# _BRB_SCO_REGISTER_SERVER structure

## Description

A profile driver uses the _BRB_SCO_REGISTER_SERVER structure to register itself as a server capable
of receiving SCO connections from remote Bluetooth devices.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The address of the remote Bluetooth device for which to receive notifications.

### `Reserved`

Reserved for future use. Do not use.

### `IndicationFlags`

A flag that indicates when the callback function that is specified in the
**IndicationCallback** member should be called. The following flags are defined.

|  |  |
| --- | --- |
| **Flag** | **Description** |
| SCO_INDICATION_SCO_REQUEST | Notify the profile driver if there are any incoming SCO connections. |
| SCO_INDICATION_ESCO_REQUEST | Notify the profile driver if there are any incoming eSCO connections. |

### `IndicationCallback`

A
[SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback), implemented
by the profile driver, that the Bluetooth driver stack should call to notify the profile driver about
incoming SCO connections.

### `IndicationCallbackContext`

The context passed to the function that is defined in the
**IndicationCallback** member.

### `ReferenceObject`

A pointer to an object to pass to the
[ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject) and
[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) functions to
maintain a reference count of. Profile drivers should provide this object in such a way that the
Bluetooth driver stack can increase the count of the object for as long as the driver stack can call the
callback function specified in the
**IndicationCallback** member. The Bluetooth driver stack will decrease the reference count of the
object when the profile driver
[builds and sends](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_SCO_UNREGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536630(v=vs.85)) request.

### `ServerHandle`

Handle to the SCO server, if successfully returned. When the profile driver should no longer
receive remote connect indications it should pass this handle to
[BRB_SCO_UNREGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536630(v=vs.85)).

## Remarks

To register itself as a SCO server, a profile driver should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_SCO_REGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536628(v=vs.85)) request.

If successful, the Bluetooth driver stack can then notify the profile driver when remote devices
attempt to create a SCO connection to the profile driver.

After the profile driver has registered itself, the Bluetooth driver stack can notify it when a remote
device attempts to connect to it by calling the
[SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback) that the
profile driver implements and specifies in the
**IndicationCallback** member.

When the profile driver receives notification of a connection attempt, it should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_SCO_OPEN_CHANNEL_RESPONSE](https://social.msdn.microsoft.com/Forums/0a9a4323-d046-4d27-9d22-4974dbab30a4/home?forum=windows-bluetooth-sco-brbscoopenchannelresponse) request to either accept or reject the connection attempt. For more
information about accepting or rejecting SCO connection attempts, see the
[_BRB_SCO_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_open_channel) structure.

After a connection is established, the profile driver can issue other BRBs to communicate with the
remote device.

To stop receiving remote connection notifications, a profile driver should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_SCO_UNREGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536630(v=vs.85)) request.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_SCO_REGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536628(v=vs.85))

[BRB_SCO_UNREGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536630(v=vs.85))

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject)

[SCO Callback Function](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnsco_indication_callback)