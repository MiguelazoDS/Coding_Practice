{-# OPTIONS_GHC -Wall #-}

import Data.Map

result :: [String] -> Int 
result xs = result' ks hs
    where hs = fromListWith (+) $ zip xs (repeat 1)
          ks = keys hs
          result' [] _ = 0
          result' (y:ys) hs' = (hs' ! y) `div` 2 + result' ys hs'

main :: IO ()
main = interact $ show . result . tail . words
