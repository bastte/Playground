module Sierpinski where

import Data.List

type Iteration = Int
type Length = Int
type Height = Int
type TriangleDimensions = (Length, Height)
type Column = Int
type Row = Int
type Position = (Row, Column)
-- A description of a sierpinsky iteration is simply the dimensions of a base triangle
-- and the position of the top point of all triangles
type Sierpinski = (TriangleDimensions, [Position])

totalLength :: Int
totalLength = 63
totalHeight :: Int
totalHeight = 32

computeTriangleDimensions :: Iteration -> TriangleDimensions
computeTriangleDimensions 0 = (totalLength, totalHeight)
computeTriangleDimensions n = (previousLength `quot` 2, (previousHeight - 1) `quot` 2)
    where (previousLength, previousHeight) = computeTriangleDimensions (n-1)

-- Returns true if the point is contained in the triangle
isInTriangle :: Position -> TriangleDimensions -> Position -> Bool
isInTriangle (r, c) (_, h) (tR, tC) = tR <= r && r < tR + h && tC - (r - tR) <= c && c <= tC + (r - tR)

-- Returns true if the point is contained in the fractal
isInFractal :: Sierpinski -> Position -> Bool
isInFractal (dim, triangles) p = any (isInTriangle p dim) triangles

displayPoint :: Sierpinski -> Position -> String
displayPoint s p = 
    if isInFractal s p
    then "1"
    else "_" 

-- Recursively computes the sierpinski fractal for the given iteration
computeSierpinski :: Iteration -> Sierpinski
computeSierpinski 0 = ((totalLength, totalHeight), [(0, (totalLength - 1) `quot` 2)])
computeSierpinski n = ((l, h), triangles)
    where 
        ((lRec, hRec), trianglesRec) = computeSierpinski (n-1)
        l = (lRec - 1) `quot` 2
        h = hRec `quot` 2
        triangles = concatMap (\(r,c) -> [(r + h, c - h), (r,c), (r + h, c + h)]) trianglesRec

print :: IO ()
print = do
    input <- getLine
    let iteration = read input :: Int
        sierpinski = computeSierpinski iteration in
        mapM_ (putStrLn . intercalate "" . map (displayPoint sierpinski)) [[(r,c) | c <- [0..totalLength - 1]] | r <- [0..totalHeight - 1]]