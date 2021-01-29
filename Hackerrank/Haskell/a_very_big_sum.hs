{-# OPTIONS_GHC -Wall #-}

bigSum :: [String] -> Int 
bigSum xs = sum (map read xs :: [Int])

main :: IO ()
main = interact $ show . bigSum . tail . words
