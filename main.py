import pycuckoo

# Crea una nuova istanza di CuckooHashMap
table = pycuckoo.CuckooHashMap()

# Inserisci alcuni elementi
table.insert(b"chiave1", "valore1")
table.insert(b"chiave2", "valore2")
table.insert(b"chiave3", "valore3")

# Trova un elemento
valore = table.find(b"chiave1")
if valore:
    print(f"Valore trovato per 'chiave1': {valore}")
else:
    print("Chiave 'chiave1' non trovata")

# Rimuovi un elemento
key =  b"chiave2"
val = table.remove(key)
print(f"Elemento rimosso: {key}→{val}")

# Verifica che l'elemento sia stato rimosso
valore = table.find(b"chiave2")
if valore:
    print(f"Valore trovato per 'chiave2': {valore}")
else:
    print("Chiave 'chiave2' non trovata")

# Itera su tutte le chiavi
print("Chiavi nella tabella:")
for chiave in table.keys():
    print(chiave)