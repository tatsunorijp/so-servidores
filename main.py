# importing the requests library 
import requests 
  
def proxy_request(PARAMS):
  r1 = requests.get("http://127.0.0.1:12913/livros", params = PARAMS)
  r2 = requests.get("http://127.0.0.1:12914/livros", params = PARAMS)
  r3 = requests.get("http://127.0.0.1:12915/livros", params = PARAMS)
  if r1.status_code == 200:
    print("\nSERVER1")
    print(r1.text)
  elif r2.status_code == 200:
    print("\nSERVER2")
    print(r2.text)
  elif r3.status_code == 200:
    print("\nSERVER3")
    print(r3.text)
  else:
    print("Nenhum livro encontrado com esse isbn")



# api-endpoint 
URL = "http://127.0.0.1:12913/livros"

print("\nOLÁ BEM VINDO À BIBLIOTECA ONLINE")

while True:
  print("\nPesquise um livro na nossa base de dados:")
  isbn = int(input("\nIsbn: "))
    
  # defining a params dict for the parameters to be sent to the API 
  PARAMS = {'isbn': isbn} 
    
  # sending get request and saving the response as response object 
  proxy_request(PARAMS)

  c = input("\nDeseja continuar? (s/n)")
  if c == 's':
    continuar = True
  elif c == 'n':
    continuar = False

  if(not continuar):
    break
