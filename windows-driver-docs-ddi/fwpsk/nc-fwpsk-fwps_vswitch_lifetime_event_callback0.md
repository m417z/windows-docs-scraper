# FWPS_VSWITCH_LIFETIME_EVENT_CALLBACK0 callback function

## Description

The filter engine calls the *vSwitchLifetimeNotifyFn* (*FWPS_VSWITCH_LIFETIME_EVENT_CALLBACK0*) callout function to notify the callout driver about create and delete events for a virtual switch.

**Note** *FWPS_VSWITCH_LIFETIME_EVENT_CALLBACK0* is a specific version of *FWPS_VSWITCH_LIFETIME_EVENT_CALLBACK*. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `notifyContext` [in, optional]

A pointer to a context supplied by the callout driver. The driver passed this pointer to the *notifyContext* parameter of the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)
function. This parameter is optional and can be NULL.

### `eventType` [in]

The type of virtual switch event specified as one of the [FWPS_VSWITCH_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_vswitch_event_type_) enumeration values. For more information, see Remarks.

### `vSwitch` [in]

A pointer to an [NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters) structure that contains information about a virtual switch.

**Note** The information in the [NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters) structure reflects the initial state of the virtual switch, not necessarily its current state. In particular, the **NumSwitchPorts** and **IsActive** members might still have their initial value of zero, unless a virtual switch PnP event has been triggered. Current state information can be found in the other parameters to this callback function.

### `vSwitchPorts` [in, optional]

A pointer to an [NDIS_SWITCH_PORT_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_array) structure that specifies an array of port configuration parameters. Each element in the array specifies the parameters for a port on a virtual switch.

### `vSwitchInterfaces` [in, optional]

A pointer to an [NDIS_SWITCH_NIC_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_array) structure that specifies an array of miniport adapter configuration parameters. Each element in the array specifies the parameters for a virtual or physical miniport adapter that is attached to a port on a virtual switch.

## Return value

A callout's
*FWPS_VSWITCH_LIFETIME_EVENT_CALLBACK0* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout driver accepts the notification from the filter engine. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver registers a *vSwitchLifetimeNotifyFn* callback function by calling
the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)
function.

If the *vSwitchLifetimeNotifyFn* callback is registered, the WFP filter driver notifies the callout driver when a virtual switch instance is created. Multiple instances of a virtual switch can be present in a Hyper-V host at the same time.

The WFP filter driver queries the [OID_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-parameters) OID in the [FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart) function to obtain the virtual switch identifier that is associated with the current instance of the virtual switch. The WFP filter driver also queries the [OID_SWITCH_NIC_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-array) and [OID_SWITCH_PORT_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-array) OIDs to obtain the initial set of configured virtual NICs and virtual ports. The WFP filter driver passes the [NDIS_SWITCH_PORT_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_array) and [NDIS_SWITCH_NIC_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_array) structure information from the OIDs to *vSwitchLifetimeNotifyFn* with FWPS_VSWITCH_EVENT_VSWITCH_CREATE set in the *eventType* parameter.

In the WFP filter driver's [FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach), the filter calls with FWPS_VSWITCH_EVENT_VSWITCH_DELETE set in the *eventType**vSwitchLifetimeNotifyFn* parameter.

A callout driver cannot return STATUS_PENDING from *vSwitchLifetimeNotifyFn*.

## See also

[Callout Driver Callout Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[FWPS_VSWITCH_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_vswitch_event_type_)

[FWPS_VSWITCH_PORT_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_port_event_callback0)

[FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach)

[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart)

[FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)

[FwpsvSwitchNotifyComplete0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitchnotifycomplete0)

[NDIS_SWITCH_NIC_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_array)

[NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters)

[NDIS_SWITCH_PORT_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_array)

[NdisFRestartComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfrestartcomplete)

[OID_SWITCH_NIC_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-array)

[OID_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-parameters)

[OID_SWITCH_PORT_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-array)