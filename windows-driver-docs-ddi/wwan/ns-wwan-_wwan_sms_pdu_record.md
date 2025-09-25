# _WWAN_SMS_PDU_RECORD structure

## Description

The WWAN_SMS_PDU_RECORD structure represents a PDU-style SMS message record.

## Members

### `MessageIndex`

An index into the virtual message store that is maintained by the miniport driver. This index is
1-based and the maximum index is
**ulMaxMessageIndex** returned in WWAN_SMS_CONFIGURATION_STATUS. Be aware that the specification does
not differentiate between physically available data stores. If the message is a Class 0 (flash/alert)
message, this must be set to WWAN_MESSAGE_INDEX_NONE.

### `MsgStatus`

The status of the record that represents whether the SMS message is new (unread), old (read), a
draft, or sent.

### `Size`

The size, in bytes, of the record.

For GSM-based devices, this represents the size of the message before conversion to a hexadecimal
string.

For CDMA-based devices, this represents the number of bytes in the
**PduData** .

### `PduData`

For GSM-based devices, a NULL-terminated string that contains the content of the record coded in a
hexadecimal string format (according to the 3GPP TS 27.005 and 3GPP TS 23.040 standards) that represents
the SMS message.

For CDMA-based devices that support reading SMS messages in binary format (as returned in
WWAN_SMS_CAPS as WWAN_SMS_CAPS_PDU_RECEIVE) this member contains the SMS message as a byte array, as
defined in section 3.4.2.1 SMS Point-to-Point Message in 3GPP2 specification C.S0015-A "Short Message
Service (SMS) for Wideband Spread Spectrum Systems". SMS will only support Wireless Messaging
Teleservice (WMT) format. Miniport drivers should typecast this information to BYTE[] for CDMA-based
devices. It is not coded in hexadecimal string format. The message is not NULL-terminated.

## See also

[WWAN_MSG_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_msg_status)