typedef enum {
  rsna_cipher_group = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 0),
  rsna_cipher_wep40 = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 1),
  rsna_cipher_tkip = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 2),
  rsna_cipher_reserved = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 3),
  rsna_cipher_ccmp_128 = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 4),
  rsna_cipher_wep104 = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 5),
  rsna_cipher_bip_cmac_128 = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 6),
  rsna_cipher_no_group_traffic = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 7),
  rsna_cipher_gcmp_128 = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 8),
  rsna_cipher_gcmp_256 = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 9),
  rsna_cipher_ccmp_256 = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 10),
  rsna_cipher_bip_gmac_128 = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 11),
  rsna_cipher_bip_gmac_256 = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 12),
  rsna_cipher_bip_cmac_256 = CIPHER_FROM_TYPE(RSNA_OUI_PREFIX, 13),
  rsna_cipher_max = rsna_cipher_bip_cmac_256
} RSNA_CIPHER_SUITE;