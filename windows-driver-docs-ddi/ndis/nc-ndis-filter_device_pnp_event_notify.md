# FILTER_DEVICE_PNP_EVENT_NOTIFY callback function

## Description

NDIS calls a filter driver's
*FilterDevicePnPEventNotify* function to notify the driver of device Plug and Play (PnP) and Power
Management events.

**Note** You must declare the function by using the **FILTER_DEVICE_PNP_EVENT_NOTIFY** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module. The filter driver created and initialized this
context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `NetDevicePnPEvent` [in]

A pointer to a
[NET_DEVICE_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_device_pnp_event) structure that
describes a device Plug and Play event.

## Remarks

*FilterDevicePnPEventNotify* is an optional function. If a filter driver does not use device PnP
requests, it can set the entry point for this function to **NULL** when it calls the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function.

*FilterDevicePnPEventNotify* is similar to a miniport driver's
[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify) function. Filter drivers can forward these notifications to underlying
drivers. To forward a request, call the
[NdisFDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdevicepnpeventnotify) function.

NDIS calls
*FilterDevicePnPEventNotify* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *FilterDevicePnPEventNotify* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterDevicePnPEventNotify* function that is named "MyDevicePnPEventNotify", use the **FILTER_DEVICE_PNP_EVENT_NOTIFY** type as shown in this code example:

```
FILTER_DEVICE_PNP_EVENT_NOTIFY MyDevicePnPEventNotify;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyDevicePnPEventNotify(
    NDIS_HANDLE  FilterModuleContext,
    PNET_DEVICE_PNP_EVENT  NetDevicePnPEvent
    )
  {...}
```

The **FILTER_DEVICE_PNP_EVENT_NOTIFY** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_DEVICE_PNP_EVENT_NOTIFY** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify)

[NET_DEVICE_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_device_pnp_event)

[NdisFDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfdevicepnpeventnotify)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisWriteEventLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteeventlogentry)