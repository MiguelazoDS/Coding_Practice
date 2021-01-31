{-# OPTIONS_GHC -Wall #-}

result :: [String] -> String
result xs 
    | a < c && d > b = "NO"
    | d - b == 0 = "NO"
    | calculus == 0 = "YES" 
    | otherwise  = "NO"
    where [a,b,c,d] = map read xs :: [Int] 
          calculus = abs(a - c) `mod` abs(d - b)

main :: IO ()
main = interact $ result . words
