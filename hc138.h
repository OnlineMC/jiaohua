// 给74HC138所控制的引脚（锁存器开关）命名
#define Y4C 4
#define Y7C 7
#define Y6C 6
#define Y5C 5

// 给硬件层命名
//SEG_BUS: 数码管 断码总线
//SEG_SEL: 数码管 位选
//LED_BUS: LED    总线
#define SEG_BUS 7
#define SEG_SEL 6
#define LED_BUS 4

void chip_sel(unsigned char selbit);
void reset_sel();