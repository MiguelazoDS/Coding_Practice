{-# OPTIONS_GHC -Wall #-}

bigSum :: [String] -> Int 
bigSum xs = sum (map read xs :: [Int])

input :: String
input = "5\n1000000001 1000000002 1000000003 1000000004 1000000005\n"

main :: IO ()
main = interact $ show . bigSum . tail . words
