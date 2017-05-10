module RPNCalculator (rpn) where

rpn :: String -> Int
rpn = head . eval . tokenize . words
    where 
        tokenize = map parseToken
        eval = foldl (flip ($)) []

-- Performs an action on the evaluation stack depending on the current token
type TokenAction = [Int] -> [Int]

parseToken :: String -> TokenAction
parseToken token = case token of
    "+" -> binaryStackOperation (+)
    "-" -> binaryStackOperation (-)
    "*" -> binaryStackOperation (*)
    "/" -> binaryStackOperation div
    _   -> (:) (read token)
    where binaryStackOperation f (x1:x2:xs) = f x1 x2 : xs