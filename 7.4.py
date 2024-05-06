pip install pyyaml
import yaml

def ler_arquivo_yaml(nome_arquivo):
    with open(nome_arquivo, 'r') as arquivo:
        try:
            dados = yaml.safe_load(arquivo)
            return dados
        except yaml.YAMLError as exc:
            print("Erro ao carregar o arquivo YAML:", exc)
            return None

if __name__ == "__main__":
    nome_arquivo_yaml = "exemplo.yaml"
    dados_yaml = ler_arquivo_yaml(nome_arquivo_yaml)
    if dados_yaml:
        print("Dados estruturados convertidos para estruturas de dados Python:")
        print(dados_yaml)
