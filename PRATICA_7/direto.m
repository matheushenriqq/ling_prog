filename = 'test_file.txt';  % Nome do arquivo a ser lido

% Abrir o arquivo para leitura
fileID = fopen(filename, 'r');

% Verificar se o arquivo foi aberto com sucesso
if fileID == -1
    error('Erro ao abrir o arquivo.');
end

% Ler e imprimir cada caractere do arquivo
while ~feof(fileID)
    character = fscanf(fileID, '%c', 1);
    fprintf('%c\n', character);
end

% Fechar o arquivo
fclose(fileID);
