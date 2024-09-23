//****************************************************************************************************************************/ 

//                      Projeto ACADEMIA V2

//  Version             : 2.0 

//  Utilidades         : Cadastrar/excluir/listar/alterar Cliente Rotina e Personal

//  Autor               : Bruno Lacerra - Diogo Loureiro

//  descrição           : Software para gerenciamento de uma academia utilizando arquivos txt com escrita e leitura binaria

//  data                : 15/04/2024. 

// 

//****************************************************************************************************************************/ 
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>

using namespace std;

char treinoPeito[10][100] = {"Supino Inclinado com Barra", "Supino Reto", "Hammer ou Articulado", "Supino com Halteres", "Crucifixo no Aparelho", "Crucifixo Reto com Halteres", "Cross Over (Para Peitoral Inferior)", "Cross Over com Polia Baixa", "Supino Fechado", "Supino Reto Com Barra"};
char treinoTriceps[10][100] = {"Extensao de Triceps com Barra", "Pulldown na Maquina", "Triceps Testa com Halteres", "Triceps Coice", "Mergulhos em Paralelas", "Extensao de Triceps com Corda", "Triceps na Polia Alta", "Triceps no Banco", "Flexao de Bracos Diamante", "Triceps Kickback"};
char treinoCosta[10][100] = {"Levantamento Terra", "Puxada na Frente", "Remada Curvada", "Pull-Up", "Maquina de Pulldown", "Remada Unilateral", "Hiperextensao", "Puxada Alta", "Puxada Baixa", "Barra Fixa"};
char treinoBiceps[10][100] = {"Rosca Direta", "Martelo", "21s", "Rosca Concentrada", "Rosca Scott", "Rosca Inversa", "Rosca 21", "Rosca Alternada", "Rosca com Barra Z", "Rosca 21s Invertida"};
char treinoOmbro[10][100] = {"Desenvolvimento Militar", "Elevacao Lateral", "Elevacao Frontal", "Elevacao Posterior", "Press Arnold", "Remada Alta", "Encolhimento de Ombros", "Elevacao Frontal com Halteres", "Elevacao Lateral com Halteres", "Elevacao com Cabo"};
char treinoAntebraco[10][100] = {"Rosca de Punho com Barra", "Rosca de Punho com Halteres", "Flexao de Punho com Barra", "Flexao de Punho com Halteres", "Rosca Invertida com Barra", "Rosca Invertida com Halteres", "Rosca de Punho com Corda", "Pronacao de Punho", "Supinacao de Punho", "Extensao de Punho"};
char treinoPerna[10][100] = {"Agachamento Livre", "Leg Press", "Cadeira Extensora", "Levantamento Terra", "Cadeira Flexora", "Avanco com Barra", "Agachamento Smith", "Agachamento Bulgaro", "Prensa 45 Graus", "Agachamento Livre"};
char semana[5][50] = {"Segunda Feira", "Terca Feira", "Quarta Feira", "Quinta Feira", "Sexta Feira"};
char treinos[8][20] = {"Peito", "Triceps", "Costa", "Biceps", "Ombro", "Antebraco", "Perna", "Nenhum"};

struct data{
        int dia;
        int mes;
        int ano;
};
typedef data data;
struct endereco{
    int numero;
    char rua[50];
    char bairro[50];
    char cidade[50];
    char uf[3];
};
typedef endereco endereco;
struct cliente{
    char cpf[20];
    char nome[100];
    float peso;
    float altura;
    int idade;
    char sexo;
    float precoMens;
    bool rotina;
    data dtIncricao;
    endereco enderecoCliente;
    bool desconto;
};
typedef cliente cliente;
struct personal{
    char cpf[20];
    char nome[100];
    endereco enderecoPersonal;
    char treinos[15][20];
    int qtdTreinos;
};
typedef personal personal;
struct rotina{
    char cpfCliente[20];
    char cpfPersonal[20];
    int segunda[6];
    int terca[6];
    int quarta[6];
    int quinta[6];
    int sexta[6];
    int ordem[5][2];
};
typedef rotina rotina;

void carregaArq(int qtdCliente, cliente cl[],int qtdPersonal, personal ps[], rotina rt[], int qtdRotina){
    FILE *bancoCliente;
    bancoCliente = fopen("..//arquivos//bancoCliente.txt","wb");
    if(bancoCliente==NULL){
        printf("Erro em abrir o arquivo!\n");
    }else{
        for(int i=0;i<qtdCliente;i++){
            fwrite(&cl[i],sizeof(cl[i]),1,bancoCliente);

        }
    }
    fclose(bancoCliente);

    FILE *bancoPersonal;
    bancoPersonal = fopen("..//arquivos//bancoPersonal.txt","wb");
    if(bancoPersonal==NULL){
        printf("Erro em abrir o arquivo!\n");
    }else{
        for(int i=0;i<qtdPersonal;i++){
            fwrite(&ps[i],sizeof(ps[i]),1,bancoPersonal);
        }
    }
    fclose(bancoPersonal);

    FILE *bancoRotina;
    bancoRotina = fopen("..//arquivos//bancoRotina.txt", "wb");
    if(bancoRotina==NULL){
        cout << "Erro em abrir o arquivo!" << endl;
    }else{
        for(int i=0; i<qtdRotina; i++){
            fwrite(&rt[i],sizeof(rt[i]),1,bancoRotina);
        }
    }
    fclose(bancoRotina);
}
void carregaVet(int *qntCliente,cliente cl[],int *qtdPersonal, personal ps[], int *qtdRotina, rotina rt[]){
    FILE *bancoCliente;
    FILE *bancoPersonal;
    FILE *bancoRotina;

    bancoCliente = fopen("..//arquivos//bancoCliente.txt","rb");
     if (bancoCliente == NULL){
        printf("Erro 001");
    }else{
        while(fread(&cl[*qntCliente],sizeof(cliente),1,bancoCliente)==1){
        (*qntCliente)++;
        }
    }
    fclose(bancoCliente);

    bancoPersonal = fopen("..//arquivos//bancoPersonal.txt","rb");
     if (bancoPersonal == NULL){
        printf("Erro 001");
    }else{
        while(fread(&ps[*qtdPersonal],sizeof(personal),1,bancoPersonal)==1){
        (*qtdPersonal)++;
        }
    }
    fclose(bancoPersonal);

    bancoRotina = fopen("..//arquivos//bancoRotina.txt", "rb");
    if(bancoRotina==NULL){
        cout << "Erro 001";
    }else{
        while(fread(&rt[*qtdRotina],sizeof(rotina), 1, bancoRotina)==1){
            (*qtdRotina)++;
        }
    }
    fclose(bancoRotina);
}
void errorMessage(){
    system("cls");
    cout << "OPCAO INVALIDA! Pressione qualquer tecla para retornar...";
    getch();
}


