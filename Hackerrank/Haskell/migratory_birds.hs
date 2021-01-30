{-# OPTIONS_GHC -Wall #-}

import Data.Map

result :: [String] -> Int
result ys = ret
    where xs = Prelude.map read ys :: [Int]
          temp = toList $ fromListWith (+) $ zip xs $ repeat 1
          invert = fromListWith (++) $ Prelude.map (\x -> (snd x, [fst x])) temp
          ret = minimum $ invert ! maximum  (keys invert)

main :: IO ()
main = interact $ show . result . tail . words
