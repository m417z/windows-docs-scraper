# _WWAN_SET_SMS_CONFIGURATION structure

## Description

The WWAN_SET_SMS_CONFIGURATION structure represents how MB devices support SMS configuration.

## Members

### `ScAddress`

A NULL-terminated string with a maximum length of 15 digits that represents the Service Center
(SC) address. This member is used by all text messages for sending and receiving. For PDU-style SMS
messages, this information is used if it is not available in PDU data.

The number can be in any of the following formats:

* "+ \0"
* "\0"

For
*set* requests, the MB Service can set this member to **NULL**. In this case, a **NULL** indicates the
miniport driver does not need to update
**ScAddress** and should not update this member thereafter.

### `SmsFormat`

The SMS message format that should be used for the unsolicited indication of new SMS message
arrivals. CDMA-based devices support only
**WwanSmsFormatCdma** format. The
**WwanSmsFormatCdma** format is does not apply to GSM-based devices.

## See also

[NDIS_WWAN_SET_SMS_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_sms_configuration)

[WWAN_SMS_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sms_format)