bool checaCPF(char cpf[], int qtd, cliente usCh[]){
    int nA=0;
    if(cpf[3]!='.' || cpf[7]!='.' || cpf[11]!='-'){
        cout << "CPF errado! Tente novamente (xxx.xxx.xxx-xx)" << endl;
        nA++;
    }else{
        for(int i=0; i<qtd; i++){
            if(strcmp(cpf, usCh[i].cpf)==0){
                cout << "CPF ja cadastrado! Tente novamente ou cheque se esse usuario ja possui cadastro" << endl;
                nA++;
            }
        }
    }
    if(nA>0){
        return false;
    }else{
        return true;
    }
}
bool checaCPFP(char cpf[], int qtd, personal usCh[]){
    int nA=0;
    if(cpf[3]!='.' || cpf[7]!='.' || cpf[11]!='-'){
        cout << "CPF errado! Tente novamente (xxx.xxx.xxx-xx)" << endl;
        nA++;
    }else{
        for(int i=0; i<qtd; i++){
            if(strcmp(cpf, usCh[i].cpf)==0){
                cout << "CPF ja cadastrado! Tente novamente ou cheque se esse usuario ja possui cadastro" << endl;
                nA++;
            }
        }
    }
    if(nA>0){
        return false;
    }else{
        return true;
    }
}


