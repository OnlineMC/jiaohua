// ��74HC138�����Ƶ����ţ����������أ�����
#define Y4C 4
#define Y7C 7
#define Y6C 6
#define Y5C 5

// ��Ӳ��������
//SEG_BUS: ����� ��������
//SEG_SEL: ����� λѡ
//LED_BUS: LED    ����
#define SEG_BUS 7
#define SEG_SEL 6
#define LED_BUS 4

void chip_sel(unsigned char selbit);
void reset_sel();