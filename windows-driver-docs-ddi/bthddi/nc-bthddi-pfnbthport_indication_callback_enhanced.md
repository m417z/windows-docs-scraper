# PFNBTHPORT_INDICATION_CALLBACK_ENHANCED callback function

## Description

Profile drivers implement an enhanced L2CAP callback function to provide the Bluetooth driver stack with a
mechanism to notify the profile driver about any changes to the status of a currently open L2CAP or eL2CAP connection.

## Parameters

### `Context` [in]

For
changes to existing L2CAP connections, this is the
**CallbackContext** member specified by the profile driver when it built and sent a
[_BRB_L2CA_OPEN_ENHANCED_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_enhanced_channel) structure.

### `Indication` [in]

An
[INDICATION_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_indication_code) value that indicates the type
of L2CAP event.

### `Parameters` [in]

An
[INDICATION_PARAMETERS_ENHANCED](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters_enhanced) structure that
contains event-specific parameters.

## Remarks

A profile driver registers its L2CAP or eL2CAP callback function by specifying the callback function in the
**Callback** member of the _BRB_L2CA_OPEN_ENHANCED_CHANNEL structure when the profile driver attempts to connect to a remote device using the
BRB_L2CA_OPEN_ENHANCED_CHANNEL or BRB_L2CA_OPEN_ENHANCED_CHANNEL_RESPONSE BRBs.

After the profile driver registers its L2CAP callback function, the callback function is only
associated with the enhanced channel that the BRB opened. The Bluetooth driver stack can call the L2CAP callback
function to notify the profile driver of actions that occur over the open enhanced channel to the remote device.
Profile drivers can register a single callback function to handle L2CAP channel notifications as a client.

The
[INDICATION_PARAMETERS_ENHANCED](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_indication_parameters_enhanced) structure held in
the
*Parameters* parameter is interpreted according to the value of the
[INDICATION_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_indication_code) enumeration that the Bluetooth
driver stack passes to the profile driver's enhanced L2CAP callback function through the
*Indication* parameter. For most notifications, there is an INDICATION_PARAMETERS_ENHANCED union member that
corresponds to the event and contains event-specific parameters.