cliente cadastrarCliente(cliente clCh[], int qtdCliente){
    cliente cl;
    system("cls");
    cout << "-->CADASTRAR CLIENTE<--\n\n" << endl;
    do{
        cout << "Digite o CPF do cliente (CUIDADO! Ele nao podera ser alterado futuramente): ";
        fflush(stdin);
        gets(cl.cpf);
    }while(checaCPF(cl.cpf,qtdCliente, clCh)==false);
    cout << "Digite o nome do cliente: ";
    fflush(stdin);
    gets(cl.nome);
    cout << "Digite o peso da cliente: ";
    cin >> cl.peso;
    cout << "Digite a altura do cliente: ";
    cin >> cl.altura;
    cout << "Digite a idade do cliente: ";
    cin >> cl.idade;
    do{
        cout << "Digite o sexo do cliente, sendo:" << endl << "M-Masculino\nF-Feminino" << endl << "OPCAO: ";
        cin >> cl.sexo;
        if(cl.sexo != 'M' && cl.sexo != 'F'){
            cout << "Sexo Invalido. Tente novamente" << endl;
        }
    }while(cl.sexo != 'M' && cl.sexo != 'F');
    cout << "Digite o preco da mensalidade: ";
    cin >> cl.precoMens;
    cl.rotina=false;
    cout << "Data de inscricao (dd/mm/aaaa): ";
    scanf("%d/%d/%d", &cl.dtIncricao.dia, &cl.dtIncricao.mes, &cl.dtIncricao.ano);
    cout << endl << "ENDERECO" << endl;
    cout << "Rua: ";
    fflush(stdin);
    gets(cl.enderecoCliente.rua);
    cout << "Numero: ";
    cin >> cl.enderecoCliente.numero;
    cout << "Bairro: ";
    fflush(stdin);
    gets(cl.enderecoCliente.bairro);
    cout << "Cidade: ";
    fflush(stdin);
    gets(cl.enderecoCliente.cidade);
    cout << "Estado (UF): ";
    fflush(stdin);
    gets(cl.enderecoCliente.uf);
    cl.desconto=false;
    cout << endl << endl << "CLIENTE CADASTRADO COM SUCESSO!" << endl; 
    return cl;
}
void calcularDesconto(cliente cl[], int qtdCliente){
    for(int i=0; i<qtdCliente-1; i++){
        if(strcmp(cl[i].enderecoCliente.rua,cl[qtdCliente-1].enderecoCliente.rua)==0){
            if(cl[i].enderecoCliente.numero==cl[qtdCliente-1].enderecoCliente.numero){
                if(strcmp(cl[i].enderecoCliente.bairro,cl[qtdCliente-1].enderecoCliente.bairro)==0){
                    if(strcmp(cl[i].enderecoCliente.cidade,cl[qtdCliente-1].enderecoCliente.cidade)==0){
                        if(strcmp(cl[i].enderecoCliente.uf,cl[qtdCliente-1].enderecoCliente.uf)==0){
                            if(cl[i].desconto==false){
                                cout << "Cliente cadastrado possui o mesmo endereco que: " << cl[i].nome << " (tambem recebe desconto de 10%)" << endl;
                                cl[i].precoMens -= cl[i].precoMens*0.1;
                                cl[qtdCliente-1].precoMens -= cl[qtdCliente-1].precoMens*0.1;
                                cl[i].desconto = true;
                                cl[qtdCliente-1].desconto = true;
                                cout << "Novo salario de " << cl[i].nome << ": R$" << cl[i].precoMens << endl;
                                cout << "Novo salario de " << cl[qtdCliente-1].nome << ": R$" << cl[qtdCliente-1].precoMens << endl;
                            }else{
                                if(cl[qtdCliente-1].desconto==true){
                                    cout << "Cliente cadastrado possui o mesmo endereco que: " << cl[i].nome << " (cliente ja possui desconto de 10%)" << endl;
                                    cout << "Cliente " << cl[qtdCliente-1].nome << " tambem ja recebeu desconto" << endl;
                                }else{
                                    cout << "Cliente cadastrado possui o mesmo endereco que: " << cl[i].nome << " (cliente ja possui desconto de 10%)" << endl;
                                    cl[qtdCliente-1].precoMens -= cl[qtdCliente-1].precoMens*0.1;
                                    cl[qtdCliente-1].desconto = true;
                                    cout << "Novo salario de " << cl[qtdCliente-1].nome << ": R$" << cl[qtdCliente-1].precoMens << endl;
                                }
                            }   
                        }
                    }
                }
            }
        }
    }
    getch();
}
void listarCliente(cliente cl[], int iC, int vet[]){
    if(iC>0){
        for(int i=0; i<iC; i++){
            cout << "Pessoa " << i+1 << endl;
            if(vet[0]==1){
                cout << "CPF: " << cl[i].cpf << endl;
            }
            if(vet[1]==1){
                cout << "Nome: " << cl[i].nome << endl;
            }
            if(vet[2]==1){
                cout << "Peso: " << cl[i].peso << "KG" << endl;
            }
            if(vet[3]==1){
                cout << "Altura: " << cl[i].altura << endl;
            }
            if(vet[4]==1){
                cout << "Idade: " << cl[i].idade << endl;
            }
            if(vet[5]==1){
                if(cl[i].sexo=='M'){
                    cout << "Sexo: Masculino" << endl;
                }else{
                    cout << "Sexo: Feminino" << endl;
                }
            }
            if(vet[6]==1){
                cout << "Preco da mensalidade: R$" << cl[i].precoMens << endl;
            }
            if(vet[7]==1){
                cout << "Data de inscricao: " << cl[i].dtIncricao.dia << "/" << cl[i].dtIncricao.mes << "/" << cl[i].dtIncricao.ano << endl;
            }
            if(vet[8]==1){
                cout << "Endereco: " << cl[i].enderecoCliente.rua << "," << cl[i].enderecoCliente.numero << ", " << cl[i].enderecoCliente.bairro << "." << cl[i].enderecoCliente.cidade << "-" << cl[i].enderecoCliente.uf << endl;
            }
            if(vet[9]==1){
                if(cl[i].rotina==true){
                    cout << "O cliente possui uma rotina de treino cadastrada" << endl;
                }else{
                    cout << "O cliente nao possui uma rotina de treino cadastrada" << endl;
                }
            }
            cout << endl;
        }
    }else{
        cout << "Nao ha registros disponiveis para listar!";
    }
    if(vet[10]==1){
        cout << "Pressione quaquer tecla para retornar..." << endl;
    }
    getch();
}
void excluirCliente(cliente cl[], int iEx,int *qtdCliente){
    if(cl[iEx].rotina==true){
        cout << "Cliente nao pode ser excluido pois ja existe uma rotina ligada a ele!";
        getch();
    }else{
        for(int i=iEx; i<*qtdCliente-1; i++){
            cl[i]=cl[i+1];
        }
        (*qtdCliente)--;
        cout << "Cliente excluido com sucesso! Pressione qualquer tecla para retornar...";
        getch();
    }
}
int procurarCliente(cliente cl[], int qtdCliente, char cpf[]){
    int rt=101;
    for(int i=0; i<qtdCliente; i++){
        if(strcmp(cl[i].cpf, cpf)==0){
            rt=i;
        }
    }
    return rt;
}
void alterarCliente(cliente cl[], int i){
    char nome[100]; 
    float peso=0;
    float altura=0;
    int idade=0;
    char sexo;
    float precoMens=0;
    system("cls");
    cout << "-->ALTERAR CLIENTE-CPF " << cl[i].cpf << "<--" << endl << endl;
    cout << "Nome atual: " << cl[i].nome << endl;
    cout << "Digite o novo nome (pressione ENTER se nao deseja alterar): ";
    fflush(stdin);
    gets(nome);
    if(nome[0]!='\0'){
        strcpy(cl[i].nome, nome);
    }
    cout << "Peso atual: " << cl[i].peso << endl;
    cout << "Digite o novo peso (Insira 0 se nao deseja alterar): ";
    cin >> peso;
    if(peso!=0){
        cl[i].peso=peso;
    }
    cout << "Altura Atual: " << cl[i].altura << endl;
    cout << "Digite a nova altura (Insira 0 se nao deseja alterar): ";
    cin >> altura;
    if(altura!=0){
        cl[i].altura=altura;
    }
    cout << "Idade Atual: " << cl[i].idade << endl;
    cout << "Digite a nova idade (Insira 0 se nao deseja alterar): ";
    cin >> idade;
    if(idade!=0){
        cl[i].idade=idade;
    }
    cout << "Sexo Atual: ";
    if(cl[i].sexo=='M'){
        cout << "Masculino" << endl;
    }else{
        cout << "Feminino" << endl;
    }
    do{
        cout << "Digite o novo sexo (se deseja manter basta repetir o ja existente): ";
        cin >> sexo;
        if(sexo!='M' && sexo!='F' && sexo!='\0'){
            cout << "Sexo Invalido. Tente novamente" << endl;
        }
    }while(sexo!='M' && sexo!='F' && sexo!='\0');
    cl[i].sexo=sexo;
    cout << "Preco de Mensalidade Atual: " << cl[i].precoMens << endl;
    cout << "Digite o novo preco de Mensalidade (Insira 0 se nao deseja alterar): ";
    cin >> precoMens;
    if(precoMens!=0){
        cl[i].precoMens=precoMens;
        if(cl[i].desconto==true){
        cout << endl << "Cliente possui desconto de mesmo endereco (10%) entao de R$" << cl[i].precoMens;
        cl[i].precoMens-=cl[i].precoMens*0.1;
        cout << " sua assinatura vai para R$" << cl[i].precoMens << endl;
    }
}
    
    

    cout << endl << endl << "CLIENTE ALTERADO COM SUCESSO!";
    getch();
}


