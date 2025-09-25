# _WWAN_SMS_SEND structure

## Description

The WWAN_SMS_SEND structure represents an SMS text message to send.

## Members

### `SmsFormat`

The format of the SMS text message.

### `u`

Container union for the different SMS formats.

### `u.Pdu`

Short message data types to be used depending on the value of
**SmsFormat** as shown in the following table.

| SmsFormat | Member to use |
| --- | --- |
| WwanSmsFormatPdu | Pdu |
| WwanSmsFormatCdma | Cdma |

### `u.Cdma`

Short message data types to be used depending on the value of
**SmsFormat** as shown in the following table.

| SmsFormat | Member to use |
| --- | --- |
| WwanSmsFormatPdu | Pdu |
| WwanSmsFormatCdma | Cdma |

## See also

[NDIS_WWAN_SMS_SEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_sms_send)

[WWAN_SMS_SEND_CDMA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_send_cdma)

[WWAN_SMS_SEND_PDU](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_send_pdu)