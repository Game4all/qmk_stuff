#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12
#define FORCE_NKRO

// Disable all the reactive rgb matrix effects
#undef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#undef RGB_MATRIX_KEYPRESSES
#undef RGB_MATRIX_KEYRELEASES

/// limiting number of leds processed by RGB mat update to 8 to 'improve' responsiveness
#undef RGB_MATRIX_LED_PROCESS_LIMIT
#define RGB_MATRIX_LED_PROCESS_LIMIT 8