personal cadastrarPersonal(personal psCh[], int qtdPersonal){
    personal ps;
    system("cls");
    cout << "-->CADASTRAR PERSONAL<--\n\n" << endl;
    do{
        cout << "Digite o CPF do personal (CUIDADO! Ele nao podera ser alterado futuramente): ";
        fflush(stdin);
        gets(ps.cpf);
    }while(checaCPFP(ps.cpf,qtdPersonal, psCh)==false);
    cout << "Digite o nome do personal: ";
    fflush(stdin);
    gets(ps.nome);
    cout << endl << "ENDERECO" << endl;
    cout << "Rua: ";
    fflush(stdin);
    gets(ps.enderecoPersonal.rua);
    cout << "Numero: ";
    cin >> ps.enderecoPersonal.numero;
    cout << "Bairro: ";
    fflush(stdin);
    gets(ps.enderecoPersonal.bairro);
    cout << "Cidade: ";
    fflush(stdin);
    gets(ps.enderecoPersonal.cidade);
    cout << "Estado (UF): ";
    fflush(stdin);
    gets(ps.enderecoPersonal.uf);
    for(int i=0; i<15; i++){
        ps.treinos[i][0]='\0';
    }
    ps.qtdTreinos=0;

    cout << endl << endl << "PERSONAL CADASTRADO COM SUCESSO!";
    getch(); 
    return ps;
}
void listarPersonal(personal ps[], int iC, int vet[]){
    if(iC>0){
        for(int i=0; i<iC; i++){
            cout << "Personal " << i+1 << endl;
            if(vet[0]==1){
                cout << "CPF: " << ps[i].cpf << endl;
            }
            if(vet[1]==1){
                cout << "Nome: " << ps[i].nome << endl;
            }
            if(vet[2]==1){
                cout << "Endereco: " << ps[i].enderecoPersonal.rua << "," << ps[i].enderecoPersonal.numero << ", " << ps[i].enderecoPersonal.bairro << "." << ps[i].enderecoPersonal.cidade << "-" << ps[i].enderecoPersonal.uf << endl;
            }
            if(vet[3]==1){
                if(ps[i].qtdTreinos!=0){
                    cout << "Cliente semanais: " << endl;
                    for(int ii=0; ii<ps[i].qtdTreinos; ii++){
                        cout << "Cliente " << ii+1 << endl;
                        cout << ps[i].treinos[ii] << endl;
                    }
                }else{
                    cout << "Personal nao possui nenhum cliente para listar" << endl;
                }
            }
            cout << endl;
        }
    }else{
        cout << "Nao ha registros disponiveis para listar!";
    }
    if(vet[9]==1){
        cout << "Pressione quaquer tecla para retornar..." << endl;
    }
    getch();
}
int procurarPersonal(personal ps[], int qtdPersonal, char cpf[]){
    int rt=101;
    for(int i=0; i<qtdPersonal; i++){
        if(strcmp(ps[i].cpf, cpf)==0){
            rt=i;
        }
    }
    return rt;
}
void excluirPersonal(personal ps[], int iEx, int *qtdPersonal){
    if(ps[iEx].qtdTreinos>0){
        cout << "Personal nao pode ser excluido pois ja existe uma rotina ligada a ele!";
        getch();
    }else{
        for(int i=iEx; i<*qtdPersonal-1; i++){
            ps[i]=ps[i+1];
        }
        (*qtdPersonal)--;
        cout << "Personal excluido com sucesso! Pressione qualquer tecla para retornar...";
        getch();
    }
}
void alterarPersonal(personal ps[], int i){
    char nome[100];
    int numero;
    char rua[50];
    char bairro[50];
    char cidade[50];
    char uf[3];
    system("cls");
    cout << "-->ALTERAR PERSONAL-CPF " << ps[i].cpf << "<--" << endl << endl;
    cout << "Nome registrado: " << ps[i].nome << endl;
    cout << "Digite o novo nome (pressione ENTER caso nao deseja alterar): " << endl;
    fflush(stdin);
    gets(nome);
    if(nome[0]!='\0'){
        strcpy(ps[i].nome, nome);
    }
    cout << "Endereco registrado: " << ps[i].enderecoPersonal.rua << "," << ps[i].enderecoPersonal.numero << ", " << ps[i].enderecoPersonal.bairro << "." << ps[i].enderecoPersonal.cidade << "-" << ps[i].enderecoPersonal.uf << endl;
    cout << "Digite o novo endereco: " << endl;
    cout << "Rua (Pressione ENTER caso nao deseja alterar): ";
    fflush(stdin);
    gets(rua);
    if(rua[0]!='\0'){
        strcpy(ps[i].enderecoPersonal.rua, rua);
    }
    cout << "Numero (Insira 0 caso nao deseja alterar): ";
    cin >> numero;
    if(numero!=0){
        ps[i].enderecoPersonal.numero=numero;
    }
    cout << "Bairro (Pressione ENTER caso nao deseja alterar): ";
    fflush(stdin);
    gets(bairro);
    if(bairro[0]!='\0'){
        strcpy(ps[i].enderecoPersonal.bairro,bairro);
    }
    cout << "Cidade (Pressione ENTER caso nao deseja alterar): ";
    fflush(stdin);
    gets(cidade);
    if(cidade[0]!='\0'){
        strcpy(ps[i].enderecoPersonal.cidade, cidade);
    }
    cout << "UF (Pressione ENTER caso nao deseja alterar): ";
    gets(uf);
    if(uf[0]!='\0'){
        strcpy(ps[i].enderecoPersonal.uf, uf);
    }

    cout << endl << endl << "PERSONAL ALTERADO COM SUCESSO!";
    fflush(stdin);
    getch();
}


