# FWPS_VSWITCH_PORT_EVENT_CALLBACK0 callback function

## Description

The filter engine calls the *vSwitchPortEventNotifyFn* (*FWPS_VSWITCH_PORT_EVENT_CALLBACK0*) callout function to notify the callout driver about events that are
associated a virtual switch (vSwitch) port.

**Note** *FWPS_VSWITCH_PORT_EVENT_CALLBACK0* is a specific version of *FWPS_VSWITCH_PORT_EVENT_CALLBACK*. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `notifyContext` [in, optional]

A pointer to a context provided by the callout driver. The driver passed this pointer to the *notifyContext* parameter of the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)
function. This parameter is optional and can be NULL.

### `completionContext` [in]

A pointer to a completion context provided by the callout driver. This parameter is optional and can be NULL.

### `eventType` [in]

The type of virtual switch vSwitch event specified as one of the [FWPS_VSWITCH_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_vswitch_event_type_) enumeration values. For more information, see Remarks.

### `vSwitch` [in]

A pointer to an [NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters) structure that contains information about a virtual switch.

**Note** The information in the [NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters) structure reflects the initial state of the virtual switch, not necessarily its current state. In particular, the **NumSwitchPorts** and **IsActive** members might still have their initial value of zero, unless a virtual switch PnP event has been triggered. Current state information can be found in the other parameters to this callback function.

### `vSwitchPort` [in]

A pointer to an [NDIS_SWITCH_PORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_parameters) structure that contains parameters for a port on a vSwitch.

## Return value

A callout's
*FWPS_VSWITCH_PORT_EVENT_CALLBACK0* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout driver accepts the notification from the filter engine. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The callout driver will call the [FwpsvSwitchNotifyComplete0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitchnotifycomplete0) function to complete the pending operation. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver registers a *vSwitchPortEventNotifyFn* function by calling the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)
function.

If the *vSwitchPortEventNotifyFn* callback is registered, the callout driver receives notifications for port creation and deletion.

If the *eventType* parameter is set to FWPS_VSWITCH_EVENT_PORT_CREATE, a vSwitch port was created.
In this case, the *vSwitch* parameter identifies an [NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters) structure that contains information about the virtual switch (vSwitch) and the [NDIS_SWITCH_PORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_parameters) parameter contains information about the port.

A callout can return STATUS_PENDING from *vSwitchPortEventNotifyFn*. In this case, the callout driver calls the [FwpsvSwitchNotifyComplete0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitchnotifycomplete0) function to complete the pending operation.

After the port is deleted, the WFP filter driver calls *vSwitchPortEventNotifyFn* with FWPS_VSWITCH_EVENT_PORT_DELETE set in the *eventType* parameter.

## See also

[Callout Driver Callout Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[FWPS_VSWITCH_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_vswitch_event_type_)

[FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)

[FwpsvSwitchNotifyComplete0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitchnotifycomplete0)

[NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters)

[NDIS_SWITCH_PORT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_parameters)