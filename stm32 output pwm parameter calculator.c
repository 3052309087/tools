#include <stdio.h>

// 定义函数用于计算ARR和CCR值
void calculate_pwm_params(unsigned long clock_freq_mhz, unsigned long pwm_freq, float duty_cycle, unsigned int prescaler) {
    // 将输入的时钟频率从MHz转换为Hz
    unsigned long clock_freq = clock_freq_mhz * 1000000;

    // 计算ARR值 (自动重装载寄存器)
    unsigned long arr = (clock_freq / (prescaler + 1)) / pwm_freq - 1;

    // 计算CCR值 (捕捉比较寄存器)，占空比以百分比输入
    unsigned long ccr = (unsigned long)((duty_cycle / 100.0) * (arr + 1));

    // 输出计算结果
    printf("预分频器 (Prescaler): %d\n", prescaler);
    printf("自动重装载寄存器 (ARR): %lu\n", arr);
    printf("捕捉比较寄存器 (CCR): %lu\n", ccr);

    // 计算占空比变化1%时CCR的变化
    unsigned long ccr_delta = (unsigned long)((1.0 / 100.0) * (arr + 1));

    // 输出增加或减少1%占空比时CCR的变化量
    printf("增加1%%占空比时，CCR需要增加的值: %lu\n", ccr_delta);
    printf("减少1%%占空比时，CCR需要减少的值: %lu\n", ccr_delta);
}

int main() {
    while (1)
    {
        unsigned long clock_freq_mhz;
    unsigned long pwm_freq;
    float duty_cycle;
    unsigned int prescaler;

    // 用户输入单片机时钟频率（以MHz为单位）、期望的PWM频率、占空比和预分频器值
    printf("请输入单片机的时钟频率 (MHz): ");
    scanf("%lu", &clock_freq_mhz);
    printf("请输入期望的PWM频率 (Hz): ");
    scanf("%lu", &pwm_freq);
    printf("请输入占空比 (0~100%%): ");
    scanf("%f", &duty_cycle);
    printf("请输入预分频器 (PSC) 值: ");
    scanf("%u", &prescaler);

    // 调用函数进行计算
    calculate_pwm_params(clock_freq_mhz, pwm_freq, duty_cycle, prescaler);
    }
    
    

    return 0;
}
