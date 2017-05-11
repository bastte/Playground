module WordsSplitter (splitWords) where

import qualified Data.Set as Set

splitWords :: String -> String
splitWords sentence 
    | success = result
    | otherwise = error "The input sentence could not be split"
    where 
        (success, result) = splitWordsAux sentence []

-- All the words in our custom language
dictionary :: Set.Set String
dictionary = Set.fromList ["apple", "pie", "pi", "app"]

-- Current word we're examining
type CurrentWord = String

splitWordsAux :: String -> CurrentWord -> (Bool, String)
splitWordsAux [] [] = (True, [])
splitWordsAux [] currentWord 
    | currentWord `Set.member` dictionary = (True, currentWord)
    | otherwise = (False, [])
splitWordsAux (x:xs) currentWord
    | currentWord `Set.member` dictionary = 
        let (success, subResult) = splitWordsAux (x:xs) [] in
            if success
            then (True, currentWord ++ " " ++ subResult) 
            else recurse
    | otherwise = recurse
    where 
        recurse = splitWordsAux xs (currentWord ++ [x])