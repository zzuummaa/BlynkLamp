find_program(CURL NAMES curl)

if (CURL)
    message("-- Curl detected: true")
    set(CURL_DETECTED TRUE)
    set(OTA_HOST zzuummaa.sytes.net)
    set(OTA_PORT 9443)
    set(OTA_TOKEN b4e0b3453ffb400cb6c049f401b75af2)
    add_definitions( -DOTA_TOKEN_DEF=${OTA_TOKEN} )

    add_custom_target(PLATFORMIO_UPLOAD_OTA
        COMMAND curl -v -F file=@${CMAKE_SOURCE_DIR}/.pioenvs/esp01_1m/firmware.bin --insecure -u admin@blynk.cc:admin https://${OTA_HOST}:${OTA_PORT}/admin/ota/start?token=${OTA_TOKEN}
        DEPENDS PLATFORMIO_BUILD
    )
else()
    message("-- Curl detected: false")
endif()
