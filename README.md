# atmega8535-check-code

## Cara Menggunakan dan Mengubah Port

1. **Skenario 1 (Default):** Cek SWITCH di PORTA dan LED di PORTB. Tidak perlu mengubah apapun dalam kode, karena kode yang disediakan sudah diatur untuk ini.

    - **Rangkaian:** Hubungkan 8 switch ke PORTA dan 8 LED ke PORTB.

2. **Skenario 2:** Cek SWITCH di PORTC dan LED di PORTD. Hanya perlu mengubah bagian Konfigurasi Port menjadi seperti ini:

    ```c++
    // Port untuk OUTPUT (LED)
    #define LED_PORT        PORTD
    #define LED_DDR         DDRD

    // Port untuk INPUT (SWITCH)
    #define SWITCH_PIN      PINC
    #define SWITCH_DDR      DDRC
    #define SWITCH_PORT     PORTC
    ```

    - **Rangkaian:** Hubungkan 8 switch ke PORTC dan 8 LED ke PORTD.

3. **Skenario 3:** Cek SWITCH di PORTB dan LED di PORTA. Ubah konfigurasi menjadi:

    ```c++
    // Port untuk OUTPUT (LED)
    #define LED_PORT        PORTA
    #define LED_DDR         DDRA

    // Port untuk INPUT (SWITCH)
    #define SWITCH_PIN      PINB
    #define SWITCH_DDR      DDRB
    #define SWITCH_PORT     PORTB
    ```

    - **Rangkaian:** Hubungkan 8 switch ke PORTB dan 8 LED ke PORTA.

## Rangkaian yang Diperlukan

1. **Untuk Rangkaian SWITCH (Input):**

    - Satu kaki dari setiap switch dihubungkan ke salah satu pin I/O (misal: PA0, PA1, ..., PA7).

    - Kaki lainnya dari setiap switch dihubungkan ke GND (Ground).

2. **Untuk Rangkaian LED (Output, Active-Low):**

    - Kutub Anoda (+) dari setiap LED dihubungkan ke VCC (+5V).

    - Kutub Katoda (-) dari setiap LED dihubungkan melalui sebuah resistor (umumnya 220Ω atau 330Ω) ke pin I/O (misal: PB0, PB1, ..., PB7).
