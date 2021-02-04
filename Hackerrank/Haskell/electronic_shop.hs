{-# OPTIONS_GHC -Wall #-}

input :: String 
input = "10 2 3\n3 1\n5 2 8\n"

result :: Int -> [Int] -> [Int] -> Int
result budget keyboards usb_drives
    | null buy = -1 
    | otherwise = maximum buy
    where buy = filter (<= budget) [x+y | x<-keyboards, y<-usb_drives]


parse :: [String] -> Int
parse [] = -1
parse [_] = -1
parse (x:y:xs) = result budget keyboards usb_drives
    where budget = read x :: Int
          keyboard_list = read y :: Int 
          keyboards = map read (take keyboard_list (drop 1 xs)) :: [Int]
          usb_drives = map read (drop (keyboard_list+1) xs) :: [Int]


main :: IO ()
main = interact $ show . parse . words
