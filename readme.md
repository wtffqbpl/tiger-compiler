## Tiger Compiler.

This is a repo for tiger compiler.

## Statement

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



