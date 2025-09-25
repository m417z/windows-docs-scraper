typedef enum {
  wpa_cipher_none = CIPHER_FROM_TYPE(WPA_OUI_PREFIX, 0),
  wpa_cipher_wep40 = CIPHER_FROM_TYPE(WPA_OUI_PREFIX, 1),
  wpa_cipher_tkip = CIPHER_FROM_TYPE(WPA_OUI_PREFIX, 2),
  wpa_cipher_ccmp_128 = CIPHER_FROM_TYPE(WPA_OUI_PREFIX, 4),
  wpa_cipher_wep104 = CIPHER_FROM_TYPE(WPA_OUI_PREFIX, 5),
  wpa_cipher_bip_cmac_128 = CIPHER_FROM_TYPE(WPA_OUI_PREFIX, 6),
  wpa_cipher_max = wpa_cipher_bip_cmac_128
} WPA_CIPHER_SUITE;