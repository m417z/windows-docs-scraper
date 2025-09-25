# _WWAN_SMS_READ structure

## Description

The WWAN_SMS_READ structure represents the format and filter of SMS messages to read.

## Members

### `SmsFormat`

The format in which the miniport driver should return messages for
*query* requests. The MB Service specifies this value.

**WwanSmsFormatCdma** applies only to CDMA-based devices. CDMA-based devices support only the
**WwanSmsFormatCdma** format.

### `ReadFilter`

Represents the filter upon which the miniport driver should retrieve the messages. For example,
the filter could indicate to return all messages in the index based on the message store, or all
messages based on
**new**,
**old**,
**draft**, or
**sent** flags.

## See also

[NDIS_WWAN_SMS_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_sms_read)

[WWAN_SMS_FILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_filter)

[WWAN_SMS_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sms_format)