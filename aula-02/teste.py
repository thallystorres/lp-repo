class Estudante:
    def __init__(self, nome, idade: int) -> None:
        self.nome = nome
        self.idade = idade

miguel = Estudante("Miguel", 19)

print(miguel.idade)