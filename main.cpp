/*
 * =================================================================================
 * Judul      : Program Tes I/O Port Fleksibel untuk ATmega8535 (DT-COMBO AVR-51)
 * Deskripsi  : Program ini membaca status 8 pin SWITCH pada satu port dan
 * menampilkannya secara langsung ke 8 pin LED di port lain.
 * Menekan SWITCHx akan menyalakan LEDx.
 *
 * Cara Pakai :
 * 1.  Hubungkan rangkaian SWITCH ke port yang didefinisikan di SWITCH_PIN.
 * 2.  Hubungkan rangkaian LED ke port yang didefinisikan di LED_PORT.
 * 3.  Ubah definisi makro di bawah ini sesuai dengan port yang ingin Anda tes.
 * 4.  Compile dan upload program ke ATmega8535.
 * =================================================================================
 */

#include <avr/io.h>

/*
 * -----------------------------------------------------------------
 * KONFIGURASI PORT (UBAH BAGIAN INI)
 * -----------------------------------------------------------------
 * Atur port mana yang akan digunakan untuk LED dan SWITCH.
 * Contoh di bawah ini menggunakan PORTA untuk SWITCH dan PORTB untuk LED.
 */
// Port untuk OUTPUT (LED)
#define LED_PORT        PORTB   // Port register untuk mengontrol LED
#define LED_DDR         DDRB    // Data Direction Register untuk LED

// Port untuk INPUT (SWITCH)
#define SWITCH_PIN      PINA    // Port register untuk membaca status Switch
#define SWITCH_DDR      DDRA    // Data Direction Register untuk Switch
#define SWITCH_PORT     PORTA   // Port register untuk mengaktifkan pull-up

/* -----------------------------------------------------------------
 * JANGAN UBAH KODE DI BAWAH INI
 * -----------------------------------------------------------------
 */
int main(void)
{
    // Langkah 1: Konfigurasi Port LED sebagai OUTPUT
    LED_DDR = 0xFF;

    // Langkah 2: Konfigurasi Port SWITCH sebagai INPUT
    SWITCH_DDR = 0x00;

    // Langkah 3: Atur nilai default Port SWITCH menjadi HIGH (1).
    SWITCH_PORT = 0xFF;

    // Loop utama program yang berjalan selamanya
    while (1)
    {
        // Baca seluruh 8-bit nilai dari port input (SWITCH_PIN)
        // dan langsung tuliskan ke port output (LED_PORT).
        //
        // - Switch tidak ditekan: PINx bit = 1 -> PORTx bit = 1 (LED mati)
        // - Switch ditekan (ke GND): PINx bit = 0 -> PORTx bit = 0 (LED nyala)
        LED_PORT = SWITCH_PIN;
    }

    return 0; // Baris ini secara teknis tidak akan pernah dieksekusi
}

/*
 * Catatan Tambahan:
 * Jika rangkaian LED ternyata Active-High (menyala saat diberi logika 1),
 * Logikanya perlu dibalik. Ganti baris di dalam while(1) menjadi:
 *
 * LED_PORT = ~SWITCH_PIN;
 *
 * Tanda '~' adalah operator bitwise NOT yang akan membalik semua bit.
 * (00001111 menjadi 11110000)
 */