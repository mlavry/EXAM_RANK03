# Exam Rank 03 – 42 School 🔧

Ce dépôt contient les deux exercices majeurs demandés lors de l'**Exam Rank 03** de 42 :  
**`ft_printf.c`** et **`get_next_line.c`**, deux implémentations fondamentales du cursus.

Ces deux fichiers sont généralement à implémenter séparément, chacun dans une durée limitée, lors d’un examen de 2 heures.

---

## 📦 Contenu du dépôt

| Fichier            | Description                                                                 |
|--------------------|-----------------------------------------------------------------------------|
| `ft_printf.c`      | Reproduction partielle de la fonction `printf` sans utiliser la libc        |
| `get_next_line.c`  | Lecture ligne par ligne à partir d’un descripteur de fichier avec `read()`  |

---

## ✅ Objectifs pédagogiques

- Manipulation des **arguments variadiques** (`va_list`)
- Conversion et affichage formaté (`%d`, `%s`, `%x`, etc.)
- Lecture incrémentale avec `read()` et gestion de buffers
- Manipulation de chaînes, mémoire dynamique et logique binaire
- Respect strict des **contraintes 42** (libc interdite sauf `write`, `malloc`, `free`, `read`)

---
