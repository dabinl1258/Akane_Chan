num_odd n = div n 2 + mod n 2

num_even n = div n 2

str2int s = read s :: Integer

str2nk str = map str2int $ words str

kisodd n k = num_odd n >= k

solve n k
  | kisodd n k = k * 2 - 1
  | otherwise = 2 * (k - num_odd n)
solve n = 1

main = do
  str <- getLine
  let nk = str2nk str
  let n = head nk
  let k = last nk
  print $ solve n k
