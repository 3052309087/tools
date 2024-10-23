#include <stdio.h>

// �������ڼ���PSC��CCR
void calculatePWMParameters(int clockFreqMHz, int pwmFreqHz, int dutyCyclePercent, int ARR) {
    int clockFreqHz = clockFreqMHz * 1000000;  // ��ʱ��Ƶ�ʴ�MHzת��ΪHz
    int PSC, CCR;

    // ����PSC
    PSC = clockFreqHz / ((ARR + 1) * pwmFreqHz) - 1;

    // ����CCRֵ��ռ�ձ� = CCR / ARR * 100%��
    CCR = (ARR + 1) * dutyCyclePercent / 100;

    // ����ÿ����1%ռ�ձ�ʱCCR������
    int ccrIncrementPerPercent = (ARR + 1) / 100;

    // ������
    printf("ʱ��Ƶ��: %d MHz\n", clockFreqMHz);
    printf("PWMƵ��: %d Hz\n", pwmFreqHz);
    printf("ռ�ձ�: %d%%\n", dutyCyclePercent);
    printf("�Զ���װ�ؼĴ���:ARRֵ: %d\n", ARR);
    printf("Ԥ��Ƶ����PSCֵ: %d\n", PSC);
    printf("��׽�ȽϼĴ���:CCRֵ: %d\n", CCR);
    printf("ÿ����1%%ռ�ձȣ�CCR����: %d\n", ccrIncrementPerPercent);
}

int main() {
    int clockFreqMHz, pwmFreqHz, dutyCyclePercent, ARR;

   while (1)
   {
     // �û�����
    printf("������STM32��ʱ��Ƶ��(MHz): ");
    scanf("%d", &clockFreqMHz);

    printf("������PWMƵ��(Hz): ");
    scanf("%d", &pwmFreqHz);

    printf("������ռ�ձ�(%%): ");
    scanf("%d", &dutyCyclePercent);

    printf("������ARRֵ: ");
    scanf("%d", &ARR);

    // ���ú�������PWM����
    calculatePWMParameters(clockFreqMHz, pwmFreqHz, dutyCyclePercent, ARR);
   }
   

    return 0;
}
