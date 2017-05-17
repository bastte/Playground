module HeathrowToLondon (computePath, sampleRoadBlocks) where

-- From "Learn you a Haskell for Great Good"
-- Page 208

-- Represent a road block from the exercise
-- It's composed of three distances A, B and C:
-- ---- A ----
--           |
--           C
--           |
-- ---- B ----
data RoadBlock = RoadBlock { a :: Int, b :: Int, c :: Int }
    deriving (Show)
type Roads = [RoadBlock]

-- This is the current position: we're always either at the top (on the A road)
-- or the bottom (on the B road)
data Position = Top | Bottom

-- From the exercise
sampleRoadBlocks = [ RoadBlock 50 10 30
                   , RoadBlock 5 90 20
                   , RoadBlock 40 2 25
                   , RoadBlock 10 8 0 
                   ]

-- Takes the road blocks and prints the shortest path
computePath :: Roads -> [Int]
computePath roadBlocks
    | bottomPathScore < topPathScore = shortestPathFromBottom
    | otherwise = shortestPathFromTop
    where 
        (shortestPathFromBottom, bottomPathScore) = (computePathAux Bottom roadBlocks, sum shortestPathFromBottom)
        (shortestPathFromTop, topPathScore) = (computePathAux Top roadBlocks, sum shortestPathFromTop)

computePathAux :: Position -> Roads -> [Int]
computePathAux _ [] = []
computePathAux currentPosition (RoadBlock a b c : blocks)
    | topPathScore < bottomPathScore = topPath
    | otherwise = bottomPath
    where 
        pathToTop Top = [a]
        pathToTop Bottom = [b, c]
        pathToBottom Top = [a, c]
        pathToBottom Bottom = [b]
        (topPath, topPathScore) = (pathToTop currentPosition ++ computePathAux Top blocks, sum topPath)
        (bottomPath, bottomPathScore) = (pathToBottom currentPosition ++ computePathAux Bottom blocks, sum bottomPath)