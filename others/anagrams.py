def funWithAnagrams(s):
	#Write your code here
	d = set()
	for word in s:
		e = [0]*(ord('z')-ord('a')+1)
		for letter in word:
			e[ord('z')-ord(letter)] += 1
		d.add(e)
	return sorted(d)


funWithAnagrams(['hola', 'aloh', 'adios', 'sodiaa'])