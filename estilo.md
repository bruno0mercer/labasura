### estilo de código

Padrão adotado: **[Google C++ Style Guide](http://google.github.io/styleguide/cppguide.html)** com algumas adaptações.

Reforços:
- Blocos não-vazios: estilo [1TBS](https://en.wikipedia.org/wiki/Indent_style#Variant:_1TBS)
```cpp
// ...
if (x < 0) {
	puts("Negative");
	negative(x);
} else {
	puts("Non-negative");
	nonnegative(x);
}
```

- Diretiva *#define* para constantes (inclusive referência aos pinos)
```cpp
// ...
#define LED 13
// ...
setPin(LED, 1);
```

- Otimização no uso de variáveis
```cpp
// ...
for(int i = 0; i < 10; ++i) // errado
//...
for(uint8_t i = 0; i < 10; ++i) // correto
```



Sugestão de editores:
- [Atom](https://atom.io/)
- [Sublime Text](http://www.sublimetext.com/)
- [Vim](http://www.vim.org/)