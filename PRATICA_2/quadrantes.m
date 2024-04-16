function quadrantes()
    % Definições das variáveis da tela, de resolução 1920x1080p
    quadrante_altura = 540;
    quadrante_comprimento = 960;
    quit = false;

    while ~quit
        cursorPos = get(0, 'PointerLocation');
		
		% Calculo que retorna 1,2,3 ou 0 para o switch case
        switch (cursorPos(1) < quadrante_comprimento) + 2 * (cursorPos(2) >= quadrante_altura)
            case 0
                disp('Quadrante D');    
            case 1
                disp('Quadrante C');
            case 2
                disp('Quadrante B');
            case 3
                disp('Quadrante A');
        end

        figure (1)
        
        tic
        while toc<0.01
            
            ch = get(gcf, 'CurrentCharacter');
        end
        
        if (ch == 'c')
            break

        end
    end
end
