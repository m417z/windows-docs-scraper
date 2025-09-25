# _WWAN_SMS_STATUS structure

## Description

The WWAN_SMS_STATUS structure represents the status of the SMS message store.

## Members

### `uFlag`

A bitmap of flags that represent the status of the message store on the MB device. The values for
**uFlag** are defined in the following table.

| Value | Meaning |
| --- | --- |
| WWAN_SMS_FLAG_NONE | No status to report. |
| WWAN_SMS_FLAG_MESSAGE_STORE_FULL | The message store is full. |
| WWAN_SMS_FLAG_NEW_MESSAGE | A new, non-Class 0 (flash/alert) message has arrived. |

Miniport drivers should not set or clear any flag until a change of state occurs. For example, the
WWAN_SMS_FLAG_MESSAGE_STORE_FULL flag must remain set until the miniport driver completely processes a
delete message request that comes from the MB Service. Similarly, the WWAN_SMS_FLAG_NEW_MESSAGE flag
must remain set until the miniport driver completely processes a read new message request from the MB
Service.

Miniport drivers must send an unsolicited event to the MB Service whenever a flag is set. Miniport
drivers do not need to send an unsolicited event when a flag is cleared (reset).

### `MessageIndex`

This is the index of the newly arrived message or the recently arrived message in case of a
*query* response.

Unique index into the message store between 1 and
**ulMaxMessageIndex** returned in NDIS_STATUS_WWAN_SMS_CONFIGURATION.

If the
**uFlag** is not set with WWAN_SMS_NEW_MESSAGE, this member must be initialized by the miniport driver
with WWAN_MESSAGE_INDEX_NONE.

## See also

[NDIS_WWAN_SMS_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_sms_status)