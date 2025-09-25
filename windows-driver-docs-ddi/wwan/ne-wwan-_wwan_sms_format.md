# _WWAN_SMS_FORMAT enumeration

## Description

The WWAN_SMS_FORMAT enumeration lists different Short Message Service (SMS) formats.

## Constants

### `WwanSmsFormatPdu`

SMS messages are in PDU format. For GSM-based devices, messages are hexadecimal strings that
represent messages in PDU format as defined in the 3GPP TS 27.005 and 3GPP TS 23.040 specifications. For
CDMA-based devices messages are byte arrays that represent messages as defined in section 3.4.2.1 SMS
Point-to-Point Message in 3GPP2 specification C.S0015-A "Short Message Service (SMS) for Wideband Spread
Spectrum Systems".

### `WwanSmsFormatReserved0`

This value is reserved for future use. Do not use.

### `WwanSmsFormatReserved1`

This value is reserved for future use. Do not use.

### `WwanSmsFormatReserved2`

This value is reserved for future use. Do not use.

### `WwanSmsFormatCdma`

The message is in text format. For more information, see
[WWAN_SMS_CDMA_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_cdma_record) and
[WWAN_SMS_SEND_CDMA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_send_cdma). This value applies
only to CDMA-based devices.

### `WwanSmsFormatMax`

This value is reserved. Do not use.

## Remarks

CDMA-based devices support only
**WwanSmsFormatCdma**. The
**WwanSmsFormatCdma** format is not applicable for GSM-based devices.

## See also

[WWAN_SET_SMS_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_sms_configuration)

[WWAN_SMS_CDMA_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_cdma_record)

[WWAN_SMS_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_configuration)

[WWAN_SMS_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_read)

[WWAN_SMS_SEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_send)

[WWAN_SMS_SEND_CDMA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_send_cdma)