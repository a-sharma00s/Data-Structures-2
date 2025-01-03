/*
 * your program signature
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#include "mysort.h"

#define MAX_REC 100
int compareScores(const void *a, const void *b) {
    const RECORD *recA = (const RECORD *)a;
    const RECORD *recB = (const RECORD *)b;
    return (recA->score > recB->score) - (recA->score < recB->score);
}

GRADE grade(float score)
{
    GRADE r = {"F"};
    // your code
    if (score >= 90) strcpy(r.letter_grade, "A+");
    else if (score >= 85) strcpy(r.letter_grade, "A");
    else if (score >= 80) strcpy(r.letter_grade, "A-");
    else if (score >= 77) strcpy(r.letter_grade, "B+");
    else if (score >= 73) strcpy(r.letter_grade, "B");
    else if (score >= 70) strcpy(r.letter_grade, "B-");
    else if (score >= 67) strcpy(r.letter_grade, "C+");
    else if (score >= 63) strcpy(r.letter_grade, "C");
    else if (score >= 60) strcpy(r.letter_grade, "C-");
    else if (score >= 57) strcpy(r.letter_grade, "D+");
    else if (score >= 53) strcpy(r.letter_grade, "D");
    else if (score >= 50) strcpy(r.letter_grade, "D-");
    return r;
}

STATS process_data(RECORD *dataset, int count)
{
    // your code
    float sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += dataset[i].score;
    }

    float mean = sum / count;

    float varianceSum = 0;
    for (int i = 0; i < count; ++i) {
        varianceSum += pow(dataset[i].score - mean, 2);
    }
    float stddev = sqrt(varianceSum / count);

    qsort(dataset, count, sizeof(RECORD), compareScores);
    float median;
    if (count % 2 == 0) {
        median = (dataset[count / 2].score + dataset[(count / 2) - 1].score) / 2.0;
    } else {
        median = dataset[count / 2].score;
    }

    STATS stats = {count, mean, stddev, median};
    return stats;
    
    
}

int import_data(FILE *fp, RECORD *dataset)
{
    // your code
    int count = 0;
    while (fscanf(fp, "%20[^,],%f\n", dataset[count].name, &dataset[count].score) == 2) {
        count++;
        if (count >= MAX_REC) break;
    }
    return count;
}

int report_data(FILE *fp, RECORD *dataset, int count)
{
    // your code
    if (count < 1) return 0;

	    for (int i = 0; i < count; i++) {
	        GRADE g = grade(dataset[i].score);
	        fprintf(fp, "%s,%.1f,%s\n", dataset[i].name, dataset[i].score, g.letter_grade);
	    }

	    return 1;
}