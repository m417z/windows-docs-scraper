## Description

The **RSNA_AKM_SUITE** enumeration specifies Robust Security Network Association (RSNA) authentication and key management (AKM) suites.

## Constants

### `rsna_akm_none:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 0)

No RSNA AKM suite.

### `rsna_akm_1x:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 1)

802.1X authentication with a Pseudo-Random Function (PRF) of 128 bits.

### `rsna_akm_psk:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 2)

Pre-Shared Key (PSK) authentication with a PRF of 128 bits.

### `rsna_akm_ft_1x_sha256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 3)

Fast Transition (FT) with 802.1X authentication and the SHA-256 encryption algorithm.

### `rsna_akm_ft_psk_sha256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 4)

FT with PSK authentication and the SHA-256 encryption algorithm.

### `rsna_akm_1x_sha256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 5)

802.1X authentication with the SHA-256 encryption algorithm.

### `rsna_akm_psk_sha256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 6)

PSK authentication with the SHA-256 encryption algorithm.

### `rsna_akm_tdls_sha256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 7)

Tunneled Direct-Link Setup (TDLS) with the SHA-256 encryption algorithm.

### `rsna_akm_sae_pmk256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 8)

Simultaneous Authentication of Equals (SAE) with a Pairwise Master Key (PMK) of 256 bits.

### `rsna_akm_ft_sae_pmk256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 9)

FT with SAE and a PMK of 256 bits.

### `rsna_akm_peerkey_sha256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 10)

Peer key authentication with the SHA-256 encryption algorithm.

### `rsna_akm_1x_suite_b_sha256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 11)

Suite B Cryptography with 802.1X authentication and the SHA-256 encryption algorithm.

### `rsna_akm_1x_suite_b_sha384:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 12)

Suite B Cryptography/Converged Security and Network Architecture (CSNA) with 802.1X authentication and the SHA-384 encryption algorithm.

### `rsna_akm_ft_1x_sha384_cmp_256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 13)

FT with 802.1X authentication, SHA-384 for encryption, and either Counter Mode Cipher Block Chaining Message Authentication Code Protocol (CCMP) or Galois/Counter Mode Protocol (GCMP) with 256 bits for data confidentiality.

### `rsna_akm_fils_1x_sha256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 14)

Fast Initial Link Setup (FILS) with 802.1X authentication and the SHA-256 encryption algorithm.

### `rsna_akm_fils_1x_sha384:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 15)

FILS with 802.1X authentication and the SHA-384 encryption algorithm.

### `rsna_akm_ft_fils_1x_sha256:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 16)

FT with FILS, 802.1X authentication, and the SHA-256 encryption algorithm.

### `rsna_akm_ft_fils_sha384:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 17)

FT with FILS and the SHA-384 encryption algorithm.

### `rsna_akm_owe:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 18)

Reserved for Opportunistic Wireless Encryption (OWE).

### `rsna_akm_ft_psk_sha384:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 19)

FT with PSK authentication and the SHA-384 encryption algorithm.

### `rsna_akm_psk_sha384:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 20)

PSK authentication with the SHA-384 encryption algorithm.

### `rsna_akm_ft_1x_sha384:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 22)

FT with 802.1X authentication and the SHA-384 encryption algorithm.

### `rsna_akm_1x_sha384:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 23)

802.1X authentication with the SHA-384 encryption algorithm.

### `rsna_akm_sae_pmk384:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 24)

Simultaneous Authentication of Equals (SAE) with a PMK of 384 bits.

### `rsna_akm_ft_sae_pmk384:AKM_FROM_TYPE(RSNA_OUI_PREFIX,` 25)

Fast Transition (FT) with SAE and a PMK of 384 bits.

### `rsna_akm_max:rsna_akm_ft_sae_pmk384`

The maximum range of the **RSNA_AKM_SUITE** enum.

## Remarks

The **RSNA_AKM_SUITE** enumeration is used in the [WDI_TLV_RSNA_AKM_SUITE](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-rsna-akm-suite) TLV.

## See also

[WDI_TLV_RSNA_AKM_SUITE](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-rsna-akm-suite)

[**AKM_FROM_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/nf-windot11-akm_from_type)

[**RSNA_AKM_CIPHER_PAIR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-rsna_akm_cipher_pair)

[WiFiCx Wi-Fi 7 feature requirements](https://learn.microsoft.com/windows-hardware/drivers/netcx/wificx-wi-fi-7)