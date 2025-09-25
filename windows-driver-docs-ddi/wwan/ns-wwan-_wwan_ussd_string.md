# _WWAN_USSD_STRING structure

## Description

The WWAN_USSD_STRING structure describes an Unstructured Supplementary Service Data (USSD) string.

## Members

### `DataCodingScheme`

The data coding scheme that specifies how the **String** member is encoded, as defined in 3GPP TS 23.038, section 5.

### `StringLength`

The length, in bytes, of USSD string in stored in the **String** member.

### `String`

The USSD string encoded according to the **DataCodingScheme** member.

## Remarks

**StringLength** can be from 1 to 160 bytes. Specify 0 bytes to indicate an absent USSD string.

This structure is designed for USSD Stage 2 (3GPP 23.090) and eliminates the need to perform any interpretation of the USSD string in the miniport driver or MB device. If the miniport driver or MB device supports USSD Stage 1 and the network uses USSD Stage 1 then the miniport driver or MB device must transcode between ASCII (IA5) used in USSD Stage 1 and this structure:

For USSD requests, the miniport driver or MB device must decode the USSD string from the GSM-7 bit default alphabet used at requests to ASCII.

For USSD notifications, the miniport driver or MB device must encode the USSD string from ASCII to GSM-7 bit and set the **DataCodingScheme** member to indicate that the GSM-7 bit default alphabet is used.

## See also

[WWAN_USSD_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ussd_event)

[WWAN_USSD_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ussd_request)