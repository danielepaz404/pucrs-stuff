/* DanielePaz_Logico: */

CREATE TABLE Carro (
    Codigo VARCHAR(20) PRIMARY KEY,
    Placa VARCHAR(7),
    Marca VARCHAR(20),
    Ano SMALLINT,
    Nome_Motorista VARCHAR(100),
    UNIQUE (Codigo, Placa)
);

CREATE TABLE Passageiro (
    CPF VARCHAR(11) PRIMARY KEY,
    Nome VARCHAR(100),
    Email VARCHAR(100),
    Telefone VARCHAR(11),
    Bairro VARCHAR(100),
    Meio_Pagamento VARCHAR(20),
    UNIQUE (Email, Telefone)
);

CREATE TABLE Viagem (
    Id VARCHAR(20) PRIMARY KEY,
    Kms DECIMAL(5,2),
    Valor DECIMAL(5,2),
    Duracao DECIMAL(5, 2)
);

CREATE TABLE Urbana (
    Bairro_Partida VARCHAR(20),
    fk_Viagem_Id VARCHAR(20) PRIMARY KEY
);

CREATE TABLE Interurbana (
    Taxa_Adicional DECIMAL,
    Cidade_Destino VARCHAR(50),
    fk_Viagem_Id VARCHAR(20) PRIMARY KEY
);

CREATE TABLE Faz (
    fk_Carro_Codigo VARCHAR(20),
    fk_Viagem_Id VARCHAR(20)
);

CREATE TABLE Usa (
    fk_Passageiro_CPF VARCHAR(11) NOT NULL,
    fk_Viagem_Id VARCHAR(20) NOT NULL
);
 
ALTER TABLE Urbana ADD CONSTRAINT FK_Urbana_2
    FOREIGN KEY (fk_Viagem_Id)
    REFERENCES Viagem (Id)
    ON DELETE CASCADE;
 
ALTER TABLE Interurbana ADD CONSTRAINT FK_Interurbana_2
    FOREIGN KEY (fk_Viagem_Id)
    REFERENCES Viagem (Id)
    ON DELETE CASCADE;
 
ALTER TABLE Faz ADD CONSTRAINT FK_Faz_1
    FOREIGN KEY (fk_Carro_Codigo)
    REFERENCES Carro (Codigo);
 
ALTER TABLE Faz ADD CONSTRAINT FK_Faz_2
    FOREIGN KEY (fk_Viagem_Id)
    REFERENCES Viagem (Id)
    ON DELETE SET NULL;
 
ALTER TABLE Usa ADD CONSTRAINT FK_Usa_1
    FOREIGN KEY (fk_Passageiro_CPF)
    REFERENCES Passageiro (CPF);
 
ALTER TABLE Usa ADD CONSTRAINT FK_Usa_2
    FOREIGN KEY (fk_Viagem_Id)
    REFERENCES Viagem (Id)
    ON DELETE SET NULL;