# 2-oji užduotis: Supaprastinta blokų grandinė (blockchain)

Užduoties reikalavimus galite pamatyti [čia](https://github.com/blockchain-group/Blockchain-technologijos/blob/master/pratybos/2uzduotis-Blockchain.md).  
Norint paleisti programą, jums reikia parsisiųsti norimą versiją ir paleisti `CMakeLists.txt` programos paleidimo failą.  

## [V0.1](https://github.com/rokas28/blockchain/releases/tag/v0.1) (2019-10-19)
Tai yra pirmoji programos versija. 
### Pridėta:
- `headers` - aprašyti visos reikalingos blockchain'o klasės.
- `functions` - aprašytos visos blockchain'o klasių funkcijos.
- `CMakeLists.txt` - Programos paleidimo failas.
- `.gitignore` failas.
- `README.md` failas.

## [V0.2](https://github.com/rokas28/blockchain/releases/tag/v0.2) (2019-10-27)
### Pridėta:
- Balansų tikrinimas.
- Transakcijos hash'o tikrinimas.
- Kuriami 5 potencialūs blokai.

Fiksuotas hash'ų bandymų skaičius potencialiems blokams yra 100000. Nepavykus sukurti, einama prie kito bloko ir vėl bandoma 100000 kartų.

## [V0.3](https://github.com/rokas28/blockchain/releases/tag/v0.3) 
### Pridėta:
- Merkle tree hashavimas.