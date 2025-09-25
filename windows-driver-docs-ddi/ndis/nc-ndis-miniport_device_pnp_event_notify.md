# MINIPORT_DEVICE_PNP_EVENT_NOTIFY callback function

## Description

NDIS calls a miniport driver's
*MiniportDevicePnPEventNotify* function to notify the driver of Plug and Play
(PnP) events.

**Note** You must declare the function by using the **MINIPORT_DEVICE_PNP_EVENT_NOTIFY** type.
For more information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

### `NetDevicePnPEvent` [in]

A pointer to a
[NET_DEVICE_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_device_pnp_event) structure that
describes a device Plug and Play event.

## Remarks

A driver specifies the
*MiniportDevicePnPEventNotify* entry point when it calls the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

NDIS calls the driver's
*MiniportDevicePnPEventNotify* function with the
**DevicePnPEvent** member of the
*NetDevicePnPEvent* parameter set to
**NdisDevicePnPEventPowerProfileChanged** after one of the following events:

* Driver initialization is complete.
* The driver received an
  [OID_PNP_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-set-power) notification that
  specifies the powered-on state (
  **NdisDeviceStateD0**).

In the second case, the value at
*InformationBuffer* indicates whether the system is running on battery power (**NdisPowerProfileBattery**) or AC power (**NdisPowerProfileAcOnline**). A driver can use this information to adjust the power consumption of
the specified miniport adapter. For example, the driver for a wireless LAN device could reduce power
consumption if the system is running on battery power or increase power consumption if the system is
running on AC power.

When a driver receives a surprise removal notification (the
**DevicePnPEvent** member of the
*NetDevicePnPEvent* parameter is
**NdisDevicePnPEventSurpriseRemoved**), it should:

* Note internally that the device has been removed.
* Cancel any pending IRPs that it sent down to the underlying bus driver.

After NDIS calls the
*MiniportDevicePnPEventNotify* function to indicate a surprise removal, NDIS
calls the driver's
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function. If the driver
receives any send requests or OID requests before NDIS calls
*MiniportHaltEx*, it should immediately complete such requests with a status
value of NDIS_STATUS_NOT_ACCEPTED.

NDIS calls
*MiniportDevicePnPEventNotify* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *MiniportDevicePnPEventNotify* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportDevicePnPEventNotify* function that is named "MyDevicePnPEventNotify", use the **MINIPORT_DEVICE_PNP_EVENT_NOTIFY** type as shown in this code example:

```
MINIPORT_DEVICE_PNP_EVENT_NOTIFY MyDevicePnPEventNotify;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyDevicePnPEventNotify(
    NDIS_HANDLE  MiniportAdapterContext,
    PNET_DEVICE_PNP_EVENT  NetDevicePnPEvent
    )
  {...}
```

The **MINIPORT_DEVICE_PNP_EVENT_NOTIFY** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_DEVICE_PNP_EVENT_NOTIFY** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NET_DEVICE_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_device_pnp_event)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[OID_PNP_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-set-power)