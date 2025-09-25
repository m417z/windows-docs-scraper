# _WWAN_SMS_CONFIGURATION structure

## Description

The WWAN_SMS_CONFIGURATION structure represents the SMS configuration of the MB device.

## Members

### `ScAddress`

A NULL-terminated string with a maximum length of 20 digits that represents the Service Center
(SC) address. This member is used by all text messages for sending and receiving. For PDU-style SMS
messages, this information is used if it is not available in PDU data.

The number can be in any of the following formats:

* "+ \0"
* "\0"

For set requests, the MB Service can set this member to **NULL**. In this case, a **NULL** indicates the
miniport driver does not need to update the
**ScAddress** member and should not update this member thereafter.

### `SmsFormat`

The SMS message format that should be used for the unsolicited indication of new SMS message
arrivals. CDMA-based devices support only the
**WwanSmsFormatCdma** format. The
**WwanSmsFormatCdma** format does not apply to GSM-based devices.

### `ulMaxMessageIndex`

The maximum number of messages that can be stored on the device. Miniport drivers report this
value for
*query* requests. Unsolicited events that are used to notify the change of
**ScAddress** must also contain valid information for this member.

## Remarks

Miniport drivers need to fill in this data structure only when processing
*query* requests, or in case of unsolicited events.

## See also

[NDIS_WWAN_SMS_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_sms_configuration)

[WWAN_SMS_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sms_format)