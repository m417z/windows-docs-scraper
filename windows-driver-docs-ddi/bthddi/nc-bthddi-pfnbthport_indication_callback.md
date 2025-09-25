# PFNBTHPORT_INDICATION_CALLBACK callback function

## Description

Profile drivers implement a L2CAP callback function to provide the Bluetooth driver stack with a
mechanism to notify the profile driver about incoming L2CAP connection requests from remote devices, and
any changes to the status of a currently open L2CAP connection.

## Parameters

### `Context` [in]

For incoming remote connection request indications, this is the context specified by the profile
driver in the
**IndicationCallbackContext** member of the
[_BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_register_server) structure when the profile driver registered the callback function. For
changes to existing L2CAP connections, this is the
**CallbackContext** member specified by the profile driver when it built and sent a
[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel) BRB.

### `Indication` [in]

An
[INDICATION_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_indication_code) value that indicates the type
of L2CAP event.

### `Parameters` [in]

An
[INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters) structure that
contains event-specific parameters.

## Remarks

A profile driver registers its L2CAP callback function in the following two scenarios:

1. When a profile driver acts as a server, it registers a L2CAP callback function using the
   **IndicationCallback** member of the
   [_BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_register_server) structure. The Bluetooth driver stack can then notify the profile
   driver when a remote device attempts to contact it.
2. When the profile driver acts as a client and attempts to connect to a remote device using the
   **BRB_L2CA_OPEN_CHANNEL** BRB, the profile driver registers its L2CAP callback function using the
   **Callback** member of the _BRB_L2CA_OPEN_CHANNEL structure that is passed when the profile driver
   [builds and sends](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
   [BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/previous-versions/ff536615(v=vs.85)) or
   [BRB_L2CA_OPEN_CHANNEL_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85)) request.

After the profile driver registers its L2CAP callback function, the callback function is only
associated with the channel that the BRB opened. The Bluetooth driver stack can call the L2CAP callback
function to notify the profile driver of actions that occur over the open channel to the remote device.
Profile drivers can register a single callback function to handle channel notifications as a client and
connection notifications as a server.

The
[INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters) structure held in
the
*Parameters* parameter is interpreted according to the value of the
[INDICATION_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_indication_code) enumeration that the Bluetooth
driver stack passes to the profile driver's L2CAP callback function through the
*Indication* parameter. For most notifications, there is an INDICATION_PARAMETERS union member that
corresponds to the event and contains event-specific parameters.

## See also

[INDICATION_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_indication_code)

[INDICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters)

[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel)

[_BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_register_server)