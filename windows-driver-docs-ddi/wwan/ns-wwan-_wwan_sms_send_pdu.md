# _WWAN_SMS_SEND_PDU structure

## Description

The WWAN_SMS_SEND_PDU structure represents a PDU-style SMS message.

## Members

### `Size`

For GSM-based devices that support PDU-style SMS messages, the size, in bytes, of the message
before conversion to hexadecimal.

For CDMA-based devices that support sending SMS messages in binary format, the size, in bytes, of the
message in
**PduData** .

The following table lists the different values for the
**SmsFormat** member of the
[WWAN_SMS_SEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_send) structure and their
corresponding range that is allowed in this member.

| SmsFormat | Size |
| --- | --- |
| WwanSmsFormatPdu | 1 to WWAN_SMS_RAW_PDU_LEN |
| WwanSmsFormatCdma | 1 to WWAN_SMS_CDMA_MAX_MSG_LEN |

**Note** For GSM-based devices, if
**ElementType** is set to
**WwanStructSmsPdu**, this member describes the size, in bytes, of
**PduData** excluding the Service Center address. The first byte of
**PduData** represents the size of the Service Center address that the miniport driver must add when
it calculates the exact size of the
**PduData** buffer.

For example:

If
**PduData** [0] = 0, then the size of
**PduData** is
**Size** + 1.

If
**PduData** [0] != 0, then the size of
**PduData** is
**Size** +
**PduData** [0].

### `PduData`

A NULL-terminated string that represents the content of the record.

For GSM-based devices, the contents are coded in a hexadecimal string format (according to the 3GPP
TS 27.005 and 3GPP TS 23.040 standards) that represents the SMS text message.

For CDMA-based devices that support sending SMS messages in binary format (that is, miniport drivers
that return WWAN_SMS_CAPS_PDU_SEND in the
**WwanSmsCaps** member of
[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps)),
**PduData** contains the SMS message as a byte array, as defined in section 3.4.2.1 SMS Point-to-Point
Message in the 3GPP2 specification C.S0015-A "Short Message Service (SMS) for Wideband Spread Spectrum
Systems". SMS will only support Wireless Messaging Teleservice (WMT) format. Miniport drivers should
typecast this information to BYTE[] for CDMA-based devices. It is not coded in hexadecimal string
format.

## See also

[WWAN_SMS_SEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_send)