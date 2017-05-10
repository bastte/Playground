module RPNCalculatorSpec where

import Test.Hspec
import RPNCalculator

spec :: Spec
spec = 
    describe "RPN Calculator" $ do
        context "with 1 2 + 3 *" $
            it "shouldbe 9" $
                rpn "1 2 + 3 *" `shouldBe` 9

main :: IO ()
main = hspec spec