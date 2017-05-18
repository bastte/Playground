module NQueens (solve, printSolution) where

-- Since there will be one queen per row, we simply return the columns of those queens
-- The index in the result list is the row of the queen
-- (0,0) is the top-left corner
type Queen =  Int
type Solution = [Queen]
type BoardSize = Int
type RemainingQueensCount = Int

solve :: BoardSize -> [Solution]
solve n = solveAux n n

solveAux :: BoardSize -> RemainingQueensCount -> [Solution]
solveAux _ 0 = [[]]
solveAux n k = 
    concatMap (addOneQueen n) subSolution
    where
        subSolution = solveAux n (k-1)

-- Take an existing solution that hasn't placed all the queens,
-- and generates all the valid solution that have one more queen
addOneQueen :: BoardSize -> Solution -> [Solution]
addOneQueen n s = filter isValidSolution $ map (: s) [0..n-1]

isValidSolution :: Solution -> Bool
isValidSolution [] = True  
isValidSolution (q:qs) = 
    all (\ queenPosition @ (c, _) -> c /= q && queenPosition `notDiag` (q, qRow)) $ zip qs [qRow - 1, qRow - 2..0]
    -- since we're pushing our new queen at the beginning of the list the last element is row 0
    where 
        qRow = length qs
        (c1, r1) `notDiag` (c2, r2) = abs (r2-r1) /= abs (c2-c1)

printSolution :: Solution -> IO ()
printSolution s = mapM_ (putStrLn . row) s
    where row q = concatMap (\ x -> if x == q then "#" else ".") [0 .. length s - 1]
