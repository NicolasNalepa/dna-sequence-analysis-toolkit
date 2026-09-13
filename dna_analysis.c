#include "dna_analysis.h"



/*
Function: calculate_gc_content                         
Purpose: Calculates the percentage of Guanine and Cytosine in a DNA sequence.
Parameters:  dna_sequence: a NUL-terminated C string of DNA bases.
Returns: A float representing the GC content as a percentage in [0, 100].
Side effects: None.                         

*/

float calculate_gc_content(const char *dna_sequence)
{
    int gc_count = 0;     
    int total_length = 0;  
    int i = 0;             
    
  

    // Handle NULL pointer
    if (!dna_sequence ) {
        return 0.0;
    }
 

    // Loop through each character until NULL terminator
    while (dna_sequence[i] != '\0') {
       
        
        if (dna_sequence[i] == 'G' || dna_sequence[i] == 'C') {
            gc_count++;
        }
        total_length++;
        i++;
    }
    
    // Avoids division by zero
    if (total_length == 0) {
        return 0.0;
    }
    
    
   // Calculates the GC content as percentage
    return (gc_count * 100.0) / total_length;
}



/*
Function: find_motif
Purpose: Searches for the first occurrence of a motif pattern within a DNA sequence.
Parameters:
  - dna_sequence: a constant character pointer to the DNA sequence to search
  - motif: a constant character pointer to the pattern to find
Returns: The starting index of the motif, or -1 if not found or if an error occurs.
Side effects: None.
*/


int find_motif(const char *dna_sequence, const char * motif) {

    // Hande the edge cases 
    
if (!dna_sequence || !motif) {
        return -1;
        
    }

    int motif_len = 0;
    while (motif[motif_len] != '\0') {
        motif_len++;
    }    

    // handle emptey motif returns 

    if (motif_len == 0){
        return -1;

    }

    // calculate dna_sequence 

    int seq_len = 0;
    while ( dna_sequence[seq_len] != '\0'){
        seq_len++;
    }
    
    // if the motif is longer than the sequence than it cannot be found 
    
    if (motif_len > seq_len){
        return -1;

    }

    // search for the motif in the dna sequnce 

    for ( int i = 0; i <= seq_len - motif_len; i++){

        //check if the motif matches the starting position of the dna sequence 
        
        int match = 1;

    for (int j =0; j < motif_len; j++){

        if (dna_sequence[i+j] != motif[j]) {
            match =0;
            break; // stops checking this position
        }
    }

    // Returns the index if a full match is found 
    if (match) {
        return i;

         }

    }

// Motif not found
return -1;


}



/*
Function: calculate_genetic_difference              
Purpose: Calculates the Hamming distance between DNA sequences (literal char-by-char).
Parameters:
  - seq1: a constant character pointer to the first DNA sequence
  - seq2: a constant character pointer to the second DNA sequence
Returns: The number of positions where the sequences differ, or -1 if lengths differ or input is NULL.
Side effects: None.
*/


int calculate_genetic_difference(const char *seq1, const char *seq2) {


// Handle NULL pointers
if ( !seq1 || !seq2){

    return -1;
}

int len1 = 0;
while (seq1[len1] != '\0'){
    len1++;
}

int len2 = 0;
while (seq2[len2] != '\0') {
    len2++;
}

// Checks if sequences are the same length
if (len1 != len2){
    return -1;
}

int difference = 0;


// Compare characters at each position
for (int i = 0; i < len1; i++) {
    if ( seq1[i] != seq2[i]) {
        difference++;
    }
}

return difference;


}


/*
Function: is_palindrome
Purpose: Determines if a DNA sequence reads the same forward and backward (literal palindrome).
Parameters:
  - dna_sequence: a constant character pointer to the DNA sequence to check 
Returns: 1 if the sequence is a palindrome, 0 if not, -1 if error (NULL).
Side effects: none.
*/



int is_palindrome (const char *dna_sequence) {

// Handle the null poitner 

if ( !dna_sequence) {
    return -1;
}


// Calculate length of sequence
int len = 0;
while (dna_sequence[len] != '\0'){
    len++;
}

int left = 0;
int right = len -1; // ensures it reads from last character and not the NULL poitner 

while (left< right){
    if (dna_sequence[left] != dna_sequence[right]){
        return 0; // not a palidrome
    }
left++;
right--;


}

return 1; // if its a palirdrome 

}


/*
Function: are_anagrams
Purpose: Determines if two DNA sequences contain the same counts of A, C, G, and T.
Parameters: 
  - seq1: a constant character pointer to the first DNA sequence
  - seq2: a constant character pointer to the second DNA sequence
Returns: 1 if the sequences are anagrams, 0 if not (or on NULL).
Side effects: None.
*/

int are_anagrams( const char *seq1, const char *seq2){

// Handle NULL pointers
if (!seq1 || !seq2){
    return 0;
}

// Calculates lenghts        
int len = 0;
while (seq1[len] != '\0'){
    len++;
}

int len2 = 0;
while (seq2[len2] != '\0'){
    len2++;
}

// If lengths differ, cannot be anagrams
if (len2 != len) {
    return 0;
}

// frequencey arrays for A, C, D, T (this indiacted 0, 1, 2, 3)

int freq1[4] = {0, 0, 0, 0};
int freq2[4] = {0, 0, 0, 0};

//count the frequencies for sequence 1

for (int i = 0; i < len; i++) {
    if (seq1[i] == 'A'){
        freq1[0]++;
    } else if (seq1[i] == 'C'){
        freq1[1]++;
    } else if (seq1[i] == 'G') {
        freq1[2]++;
    } else if (seq1[i] == 'T') {
        freq1[3]++;
    }
}

// count the frequencies for sequence 2 

for (int i = 0; i < len2; i++){
    if (seq2[i] == 'A'){
        freq2[0]++;
    } else if (seq2[i] == 'C'){
        freq2[1]++;
    } else if ( seq2[i] == 'G'){
        freq2[2]++;
    } else if (seq2[i] == 'T'){
        freq2[3]++;
    }
}

// Compate the frequency arrays 

for (int i = 0; i < 4; i++){
    if (freq1[i] != freq2[i]){
        return 0; // not an anagram
    }
}

return 1; // if they are anagrams


}



