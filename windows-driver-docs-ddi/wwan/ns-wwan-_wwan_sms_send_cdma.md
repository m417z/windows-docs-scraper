# _WWAN_SMS_SEND_CDMA structure

## Description

The WWAN_SMS_SEND_CDMA structure represents a CDMA-based SMS text message to send.

## Members

### `EncodingId`

The encoding that is used in the CDMA message.
**EncodedMsg** message should be interpreted based on the value of this member.

### `LanguageId`

The language used in CDMA message. This is an indicator of the language used in SMS message and
may be set to
**WwanSmsCdmaLangUnknown**, if the language is not known.

### `Address`

A NULL-terminated string with a maximum length of 15 digits that represents a mobile number. The
number can be in any of the following formats:
* "+ \0"
* "\0"

If
**MsgStatus** is
*WwanMsgStatusDraft* or
*WwanMsgStatusSent*, miniport drivers should specify the receiver's mobile number in the previous
members. Otherwise, if
**MsgStatus** is
*WwanMsgStatusNew* or
*WwanMsgStatusOld*, miniport drivers should specify the sender's mobile number.

### `SizeInBytes`

The size, in bytes, of
**EncodedMsg** . The encoded message can have a maximum length of WWAN_SMS_CDMA_MAX_BUF_LEN. Miniport
drivers must specify a value for this member for all encoding types.

### `SizeInCharacters`

Size of
**EncodedMsg** in number of characters represented by the encoded data. Miniport drivers should
specify 0 for this member when
**EncodingId** is set to
*WwanSmsCdmaEncodingShiftJis* or
*WwanSmsCdmaEncodingKorean*.

### `EncodedMsg`

The encoded content that represents the CDMA-based SMS text message.

## See also

[WWAN_SMS_CDMA_ENCODING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sms_cdma_encoding)

[WWAN_SMS_CDMA_LANG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sms_cdma_lang)

[WWAN_SMS_SEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_send)