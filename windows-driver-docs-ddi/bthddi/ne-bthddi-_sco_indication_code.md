# _SCO_INDICATION_CODE enumeration

## Description

The SCO_INDICATION_CODE enumeration type describes the type of an incoming SCO connection or bonding
state change. The Bluetooth driver stack passes a value from this enumeration in the
*Indication* argument of a profile driver's
[SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback).

## Constants

### `ScoIndicationAddReference`

This value indicates that the profile driver should add one reference to its device object.

### `ScoIndicationReleaseReference`

This value indicates that the profile driver can release one reference to its device
object.

### `ScoIndicationRemoteConnect`

This value indicates to a profile driver that a remote device is trying to connect to the local
radio. Profile drivers accept or reject this request by
[building and sending](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_SCO_OPEN_CHANNEL_RESPONSE](https://social.msdn.microsoft.com/Forums/0a9a4323-d046-4d27-9d22-4974dbab30a4/home?forum=windows-bluetooth-sco-brbscoopenchannelresponse) request.

### `ScoIndicationRemoteDisconnect`

This value indicates to a profile driver that a remote device is disconnecting from the local
radio.

## See also

[BRB_SCO_REGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536628(v=vs.85))

[IOCTL_INTERNAL_BTH_SUBMIT_BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_internal_bth_submit_brb)

[SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback)