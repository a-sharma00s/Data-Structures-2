#include<math.h>

float monthly_payment(float principal_amount, float annual_interest_rate, int years) {
   float monthly_interest_rate = annual_interest_rate / 100 / 12;
    int total_payments = years * 12;
    float monthly_payment = principal_amount * monthly_interest_rate * pow(1 + monthly_interest_rate, total_payments) /
                            (pow(1 + monthly_interest_rate, total_payments) - 1);
    return monthly_payment;
}

float total_payment(float principal_amount, float annual_interest_rate, int years) {
    int total_payments = years * 12;
    float monthly_payment_amount = monthly_payment(principal_amount, annual_interest_rate, years);
    float total_payment_amount = monthly_payment_amount * total_payments;

    return total_payment_amount;
}

float total_interest(float principal_amount, float annual_interest_rate, int years) {
    float total_payment_amount = total_payment(principal_amount, annual_interest_rate, years);
    float total_interest_amount = total_payment_amount - principal_amount;

    return total_interest_amount;
}

