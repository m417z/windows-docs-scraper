# _WWAN_SMS_FILTER structure

## Description

The WWAN_SMS_FILTER structure represents the filter to apply to SMS messages on the MB device.

## Members

### `Flag`

A value from the WWAN_SMS_FLAG enumeration that represents what filter to use to display SMS
messages for.

### `MessageIndex`

A value between 1 and
*ulMaxMessageIndex* that is an index into the device's message store.

This value in this member is valid only if
**Flag** is set to
**WwanSmsFlagIndex**. The MB Service sets this member if
**Flag** is set to
**WwanSmsFlagIndex**. For all flags other than
**WwanSmsFlagIndex**, the MB Service sets this index to WWAN_MESSAGE_INDEX_NONE.

## Remarks

When
**Flag** is
**WwanSmsFlagIndex**, the filter identifies the SMS message specified by
**MessageIndex** .

## See also

[NDIS_WWAN_SMS_DELETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_sms_delete)

[WWAN_SMS_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sms_flag)

[WWAN_SMS_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_read)