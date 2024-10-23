#include <stdio.h>

// 函数用于计算PSC和CCR
void calculatePWMParameters(int clockFreqMHz, int pwmFreqHz, int dutyCyclePercent, int ARR) {
    int clockFreqHz = clockFreqMHz * 1000000;  // 将时钟频率从MHz转换为Hz
    int PSC, CCR;

    // 计算PSC
    PSC = clockFreqHz / ((ARR + 1) * pwmFreqHz) - 1;

    // 计算CCR值（占空比 = CCR / ARR * 100%）
    CCR = (ARR + 1) * dutyCyclePercent / 100;

    // 计算每增加1%占空比时CCR的增量
    int ccrIncrementPerPercent = (ARR + 1) / 100;

    // 输出结果
    printf("时钟频率: %d MHz\n", clockFreqMHz);
    printf("PWM频率: %d Hz\n", pwmFreqHz);
    printf("占空比: %d%%\n", dutyCyclePercent);
    printf("自动重装载寄存器:ARR值: %d\n", ARR);
    printf("预分频器：PSC值: %d\n", PSC);
    printf("捕捉比较寄存器:CCR值: %d\n", CCR);
    printf("每增加1%%占空比，CCR增加: %d\n", ccrIncrementPerPercent);
}

int main() {
    int clockFreqMHz, pwmFreqHz, dutyCyclePercent, ARR;

   while (1)
   {
     // 用户输入
    printf("请输入STM32的时钟频率(MHz): ");
    scanf("%d", &clockFreqMHz);

    printf("请输入PWM频率(Hz): ");
    scanf("%d", &pwmFreqHz);

    printf("请输入占空比(%%): ");
    scanf("%d", &dutyCyclePercent);

    printf("请输入ARR值: ");
    scanf("%d", &ARR);

    // 调用函数计算PWM参数
    calculatePWMParameters(clockFreqMHz, pwmFreqHz, dutyCyclePercent, ARR);
   }
   

    return 0;
}
