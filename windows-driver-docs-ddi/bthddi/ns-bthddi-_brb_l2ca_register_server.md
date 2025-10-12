# _BRB_L2CA_REGISTER_SERVER structure

## Description

A profile driver uses the _BRB_L2CA_REGISTER_SERVER structure to register itself as a server capable
of receiving L2CAP connections from remote Bluetooth devices.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The address of the remote Bluetooth device to receive notifications for. Specify BTH_ADDR_NULL to
receive notification for any incoming connections.

### `PSM`

The Protocol/Service Multiplexer (PSM) that accepts connection requests.

### `IndicationFlags`

An optional flag or combination of flags that indicates whether the profile driver will accept
pairing notifications in addition to connection notifications. The following table lists the possible
flag settings.

| Flag | Description |
| --- | --- |
| INDICATION_PAIR_DEVICE | The profile driver will accept notifications when a device is paired. |
| INDICATION_UNPAIR_DEVICE | The profile driver will accept notifications when a device is unpaired. |
| INDICATION_UNPERSONALIZE_DEVICE | The profile driver will accept notifications when a device is unpersonalized. |

### `IndicationCallback`

A
[L2CAP Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbthport_indication_callback),
implemented by the profile driver, that the Bluetooth driver stack should call to notify the profile
driver about incoming L2CAP connections.

### `IndicationCallbackContext`

The context to be passed to the callback function that is specified in the
**IndicationCallback** member.

### `ReferenceObject`

A pointer to an object to pass to the
[ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject) and
[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) functions to
maintain a reference count. Profile drivers should provide this object in such a way that the Bluetooth
driver stack can increase the count of the object for as long as the driver stack can call the callback
function specified in the
**IndicationCallback** member. The Bluetooth driver stack will decrease the reference count of the
object when the profile driver
[builds and sends](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_L2CA_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_unregister_server) request.

### `ServerHandle`

Handle to the L2CAP server, if successfully returned. When the profile driver should no longer
receive remote connect indications it should pass this handle to
[BRB_L2CA_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_unregister_server).

## Remarks

To register itself as a L2CAP server, a profile driver should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536618(v=vs.85)) request.

After the profile driver registers itself, it should then
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_REGISTER_PSM](https://learn.microsoft.com/previous-versions/ff536621(v=vs.85)) request so the Bluetooth
driver stack will accept connections from the PSM.

If successful, the Bluetooth driver stack can then notify the profile driver when remote devices
attempt to create a L2CAP connection to the profile driver on a particular PSM.

A profile driver can specify zero the
**Psm** member of the _BRB_L2CA_REGISTER_SERVER structure--which means that the PSM is unspecified--and
the profile driver will subsequently issue a **BRB_REGISTER_PSM** BRB to obtain a dynamic PSM to register for
connection notifications. For more information about PSMs, see
[_BRB_PSM](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_psm).

After the profile driver has registered itself, the Bluetooth driver stack can notify it when a remote
device attempts to connect to it by calling the
[L2CAP Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbthport_indication_callback) that the
profile driver implements and specifies in the
**IndicationCallback** member.

For more information about L2CAP servers and PSMs, see
[Accepting
L2CAP Connections in a Bluetooth Profile Driver](https://learn.microsoft.com/previous-versions/ff536572(v=vs.85)).

When the profile driver receives notification of a connection attempt, it should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_L2CA_OPEN_CHANNEL_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85)) BRB to either accept or reject the connection attempt. For more
information about accepting or rejecting L2CAP connection attempts, see the
[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel) structure.

After a connection is established, the profile driver can issue other BRBs to communicate with the
remote device.

To stop receiving remote connection notifications, a profile driver should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_L2CA_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_unregister_server) request.

While this procedure allows a profile driver to accept incoming connection requests, it does not
automatically advertise a service using SDP. To advertise a service using SDP, a profile driver must
submit an SDP record using the SDP APIs. For more information about advertising services with SDP, see
[Communicating with SDP
Servers](https://learn.microsoft.com/previous-versions/ff536671(v=vs.85)).

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536618(v=vs.85))

[BRB_L2CA_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_unregister_server)

[L2CAP Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbthport_indication_callback)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject)