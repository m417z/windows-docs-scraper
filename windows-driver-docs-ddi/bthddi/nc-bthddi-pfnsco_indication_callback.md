# PFNSCO_INDICATION_CALLBACK callback function

## Description

Profile drivers implement a SCO callback function to provide the Bluetooth driver stack with a
mechanism to notify the profile driver about incoming SCO connection requests from remote devices, and any
changes to the status of a currently open SCO connection.

## Parameters

### `Context` [in]

For incoming remote connection request indications, this is the context specified by the profile
driver in the
**IndicationCallbackContext** member of the
[_BRB_SCO_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_register_server) structure
when the profile driver registered the callback function. For changes to existing SCO connections, this
is the
**CallbackContext** member specified by the profile driver when it built and sent a
[BRB_SCO_OPEN_CHANNEL](https://learn.microsoft.com/previous-versions/ff536626(v=vs.85)) BRB.

### `Indication` [in]

A
[SCO_INDICATION_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_sco_indication_code) value that indicates
the type of SCO event.

### `Parameters` [in]

A
[SCO_INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_sco_indication_parameters) structure that contains parameter information based on the value passed
to the
*Indication* parameter.

## Remarks

The
**BtAddress** member found in the SCO_INDICATION_PARAMETERS structure passed in the
*Parameters* parameter indicates the Bluetooth address of the remote device.

The
*PFNSCO_INDICATION_CALLBACK* function can be registered in two ways.

In the first case, the profile driver acts as a server and must register this callback function
through the
**IndicationCallback** member of the
[_BRB_SCO_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_register_server) structure.
The Bluetooth driver stack can then call this function to notify the profile driver when a remote device
attempts to contact it.

In the second case, the profile driver acts as a client and attempts to connect to a remote device
using the **BRB_SCO_OPEN_CHANNEL** BRB. The
*PFNSCO_INDICATION_CALLBACK* callback function is registered through the
**Callback** member of the
[_BRB_SCO_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_open_channel) structure passed
with the specified BRB when one of them is submitted through
[IOCTL_INTERNAL_BTH_SUBMIT_BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_internal_bth_submit_brb).

After it is registered, the callback function is only associated with the channel that the BRB opened,
and the function notifies the profile driver of actions that occur over the open channel to the remote
device. Profile drivers can register a single function to handle channel notifications as a client and
_BRB_SCO_REGISTER_SERVER notifications as a server.

The SCO_INDICATION_PARAMETERS structure held in the
*Parameters* parameter is interpreted according to the SCO_INDICATION_CODE value that is passed to
the callback function through the
*Indication* parameter. For most notifications, there is a SCO_INDICATION_PARAMETERS union member
that corresponds to the event and contains event-specific parameters.

## See also

[BRB_SCO_OPEN_CHANNEL](https://learn.microsoft.com/previous-versions/ff536626(v=vs.85))

[IOCTL_INTERNAL_BTH_SUBMIT_BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_internal_bth_submit_brb)

[SCO_INDICATION_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_sco_indication_code)

[SCO_INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_sco_indication_parameters)

[_BRB_SCO_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_register_server)