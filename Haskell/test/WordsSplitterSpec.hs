module WordsSplitterSpec where 

import Test.Hspec
import WordsSplitter

spec :: Spec
spec = 
    describe "Words Splitter" $ do
        context "with 'applepie'" $
            it "should return 'apple pie'" $
                splitWords "applepie" `shouldBe` "apple pie"

main :: IO ()
main = hspec spec