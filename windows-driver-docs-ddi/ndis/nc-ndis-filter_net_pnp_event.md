# FILTER_NET_PNP_EVENT callback function

## Description

NDIS calls a filter driver's
*FilterNetPnPEvent* function to notify the driver of network Plug and Play (PnP)
and Power Management events.

**Note** You must declare the function by using the **FILTER_NET_PNP_EVENT** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module. The filter driver created and initialized this
context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetPnPEventNotification` [in]

A pointer to a
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification) structure, which describes the PnP event or Power Management event
being indicated to the filter driver.

## Return value

*FilterNetPnPEvent* can return either of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The driver successfully processed the PnP event. |
| **NDIS_STATUS_FAILURE** | The driver failed the PnP event. |

The return value is significant only when the propagated event is a
**NetEventQueryPower** or a
**NetEventQueryRemove** event. For all other propagated events, the return
value is always NDIS_STATUS_SUCCESS.

## Remarks

*FilterNetPnPEvent* is an optional function. If a filter driver does not handle
network PnP events, it can set the entry point for this function to **NULL** when it calls the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function.

*FilterNetPnPEvent* is similar to a protocol driver's
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function. A
filter driver can forward these notifications to overlying drivers or it can handle them itself and not
forward them. To forward a notification, call the
[NdisFNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfnetpnpevent) function. Do not confuse
this function with the
[FilterDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_device_pnp_event_notify) function, which filters notifications that are directed down the stack
to underlying drivers.

NDIS calls
*FilterNetPnPEvent* to notify a filter driver of a PnP or Power Management event
that was issued for an underlying NIC. NDIS calls the
*FilterNetPnPEvent* function of each filter driver overlying a NIC, and then
calls the
*ProtocolNetPnPEvent* function of each overlying protocol driver.

When a filter module is inserted into or deleted from a driver stack, the characteristics of the stack
might change. NDIS sends a PnP event to all affected protocol bindings and filter modules to notify them
about this change. Filter drivers should handle such changes appropriately.

NDIS calls
*FilterNetPnPEvent* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *FilterNetPnPEvent* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterNetPnPEvent* function that is named "MyNetPnPEvent", use the **FILTER_NET_PNP_EVENT** type as shown in this code example:

```
FILTER_NET_PNP_EVENT MyNetPnPEvent;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyNetPnPEvent(
    NDIS_HANDLE  FilterModuleContext,
    PNET_PNP_EVENT_NOTIFICATION  NetPnPEvent
    )
  {...}
```

The **FILTER_NET_PNP_EVENT** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_NET_PNP_EVENT** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_device_pnp_event_notify)

[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification)

[NdisFNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfnetpnpevent)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event)