typedef enum {
  wpa_akm_none = (WPA_OUI_PREFIX, 0),
  wpa_akm_1x = (WPA_OUI_PREFIX, 1),
  wpa_akm_psk = (WPA_OUI_PREFIX, 2),
  wpa_akm_max = wpa_akm_psk
} WPA_AKM_SUITE;