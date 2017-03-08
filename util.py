#coding=utf-8
import os
import codecs

#insert line, before line"//XXXX"
class Insert_line(object):
	def __init__(self, file, keyword, newline):  
		self.__file = file  
		self.__key = keyword  
		self.__newline = newline  
	
	def _get_specify_lineno(self):  
		i = 1  
		try:  
			f = open("%s" % self.__file)  
		except IOError,e:  
			print e[1] + ' "%s"' % e.filename  
			sys.exit(1)  
		while True:  
			line = f.readline()  
			if not line: break  
			if "%s" % self.__key in line:  
				return i  
				break  
			i += 1  
		f.close()  
	
	def _inserted_newline_list(self):
		ls = os.linesep  
		f = open("%s" % self.__file)  
		li = f.readlines()  
		f.close()  
		li.insert(self._get_specify_lineno() - 1, self.__newline + ls )  
		return li  

	def inserted_new_file(self):
		if len(self.__newline) == 0:
			return
			
		lines = self._inserted_newline_list()  
		#os.system("cp %s %s.bak" % (self.__file, self.__file))  
		f = open("%s" % self.__file, 'w')  
		f.writelines(lines)  
		f.close()
		
#get word, between star_str and end
def txt_wrap_by(start_str, end, src_str):
	start = src_str.find(start_str)
	if start >= 0:
		start += len(start_str)
		end = src_str.rfind(end, start)

	if end >= 0:
		return src_str[start:end].strip()
		
def load_base_struct(file_):
	base_struct = []
	f_struct = open(file_)
	list_ = f_struct.readlines()
	for one_ in list_:
		if "struct " in one_:
			base_struct.append(one_)
	f_struct.close()
	return base_struct

def InitFile(path , file_ ,str_):
	#f = open(path+file_, 'w')
	f = codecs.open(path+file_, "w", "utf-8-sig")
	f.write(str_)
	f.close()
	
def Add2File(path , file_ , str_):	
	f = open(path+file_, 'ab')
	f.write(str_)
	f.close()
