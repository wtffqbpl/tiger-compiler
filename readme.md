# Tiger Compiler.
This is a repo for tiger compiler.

# The Differences

* Change c-language to c++ language.

# Statement

| Statement | Struct |
| --- | --- |
| Stm -> Stm; Stm| CompoundStm |
| Stm -> id := Exp | AssignStm |
| Stm -> print(ExpList) | PrintStm |
| Exp -> id | IdExp |
| Exp -> num | NumExp |
| Exp -> Exp Binop Exp | OpExp |
| Exp -> (Stm, Exp) | EseqExp |
| ExpList -> Exp, ExpList | PairExpList |
| ExpList -> Exp | LastExpList |
| Binop -> + | Plus |
| Binop -> - | Minus |
| Binop -> x | Times |
| Binop -> / | Div |



# References
- [CS143-Compiler Design](https://www.bilibili.com/video/BV17K4y147Bz)