% Abrir o arquivo para leitura
fileID = fopen('test_file_2.txt', 'r');
if fileID == -1
    error('Error opening file');
end

% Ler e processar cada linha do arquivo
while ~feof(fileID)
    % Ler uma linha do arquivo
    line = fgetl(fileID);
    
    % Dividir a linha em tokens usando a vírgula como delimitador
    tokens = strsplit(line, ',');
    
    % Processar cada token
    for i = 1:length(tokens)
        fprintf('%s\n', tokens{i});
    end
end

% Fechar o arquivo
fclose(fileID);
