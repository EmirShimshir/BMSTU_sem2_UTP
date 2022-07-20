class Graph:
	
	row_count = 21
	sizes = [1] + [i for i in range(5, 101, 5)]

	def __init__(self, prog, opt):
		self.prog = prog
		self.opt = opt
		self.rows = []
		self.init_rows()
		self.write_rows()

	def init_rows(self):
		for i in Graph.sizes:
			with open("../dataset/"+self.prog+"/"+self.opt+"/"+str(i)+".txt", "r") as f:
				data = [float(row.strip()) for row in f]
			data.sort()
			average = sum(data) / len(data)
			self.rows.append([i, average])

	def write_rows(self):
		with open("../dataset/prep_data/"+self.prog+"_"+self.opt+".txt", "w") as f:
			for i in range(Graph.row_count):
				f.write(" ".join(map(str, self.rows[i])) + "\n")
			
progs = ["transpose_no", "transpose_first", "transpose_second"]
opts = ["O0", "O1", "O2", "O3", "Os"]

for prog in progs:
	for opt in opts:
		Graph(prog, opt)

print("make_preproc.py complite!")
