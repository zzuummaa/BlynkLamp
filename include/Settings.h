/*
 * General options
 */

#define BOARD_FIRMWARE_VERSION        "1.0.1"
#define BOARD_HARDWARE_VERSION        "1.0.0"

#define BOARD_NAME                    "Product Name"        // Name of your product. Should match App Export request info.
#define BOARD_VENDOR                  "Company Name"        // Name of your company. Should match App Export request info.
#define BOARD_TEMPLATE_ID             "TMPL0000"            // ID of the Tile Template. Can be found in Tile Template Settings

#define PRODUCT_WIFI_SSID             "Our Product"         // Name of the device, to be displayed during configuration. Should match export request info.
#define BOARD_CONFIG_AP_URL           "our-product.cc"      // Config page will be available in a browser at 'http://our-product.cc/'

/*
 * Board configuration (see examples below).
 */

#if defined(ARDUINO_ESP8266_ESP01)

  //#define APP_DEBUG        // Comment this out to disable debug prints

  // Custom board configuration
  #define BOARD_BUTTON_PIN            0                     // Pin where user button is attached
  #define BOARD_BUTTON_ACTIVE_LOW     true                  // true if button is "active-low"

  #define BOARD_LED_PIN               1                     // Set LED pin - if you have a single-color LED attached
  #define BOARD_LED_INVERSE           false                 // true if LED is common anode, false if common cathode
  #define BOARD_LED_BRIGHTNESS        64                    // 0..255 brightness control

#elif defined(ARDUINO_ESP8266_NODEMCU)

  #define APP_DEBUG        // Comment this out to disable debug prints

  // Example configuration for NodeMCU v1.0 Board
  #define BOARD_BUTTON_PIN            0
  #define BOARD_BUTTON_ACTIVE_LOW     true

  #define BOARD_LED_PIN               2
  #define BOARD_LED_INVERSE           false
  #define BOARD_LED_BRIGHTNESS        64

#elif defined(USE_SPARKFUN_BLYNK_BOARD)

  #warning "Sparkfun Blynk board selected"

  // Example configuration for SparkFun Blynk Board
  #define BOARD_BUTTON_PIN            0
  #define BOARD_BUTTON_ACTIVE_LOW     true

  #define BOARD_LED_PIN_WS2812        4
  #define BOARD_LED_BRIGHTNESS        64

#elif defined(USE_WITTY_CLOUD_BOARD)

  #warning "Witty Cloud board selected"

  // Example configuration for Witty cloud Board
  #define BOARD_BUTTON_PIN            4
  #define BOARD_BUTTON_ACTIVE_LOW     true

  #define BOARD_LED_PIN_R             15
  #define BOARD_LED_PIN_G             12
  #define BOARD_LED_PIN_B             13
  #define BOARD_LED_INVERSE           false
  #define BOARD_LED_BRIGHTNESS        64

#else
  #error "No board selected"
#endif


/*
 * Advanced options
 */

#define BUTTON_HOLD_TIME_INDICATION   3000
#define BUTTON_HOLD_TIME_ACTION       10000

#define BOARD_PWM_MAX                 1023

#define WIFI_NET_CONNECT_TIMEOUT      30000
#define WIFI_CLOUD_CONNECT_TIMEOUT    15000
#define WIFI_AP_CONFIG_PORT           80
#define WIFI_AP_IP                    IPAddress(192, 168, 4, 1)
#define WIFI_AP_Subnet                IPAddress(255, 255, 255, 0)
//#define WIFI_CAPTIVE_PORTAL_ENABLE

#define USE_TICKER
//#define USE_TIMER_ONE
//#define USE_TIMER_THREE

#if defined(APP_DEBUG)
  #if defined(USE_CUSTOM_BOARD) & BOARD_LED_PIN == 1 || BOARD_LED_PIN == 3
    #warning UART pins should not used as BOARD_LED_PIN
  #endif
  #define DEBUG_PRINT(...) BLYNK_LOG1(__VA_ARGS__)
#else
  #define DEBUG_PRINT(...)
#endif

