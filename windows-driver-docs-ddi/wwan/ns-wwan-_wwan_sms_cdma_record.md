# _WWAN_SMS_CDMA_RECORD structure

## Description

The WWAN_SMS_CDMA_RECORD structure represents CDMA-based SMS text message records.

## Members

### `MessageIndex`

An index into the virtual message store that is maintained by the miniport driver. This index is
1-based and the maximum index is
**ulMaxMessageIndex** as returned in WWAN_SMS_CONFIGURATION_STATUS. Be aware that the specification
does not differentiate between physically available data stores. If the message is a Class 0
(flash/alert) message, this must be set to WWAN_MESSAGE_INDEX_NONE.

### `MsgStatus`

The status of the record that represents whether the SMS message is new (unread), old (read), a
draft, or sent.

### `Address`

A NULL-terminated string with a maximum length of 15 digits that represents a mobile number. The
number can be in any of the following formats:

* "+ \0"
* "\0"

If
**MsgStatus** is
**WwanMsgStatusDraft** or
**WwanMsgStatusSent**, miniport drivers should specify the receiver's mobile number in the previous
members. Otherwise, if
**MsgStatus** is
**WwanMsgStatusNew** or
**WwanMsgStatusOld**, miniport drivers should specify the sender's mobile number.

### `ScTimeStamp`

A string that represent the Service Center (SC) timestamp, in the following format: "
*YY*/*MM*/*DD*,
*HH*:*mm*:*SS*±*ZZ*" where:

* *YY* represents the last two digits of the year. For example, 07 corresponds to 2007. Valid range
  is between 00 and 99.
* *MM* represents the month index in double digits. For example, 01 for January and 12 corresponds
  to December. Valid range is between 01 and 12.
* *DD* represents the day of the month in double digits. For example, 01 corresponds to the 1st day
  of the month, and 31 corresponds to the 31st day. Valid range is between 01 and 31.
* *HH* represents the hours in 24-hour format. For example, 01 corresponds to 1 AM and 13
  corresponds to 1PM. Valid range is between 00 and 23.
* *mm* represents the minutes in double digits. For example, 01 corresponds to 1 minute and 30
  corresponds to 30 minutes. Valid range is between 00 and 59.
* *SS* represents the seconds in double digits. For example, 01 corresponds to 1 second and 30
  corresponds to 30 seconds. Valid range is between 00 and 59.
* *ZZ* represents the time zone with reference to Greenwich Mean Time (GMT). For example, 01
  corresponds to 1 hour and 12 corresponds to 12 hours. Valid range is between 00 and 13 (-12 to +13
  when combined with the Â± symbol).

For example, to represent October 2nd, 1996, 20:01:54 GMT+2 hours use the following string timestamp
"96/10/02,20:01:54+02"

### `EncodingId`

The encoding that is used in the CDMA message.
**EncodedMsg** message should be interpreted based on the value of this member.

### `LanguageId`

The language that is used in the SMS text message.

### `SizeInBytes`

The size, in bytes, of
**EncodedMsg** . The encoded message can have a maximum length of WWAN_SMS_CDMA_MAX_BUF_LEN. Miniport
drivers must specify a value for this member for all encoding types.

### `SizeInCharacters`

Size of
**EncodedMsg** in number of characters represented by the encoded data. Miniport drivers should
specify 0 for this member when
**EncodingId** is set to
**WwanSmsCdmaEncodingShiftJis** or
**WwanSmsCdmaEncodingKorean**.

### `EncodedMsg`

The encoded content of the record that represents the SMS text message.

## See also

[WWAN_MSG_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_msg_status)

[WWAN_SMS_CDMA_ENCODING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sms_cdma_encoding)

[WWAN_SMS_CDMA_LANG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sms_cdma_lang)