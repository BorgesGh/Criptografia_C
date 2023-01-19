Projeto de criptografia em C;
Padrões de criptografia são aplicados "por palavra" na frase. Ao chegar no limite dos padrões eles se reiniciam.

Condições de Criptografia: 
#-Primeiro padrão- Caracteres especiais como "@#$" deve ser substituidos por Abd;
#-Segundo padrão- Se a quantidade de caracteres pares for superior aos impares (de acordo com a tabela ascii) deve-se colocar o sufixo "Rabbu" no final da palavra;
#-Terceiro padrão- A palavra deverá ser reescrita invertida. Se o número de letras for par, deve-se posicionar um "#" no meio da palavra;
#-Quarto padrão- As letras da palavra deverão ser trocadas em duplas. Em caso de palavra impar, a última letra não sera modificada; 
#-Quinto padrão- A palavra receberá todos os padrões de criptografia acima na sequência;

Exemplo: @mor raror felicidade pastel c@miseta
deverá se tornar: 
Abdmor rarorRabbu edadi#cilef aptsle tase#idmAbc
1°       2°         3°          4°        5°

Por fim o programa deverá devolver a frase descriptografada com base na criptografia criada pelo mesmo.

