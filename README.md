# Stable Matching Algorithm

## Overview  
This project implements the Gale-Shapley Stable Matching Algorithm in C++. The algorithm finds a stable pairing between men and women based on their preferences. It should be noted that the matching output is man optimal (assuming men is the group proposing). 

## How It Works
1. Each man proposes to his most preferred woman who he hasn't been rejected by.
2. A woman accepts a proposal if she is either single or prefers the new proposer over her current engagement.
3. This process repeats until everyone is matched in a stable manner.

## How to run the code
### 1. Build the project  
Build:  
```sh
make build
```

### 2. Execute the program  
Run:  
```sh
make run
```

### 3. Expected Output  
The program prints the stable matches in the format:  
```
[Woman's Name] ---<3--- [Man's Name]
```

## Notes  
- Ensure `names.txt`, `preferences_m.txt`, and `preferences_w.txt` exist in the correct format. The sample input files can be observed for reference.
- This implementation assumes that preference lists are **complete** and **correctly formatted**.
