# FWPS_VSWITCH_INTERFACE_EVENT_CALLBACK0 callback function

## Description

The filter engine calls the *vSwitchInterfaceEventNotifyFn* (*FWPS_VSWITCH_INTERFACE_EVENT_CALLBACK0*) callout function to notify the callout driver about events that are associated the virtual switch interface.

**Note** *FWPS_VSWITCH_INTERFACE_EVENT_CALLBACK0* is a specific version of *FWPS_VSWITCH_INTERFACE_EVENT_CALLBACK*. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `notifyContext` [in, optional]

A pointer to a context provided by the callout driver. The driver passed this pointer to the *notifyContext* parameter of the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)
function. This parameter is optional and can be NULL.

### `completionContext` [in]

A pointer to a completion context provided by the callout driver. This parameter is optional and can be NULL.

### `eventType` [in]

The type of virtual switch event specified as one of the [FWPS_VSWITCH_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_vswitch_event_type_) enumeration values. For more information, see Remarks.

### `vSwitch` [in]

A pointer to an [NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters) structure that contains information about a virtual switch.

**Note** The information in the [NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters) structure reflects the initial state of the virtual switch, not necessarily its current state. In particular, the **NumSwitchPorts** and **IsActive** members might still have their initial value of zero, unless a virtual switch PnP event has been triggered. Current state information can be found in the other parameters to this callback function.

### `vSwitchNic` [in]

A pointer to an [NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters) structure that specifies the parameters for a virtual miniport adapter that is connected to a virtual switch port.

## Return value

A callout's
*FWPS_VSWITCH_INTERFACE_EVENT_CALLBACK0* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout driver accepts the notification from the filter engine. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver registers a
*vSwitchInterfaceEventNotifyFn* function by calling
the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)
function.

If the *eventType* parameter is set to WPS_VSWITCH_EVENT_INTERFACE_CREATE, a new network connection between a virtual switch port and a network adapter is completely established. The *vSwitchNic* parameter identifies an [NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters) structure that contains information about the virtual network adapter that is connected to the virtual switch port.

 If the *eventType* parameter is FWPS_VSWITCH_EVENT_INTERFACE_DISCONNECT, the connection between a virtual switch port and a network adapter is being torn down. After the connection has been completely torn down, the WFP filter driver will call *vSwitchInterfaceEventNotifyFn* with FWPS_VSWITCH_EVENT_INTERFACE_DELETE set in the *eventType* parameter.

## See also

[Callout Driver Callout Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[FWPS_VSWITCH_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_vswitch_event_type_)

[FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)

[NDIS_SWITCH_NIC_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_parameters)

[NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters)