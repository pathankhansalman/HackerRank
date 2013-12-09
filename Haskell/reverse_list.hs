revl l
	| l == [] = []
	| otherwise = let (a:x) = l 
					  in (revl x) ++ a

main = do
	let n = [1..3]
		in print (revl n)