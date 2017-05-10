module RPNCalculatorSpec where

import Test.Hspec
import RPNCalculator

spec :: Spec
spec = 
    describe "RPN Calculator" $ do
        context "with 1 2 + 3 * 17 -" $
            it "shouldbe 8" $
                rpn "1 2 + 3 * 17 -" `shouldBe` 8

main :: IO ()
main = hspec spec