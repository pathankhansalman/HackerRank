print_fib_h k i j m
	| k==0 = print i
	| k==1 = print j
	| otherwise = do 
		let l = i
		let i = rem (l+j) m
		let l = j
		let j = rem (i+l) m
		print_fib_h (k-2) i j m



print_fib n 
	| n<=0 = return()
	|otherwise = do
		inputjar <- getLine
		let k = read inputjar :: Int
			in print_fib_h k 0 1 100000007
		print_fib (n-1)

main = do
	inputjar <- getLine
	let n = read inputjar :: Int
		in print_fib n