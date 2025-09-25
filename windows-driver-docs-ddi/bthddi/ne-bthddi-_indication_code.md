# _INDICATION_CODE enumeration

## Description

The INDICATION_CODE enumeration type indicates to a profile driver what type of L2CAP event has
occurred.

## Constants

### `IndicationAddReference`

Indicates to a profile driver to add a reference to its device object because it may be called at
any time.

### `IndicationReleaseReference`

Indicates to a profile driver to release a reference to its device object and that it will no
longer be called.

### `IndicationRemoteConnect`

Indicates to a server profile driver that a remote device is connecting to the PSM that the
profile driver registered earlier. Profile drivers accept or reject this request by
[building and sending](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_L2CA_OPEN_CHANNEL_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85)) request. When this indication code is passed, the profile driver
should use the parameters that are passed to it in the
**Connect** member of the
[INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters) structure.

### `IndicationRemoteDisconnect`

Indicates to a registered profile driver that a remote device disconnecting from the local radio.
When this indication code is passed, the profile driver should use the parameters that are passed to it
in the
**Disconnect** member of the INDICATION_PARAMETERS structure.

### `IndicationRemoteConfigRequest`

Indicates to a client profile driver that a remote device is performing a configuration request.
When this indication code is passed, the profile driver should use the parameters that are passed to it
in the
**ConfigRequest** member of the INDICATION_PARAMETERS structure.

### `IndicationRemoteConfigResponse`

Indicates to a client profile driver that a remote device is responding to a configuration
request. When this indication code is passed, the profile driver should use the parameters that are
passed to it in the
**ConfigResponse** member of the INDICATION_PARAMETERS structure.

### `IndicationFreeExtraOptions`

Reserved for future use. Do not use.

### `IndicationRecvPacket`

Indicates to a registered profile driver that a packet has been received on the specified PSM. The
profile driver can use this event to determine when it is necessary to issue a read
BRB_L2CA_ACL_TRANSFTER BRB. Profile drivers that need to read from the remote device can also ignore
this notification and keep a read BRB pending at all times. When this indication code is passed, the
profile driver should use the parameters that are passed to it in the
**RecvPacket** member of the
[INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters) structure.

### `IndicationPairDevice`

Indicates to a registered driver that the local radio has bonded to a specific remote
radio.

### `IndicationUnpairDevice`

Indicates to a registered driver that the local radio is no longer bonded to a specific remote
radio.

### `IndicationUnpersonalizeDevice`

Indicates to a registered driver that the specified remote radio has been removed from the list of
personal devices.

### `IndicationRemoteConnectLE`

Indicates to a server profile driver that a low energy (LE) remote device is connecting to the PSM that the
profile driver registered earlier. Profile drivers accept or reject this request by
[building and sending](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_L2CA_OPEN_CHANNEL_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85)) request. When this indication code is passed, the profile driver
should use the parameters that are passed to it in the
**Connect** member of the
[INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters) structure. This value is present in Windows 8 and later versions of Windows.

## Remarks

A value from this enumeration is passed to a profile driver's
[L2CAP Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbthport_indication_callback) to notify
it of an event.

## See also

[BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536618(v=vs.85))

[INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters)

[IOCTL_INTERNAL_BTH_SUBMIT_BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_internal_bth_submit_brb)

[L2CAP Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbthport_indication_callback)