void cadastrarRotina(cliente cl[], int iC, personal ps[], int vetShow[], int qtdPersonal, int *qR, rotina rt[]){
        for(int i=0; i<5; i++){
            system("cls");
            cout << "-->CADASTRAR ROTINA - ID:" << cl[iC].cpf << "<--" << endl << endl;
            cout << "Digite os treinos que deseja realizar " << semana[i] << ":" << endl;
            for(int tr=0; tr<8; tr++){
                cout << tr << "-" << treinos[tr] << endl;
            }
            cout << endl;
            cout << "OPCAO 1:";
            cin >> rt[*qR].ordem[i][0];
            cout << "OPCAO 2:";
            cin >> rt[*qR].ordem[i][1];
        }
        for(int i=0; i<5; i++){
            bool rep=false;
            for(int ii=0; ii<2; ii++){
                system("cls");
                cout << "-->CADASTRAR TREINOS - " << semana[i] << endl << endl;
                int pre=0;
                int lim=3;
                if(pre==0){
                    pre=0;
                }
                if(rep==true){
                    pre=3;
                    lim=6;
                }
                switch(rt[*qR].ordem[i][ii]){
                        case 0:
                            cout << "Selecione 3 tipos de treino para peito: " << endl;
                            for(int i3=0; i3<10; i3++){
                                cout << i3 << "- " << treinoPeito[i3] << endl;
                            }
                        break;
                        case 1:
                            cout << "Selecione 3 tipos de treino para triceps: " << endl;
                            for(int i3=0; i3<10; i3++){
                                cout << i3 << "- " << treinoTriceps[i3] << endl;
                            }
                        break;
                        case 2:
                            cout << "Selecione 3 tipos de treino para costas: " << endl;
                            for(int i3=0; i3<10; i3++){
                                cout << i3 << "- " << treinoCosta[i3] << endl;
                            }
                        break;
                        case 3:
                            cout << "Selecione 3 tipos de treino para biceps: " << endl;
                            for(int i3=0; i3<10; i3++){
                                cout << i3 << "- " << treinoBiceps[i3] << endl;
                            }
                        break;
                        case 4:
                            cout << "Selecione 3 tipos de treino para ombro: " << endl;
                            for(int i3=0; i3<10; i3++){
                                cout << i3 << "- " << treinoOmbro[i3] << endl;
                            }
                        break;
                        case 5:
                            cout << "Selecione 3 tipos de treino pra antebraco: " << endl;
                            for(int i3=0; i3<10; i3++){
                                cout << i3 << "- " << treinoAntebraco[i3] << endl;
                            }
                        break;
                        case 6:
                            cout << "Selecione 3 tipos de treino para perna: " << endl;
                            for(int i3=0; i3<10; i3++){
                                cout << i3 << "- " << treinoPerna[i3] << endl;
                            }
                        break;
                }
                if(rt[*qR].ordem[i][ii]!=7){
                    for(pre = pre; pre<lim; pre++){
                        cout << "OPCAO " << pre+1 << ":";
                        switch(i){
                            case 0:
                            fflush(stdin);
                                cin >> rt[*qR].segunda[pre];
                            break;
                            case 1:
                                cin >> rt[*qR].terca[pre];
                            break;
                            case 2:
                                cin >> rt[*qR].quarta[pre];
                            break;
                            case 3:
                                cin >> rt[*qR].quinta[pre];
                            break;
                            case 4:
                                cin >> rt[*qR].sexta[pre];
                            break;
                        }
                    }
                }
                rep=true;
            }
        }
        system("cls");
        cout << "-->CADASTRAR ROTINA - ESCOLHER PERSONAL<--" << endl << endl;
        cout << "Personais disponiveis: ";
        listarPersonal(ps, qtdPersonal, vetShow);
        char perRot[14];
        int perP=0;
        do{
            cout << "Digite o CPF do Personal que deseja cadastrar na rotina: ";
            fflush(stdin);
            gets(perRot);
            perP = procurarPersonal(ps, qtdPersonal, perRot);
            if(perP==101){
                cout << "CPF nao encontrado, tente novamente." << endl;
            }
        }while(perP==101);
        if(ps[perP].qtdTreinos<15){
            strcpy(ps[perP].treinos[ps[perP].qtdTreinos],cl[iC].cpf);
            strcpy(rt[*qR].cpfPersonal, ps[perP].cpf);
            strcpy(rt[*qR].cpfCliente, cl[iC].cpf);
            ps[perP].qtdTreinos++;
            cl[iC].rotina=true;
            (*qR)++;
            cout << "ROTINA DE TREINO CADASTRADA COM SUCESSO!" << endl;
            fflush(stdin);
            getch();
        }else{
            cout << "Personal escolhido nao possui mais treinos disponiveis. Faça o cadastro novamente com outro personal" << endl;
            fflush(stdin);
            getch();
        }
}
void consultarRotina(cliente cl[], int iC, personal ps[], rotina rt[], int qtdRotina){
    for(int i=0; i<qtdRotina; i++){
        if(strcmp(rt[i].cpfCliente, cl[iC].cpf)==0){
            system("cls");
            cout << "-->LISTAR ROTINA - CPF: " << cl[iC].cpf << "<--" << endl << endl;
            cout << "CPF: " << cl[iC].cpf << endl;
            cout << "Nome: " << cl[iC].nome << endl;
            cout << "Peso: " << cl[iC].peso << endl;
            cout << "Idade: " << cl[iC].idade << endl;
            cout << "Altura: " << cl[iC].altura << endl;
            cout << "Sexo: ";
            if(cl[iC].sexo=='M'){
                cout << "Masculino" << endl;
            }else{
                cout << "Feminino" << endl;
            }
            
            cout << endl;
            for(int ii=0; ii<5; ii++){
                cout << "Treino de " << semana[ii] << endl;
                bool rep=false;
                for(int i2=0; i2<2; i2++){
                    int min=0;
                    int lim=3;
                    if(rep==true){
                        min=3;
                        lim=6;
                    }
                    for(min=min; min<lim; min++){
                        switch(rt[i].ordem[ii][i2]){
                            case 0:
                                switch(ii){
                                    case 0:
                                        cout << min+1 << "- " << treinoPeito[rt[i].segunda[min]] << endl;
                                    break;
                                    case 1:
                                        cout << min+1 << "- " << treinoPeito[rt[i].terca[min]] << endl;
                                    break;
                                    case 2:
                                        cout << min+1 << "- " << treinoPeito[rt[i].quarta[min]] << endl;
                                    break;
                                    case 3:
                                        cout << min+1 << "- " << treinoPeito[rt[i].quinta[min]] << endl;
                                    break;
                                    case 4:
                                        cout << min+1 << "- " << treinoPeito[rt[i].sexta[min]] << endl;
                                    break;
                                }
                            break;
                            case 1:
                                switch(ii){
                                    case 0:
                                        cout << min+1 << "- " << treinoTriceps[rt[i].segunda[min]] << endl;
                                    break;
                                    case 1:
                                        cout << min+1 << "- " << treinoTriceps[rt[i].terca[min]] << endl;
                                    break;
                                    case 2:
                                        cout << min+1 << "- " << treinoTriceps[rt[i].quarta[min]] << endl;
                                    break;
                                    case 3:
                                        cout << min+1 << "- " << treinoTriceps[rt[i].quinta[min]] << endl;
                                    break;
                                    case 4:
                                        cout << min+1 << "- " << treinoTriceps[rt[i].sexta[min]] << endl;
                                    break;
                                }
                            break;
                            case 2:
                                switch(ii){
                                    case 0:
                                        cout << min+1 << "- " << treinoCosta[rt[i].segunda[min]] << endl;
                                    break;
                                    case 1:
                                        cout << min+1 << "- " << treinoCosta[rt[i].terca[min]] << endl;
                                    break;
                                    case 2:
                                        cout << min+1 << "- " << treinoCosta[rt[i].quarta[min]] << endl;
                                    break;
                                    case 3:
                                        cout << min+1 << "- " << treinoCosta[rt[i].quinta[min]] << endl;
                                    break;
                                    case 4:
                                        cout << min+1 << "- " << treinoCosta[rt[i].sexta[min]] << endl;
                                    break;
                                }
                            break;
                            case 3:
                                switch(ii){
                                    case 0:
                                        cout << min+1 << "- " << treinoBiceps[rt[i].segunda[min]] << endl;
                                    break;
                                    case 1:
                                        cout << min+1 << "- " << treinoBiceps[rt[i].terca[min]] << endl;
                                    break;
                                    case 2:
                                        cout << min+1 << "- " << treinoBiceps[rt[i].quarta[min]] << endl;
                                    break;
                                    case 3:
                                        cout << min+1 << "- " << treinoBiceps[rt[i].quinta[min]] << endl;
                                    break;
                                    case 4:
                                        cout << min+1 << "- " << treinoBiceps[rt[i].sexta[min]] << endl;
                                    break;
                                }
                            break;
                            case 4:
                                switch(ii){
                                    case 0:
                                        cout << min+1 << "- " << treinoOmbro[rt[i].segunda[min]] << endl;
                                    break;
                                    case 1:
                                        cout << min+1 << "- " << treinoOmbro[rt[i].terca[min]] << endl;
                                    break;
                                    case 2:
                                        cout << min+1 << "- " << treinoOmbro[rt[i].quarta[min]] << endl;
                                    break;
                                    case 3:
                                        cout << min+1 << "- " << treinoOmbro[rt[i].quinta[min]] << endl;
                                    break;
                                    case 4:
                                        cout << min+1 << "- " << treinoOmbro[rt[i].sexta[min]] << endl;
                                    break;
                                }
                            break;
                            case 5:
                                switch(ii){
                                    case 0:
                                        cout << min+1 << "- " << treinoAntebraco[rt[i].segunda[min]] << endl;
                                    break;
                                    case 1:
                                        cout << min+1 << "- " << treinoAntebraco[rt[i].terca[min]] << endl;
                                    break;
                                    case 2:
                                        cout << min+1 << "- " << treinoAntebraco[rt[i].quarta[min]] << endl;
                                    break;
                                    case 3:
                                        cout << min+1 << "- " << treinoAntebraco[rt[i].quinta[min]] << endl;
                                    break;
                                    case 4:
                                        cout << min+1 << "- " << treinoAntebraco[rt[i].sexta[min]] << endl;
                                    break;
                                }
                            break;
                            case 6:
                                switch(ii){
                                    case 0:
                                        cout << min+1 << "- " << treinoPerna[rt[i].segunda[min]] << endl;
                                    break;
                                    case 1:
                                        cout << min+1 << "- " << treinoPerna[rt[i].terca[min]] << endl;
                                    break;
                                    case 2:
                                        cout << min+1 << "- " << treinoPerna[rt[i].quarta[min]] << endl;
                                    break;
                                    case 3:
                                        cout << min+1 << "- " << treinoPerna[rt[i].quinta[min]] << endl;
                                    break;
                                    case 4:
                                        cout << min+1 << "- " << treinoPerna[rt[i].sexta[min]] << endl;
                                    break;
                                }
                            break;
                        }
                    }
                    cout << endl;
                    rep=true;
                }
            }
            int ii=0;
            bool fPers=false;
            while(fPers==false){
                if(strcmp(rt[i].cpfPersonal,ps[ii].cpf)==0){
                    cout << "PERSONAL: " << ps[ii].nome << endl << endl;
                    fPers=true;
                }
                ii++;
            }
            cout << "Pressione qualquer tecla para retorar ao menu..." << endl;
            fflush(stdin);
            getch();
        }
    }
}
void excluirRotina(rotina rt[],int *qtdRotina, cliente cl[], int cE, personal ps[], int qtdPersonal){
    for(int i=0; i<*qtdRotina; i++){
        if(strcmp(rt[i].cpfCliente,cl[cE].cpf)==0){
            for(int ii=i; ii<*qtdRotina-1; ii++){
                rt[ii]=rt[ii+1];
            }
        }
    }
    for(int i=0; i<qtdPersonal; i++){
        for(int ii=0; ii<ps[i].qtdTreinos; ii++){
            if(strcmp(ps[i].treinos[ii],cl[cE].cpf)==0){
                for(int i2=ii; i2<ps[i].qtdTreinos-1; i2++){
                    strcpy(ps[i].treinos[i2],ps[i].treinos[i2+1]);
                }
                ps[i].qtdTreinos--;
            }
        }
    }
    cl[cE].rotina=false;
    (*qtdRotina)--;
    cout << "ROTINA DE TREINO EXCLUIDA COM SUCESSO!" << endl;
    fflush(stdin);
    getch();
}


int main(){
    int opCliente;
    int opRotina;
    int opPersonal;
    cliente cl[100];
    personal ps[100];
    rotina rt[100];
    int qtdPersonal = 0;
    int qtdCliente = 0;
    int qtdRotina = 0;
    int vetShow[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int op;
    carregaVet(&qtdCliente,cl,&qtdPersonal,ps, &qtdRotina, rt);
    do{
        system("cls");
        cout << "-->MENU PRINCIPAL<--" << endl << endl;
        cout << "SELECIONE A OPCAO DESEJADA:" << endl;
        cout << "1-CLIENTE\n2-ROTINA DE TREINO\n3-PERSONAL\n0-Sair\nOPCAO: ";
        fflush(stdin);
        cin >> op;

        switch(op){
            case 1:
                do{
                    system("cls");
                    cout << "-->MENU CLIENTE<--" << endl;
                    cout << "SELECIONE A OPCAO DESEJADA:" << endl << endl;
                    cout << "1-Cadastrar Cliente\n2-Listar Clientes\n3-Alterar Cliente\n4-Excluir Cliente\n0-Voltar\nOPCAO: ";
                    fflush(stdin);
                    cin >> opCliente;
                    
                    switch(opCliente){
                        case 1:
                            cl[qtdCliente]=cadastrarCliente(cl, qtdCliente);
                            qtdCliente++;
                            calcularDesconto(cl, qtdCliente);
                            opCliente=0;
                        break;
                        case 2:
                            system("cls");
                            cout << "-->LISTAR CLIENTES<--" << endl << endl;
                            for(int i=0; i<11; i++){
                                vetShow[i] = 1;
                            }
                            listarCliente(cl, qtdCliente, vetShow); 
                            for(int i=0; i<11; i++){
                                vetShow[i] = 0;
                            }
                            opCliente=0;
                        break;
                        case 3:
                            char cpfAux[20];
                            system("cls");
                            cout << "-->ALTERAR CLIENTE<--" << endl << endl;
                            cout << "Clientes Disponiveis: " << endl << endl;
                            vetShow[0]=1;
                            vetShow[1]=1;
                            listarCliente(cl, qtdCliente, vetShow);
                            if(qtdCliente>0){
                                int pC=0;
                                do{
                                    cout << "Digite o CPF do cliente que deseja alterar: ";
                                    fflush(stdin);
                                    gets(cpfAux);
                                    pC = procurarCliente(cl, qtdCliente, cpfAux);
                                    if(pC==101){
                                        cout << "CPF nao encontrado, tente novamente." << endl;
                                    }else{
                                        alterarCliente(cl, pC);
                                    }
                                }while(pC==101);
                            }
                            cpfAux[0] = '\0';
                            for(int i=0; i<11; i++){
                                vetShow[i] = 0;
                            }
                            opCliente=0;
                        break;
                        case 4:
                            char cpfAux2[20];
                            system("cls");
                            cout << "-->EXCLUIR CLIENTE<--" << endl << endl;
                            cout << "Clientes Disponiveis: " << endl << endl;
                            vetShow[0]=1;
                            vetShow[1]=1;
                            listarCliente(cl, qtdCliente, vetShow);
                            if(qtdCliente>0){
                                int pC=0;
                                do{
                                    cout << "Digite o CPF do cliente que deseja alterar: ";
                                    fflush(stdin);
                                    gets(cpfAux2);
                                    pC = procurarCliente(cl, qtdCliente, cpfAux2);

                                    if(pC==101){
                                        cout << "CPF nao encontrado, tente novamente." << endl;
                                    }else{
                                        excluirCliente(cl, pC, &qtdCliente);
                                    }
                                }while(pC==101);
                            }
                            cpfAux[0] = '\0';
                            for(int i=0; i<11; i++){
                                vetShow[i] = 0;
                            }
                            opCliente=0;
                        break;
                        case 0:
                        break;
                        default:
                            errorMessage();
                        break;
                    }
                }while(opCliente!=0);
            break;
            case 2:
                do{
                    system("cls");
                    cout << "-->MENU ROTINA<--" << endl << endl;
                    cout << "Digite a opcao desejada: " << endl;
                    cout << "1-Cadastrar Rotina\n2-Consultar Rotina\n3-Excluir Rotina\n0-Sair\nOPCAO: " ;
                    cin >> opRotina;
                    if(opRotina==1){
                            char cpfAux5[20];
                            system("cls");
                            cout << "-->CADASTRAR ROTINA<--" << endl << endl;
                            cout << "Clientes Disponiveis: " << endl << endl;
                            vetShow[0]=1;
                            vetShow[1]=1;
                            listarCliente(cl, qtdCliente, vetShow);
                            if(qtdCliente>0){
                                int pR=0;
                                do{
                                    cout << "Digite o CPF do cliente que deseja alterar: ";
                                    fflush(stdin);
                                    gets(cpfAux5);
                                    pR = procurarCliente(cl, qtdCliente, cpfAux5);
                                    if(pR==101){
                                        cout << "CPF nao encontrado, tente novamente." << endl;
                                    }else{
                                        if(qtdPersonal>0){
                                            if(cl[pR].rotina==false){
                                                cadastrarRotina(cl, pR, ps, vetShow, qtdPersonal, &qtdRotina, rt);
                                            }else{
                                                cout << "Cliente ja possui rotina cadastrada." << endl;
                                                fflush(stdin);
                                                getch();
                                            }
                                        }else{
                                            cout << "Nao existe nenhum personal cadastrado ou disponivel para criar uma rotina de treino!";
                                            fflush(stdin);
                                            getch();
                                        }
                                    }
                                }while(pR==101);
                            }
                            for(int i=0; i<10; i++){
                                vetShow[i]=0;
                            }
                            opRotina=0;
                    }else if(opRotina==2){

                            char cpfAux6[20];
                            system("cls");
                            cout << "-->CONSULTAR ROTINA<--" << endl << endl;
                            int rC=0;
                            for(int i=0; i<10; i++){
                                vetShow[i]=0;
                            }
                            vetShow[0]=1;
                            vetShow[1]=1;
                            listarCliente(cl, qtdCliente, vetShow);
                            do{
                                cout << "Digite o CPF do cliente que deseja consultar a rotina: ";
                                fflush(stdin);
                                gets(cpfAux6);
                                rC = procurarCliente(cl, qtdCliente, cpfAux6);
                                if(rC==101){
                                    cout << "CPF nao encontrado, tente novamente." << endl;
                                }else{
                                    if(cl[rC].rotina==false){
                                        cout << "Cliente nao possui rotina cadastrada.";
                                        fflush(stdin);
                                        getch();
                                    }else{
                                        consultarRotina(cl, rC, ps, rt, qtdRotina);
                                    }
                                }
                            }while(rC==101);
                            opRotina=0;
                    }else if(opRotina==3){
                            char cpfAux7[20];
                            system("cls");
                            cout << "-->EXCLUIR ROTINA<--" << endl << endl;
                            int rE=0;
                            for(int i=0; i<10; i++){
                                vetShow[i]=0;
                            }
                            vetShow[0]=1;
                            vetShow[1]=1;
                            listarCliente(cl,qtdCliente,vetShow);
                            do{
                                cout << "Digite o CPF do cliente que deseja excluir a rotina: ";
                                fflush(stdin);
                                gets(cpfAux7);
                                rE = procurarCliente(cl, qtdCliente, cpfAux7);
                                if(rE==101){
                                    cout << "CPF nao encontrado, tente novamente." << endl;
                                }else{
                                    if(cl[rE].rotina==false){
                                        cout << "Cliente nao possui rotina cadastrada para excluir.";
                                        fflush(stdin);
                                        getch();
                                    }else{
                                        excluirRotina(rt, &qtdRotina, cl, rE, ps, qtdPersonal);
                                    }
                                }
                            }while(rE==101);
                            getch();
                            opRotina=0;
                    }else if(opRotina==0){
                    }else{
                        errorMessage();
                    }
                }while(opRotina!=0);
            break;
            case 3:
                do{
                    system("cls");
                    cout << "-->MENU PERSONAL<--" << endl << endl;
                    cout << "Digite a opcao desejada: " << endl;
                    cout << "1-Cadastrar Personal\n2-Listar Personais\n3-Alterar Personal\n4-Excluir Personal\n0-Sair\nOPCAO: ";
                    cin >> opPersonal;

                    switch(opPersonal){
                        case 1:
                            ps[qtdPersonal]=cadastrarPersonal(ps, qtdPersonal);
                            qtdPersonal++;
                            opPersonal=0;
                        break;
                        case 2:
                            system("cls");
                            cout << "-->LISTAR PERSONAIS<--" << endl << endl;
                            for(int i=0; i<11; i++){
                                vetShow[i] = 1;
                            }
                            listarPersonal(ps, qtdPersonal, vetShow); 
                            for(int i=0; i<11; i++){
                                vetShow[i] = 0;
                            }
                            opPersonal=0;
                        break;
                        case 3:
                            char cpfAux3[20];
                            system("cls");
                            cout << "-->ALTERAR PERSONAL<--" << endl << endl;
                            cout << "Personais Disponiveis: " << endl << endl;
                            vetShow[0]=1;
                            vetShow[1]=1;
                            listarPersonal(ps, qtdPersonal, vetShow);
                            if(qtdPersonal>0){
                                int pP=0;
                                do{
                                    cout << "Digite o CPF do personal que deseja alterar: ";
                                    fflush(stdin);
                                    gets(cpfAux3);
                                    pP = procurarPersonal(ps, qtdPersonal, cpfAux3);

                                    if(pP==101){
                                        cout << "CPF nao encontrado, tente novamente." << endl;
                                    }else{
                                        alterarPersonal(ps, pP);
                                    }
                                }while(pP==101);
                            }
                            cpfAux3[0] = '\0';
                            for(int i=0; i<11; i++){
                                vetShow[i] = 11;
                            }
                            opPersonal=0;
                        break;
                        case 4:
                        char cpfAux4[20];
                            system("cls");
                            cout << "-->EXCLUIR Personal<--" << endl << endl;
                            cout << "Personais Disponiveis: " << endl << endl;
                            vetShow[0]=1;
                            vetShow[1]=1;
                            listarPersonal(ps, qtdPersonal, vetShow);
                            if(qtdPersonal>0){
                                int pEx=0;
                                do{
                                    cout << "Digite o CPF do personal que deseja excluir: ";
                                    fflush(stdin);
                                    gets(cpfAux4);
                                    pEx= procurarPersonal(ps, qtdPersonal, cpfAux4);
                                    if(pEx==101){
                                        cout << "CPF nao encontrado, tente novamente." << endl;
                                    }else{
                                        excluirPersonal(ps, pEx, &qtdPersonal);
                                    }
                                }while(pEx==101);
                            }
                            cpfAux4[0] = '\0';
                            for(int i=0; i<10; i++){
                                vetShow[i] = 10;
                            }
                            opPersonal=0;
                        break;
                        case 0:
                        break;
                        default:
                            errorMessage();
                        break;
                    }
                }while(opPersonal!=0);

            break;
            case 0:
                system("cls");
                cout << "Obrigado por usar nosso sistema, ate a proxima!" << endl << endl;
                carregaArq(qtdCliente,cl,qtdPersonal,ps, rt, qtdRotina);
            break;
            default:
                errorMessage();
            break;
        }
    }while(op!=0);
    return 0;
}