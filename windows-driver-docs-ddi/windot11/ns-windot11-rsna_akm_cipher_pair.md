## Description

The **RSNA_AKM_CIPHER_PAIR** structure represents a Robust Security Network Association (RSNA) authentication and key management (AKM) and encryption cipher pair.

## Members

### `akm`

An [**RSNA_AKM_SUITE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-rsna_akm_suite) enumeration value that specifies the RSNA AKM suite.

### `cipher`

An [**RSNA_CIPHER_SUITE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-rsna_cipher_suite) enumeration value that specifies the RSNA cipher suite.

## Remarks

The **RSNA_AKM_CIPHER_PAIR** structure is used in the [WDI_TLV_RSNA_AKM_CIPHER_SUITE](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-rsna-akm-cipher-suite) TLV.

## See also

[**RSNA_AKM_SUITE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-rsna_akm_suite)

[**RSNA_CIPHER_SUITE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ne-windot11-rsna_cipher_suite)

[WDI_TLV_RSNA_AKM_CIPHER_SUITE](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-rsna-akm-cipher-suite)

[WiFiCx Wi-Fi 7 feature requirements](https://learn.microsoft.com/windows-hardware/drivers/netcx/wificx-wi-fi-7)