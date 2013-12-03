import Text.Printf

getfun :: Float -> Float -> Float
getfun_h :: Float -> Float -> Float
fact :: Float -> Float 

fact n 
	| n<=0 = 1
	| otherwise = n*fact (n-1)

getfun_h x n = (x**n)/(fact n)

getfun x n 
	| n<=0 = 1
	| otherwise = (getfun_h x n) + (getfun x (n-1))

print_numbers n 
	| n>0 = do
		inputjar <- getLine
		let k = read inputjar :: Float
		printf "%.4f\n" (getfun k 9)
		print_numbers (n-1)
	| otherwise = return()


main = do
	inputjar <- getLine
	let n = read inputjar :: Float
		in print_numbers n