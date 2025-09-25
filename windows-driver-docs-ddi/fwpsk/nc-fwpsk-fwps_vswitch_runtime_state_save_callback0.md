# FWPS_VSWITCH_RUNTIME_STATE_SAVE_CALLBACK0 callback function

## Description

The filter engine calls the *vSwitchRuntimeStateSaveNotifyFn* (*FWPS_VSWITCH_RUNTIME_STATE_SAVE_CALLBACK0*) callout function to notify a callout driver about virtual switch run-time state save events.

> [!NOTE]
> *FWPS_VSWITCH_RUNTIME_STATE_SAVE_CALLBACK0* is a specific version of *FWPS_VSWITCH_RUNTIME_STATE_SAVE_CALLBACK*. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

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

> [!NOTE]
> The information in the [NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters) structure reflects the initial state of the virtual switch, not necessarily its current state. In particular, the **NumSwitchPorts** and **IsActive** members might still have their initial value of zero, unless a virtual switch PnP event has been triggered. Current state information can be found in the other parameters to this callback function.

### `portId` [in]

The source switch port identifier.

### `runtimeStateLength` [out]

The length, in bytes, of the run-time state information in the run-time state buffer.

### `runtimeState`

The location of the run-time state output result buffer.

## Return value

A callout's *FWPS_VSWITCH_RUNTIME_STATE_SAVE_CALLBACK0* function returns one of the following NTSTATUS codes.

|Return code|Description|
|--- |--- |
|**STATUS_SUCCESS**|The callout driver accepts the notification from the filter engine.|
|**STATUS_PENDING**|The operation is pending and will be completed later. The callout driver will call the [FwpsvSwitchNotifyComplete0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitchnotifycomplete0) function to complete the pending operation.|
|**Other status codes**|An error occurred.|

## Remarks

A callout driver registers a *vSwitchRuntimeStateSaveNotifyFn* function by calling the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)
function.

If the *vSwitchRuntimeStateSaveNotifyFn* callback is registered, the callout will be notified to retrieve a source VM’s run-time state and to restore a target VM’s run-time state during live migration or a local save and restore operation. In the save case, the *eventType* parameter of *vSwitchRuntimeStateSaveNotifyFn* is set to FWPS_VSWITCH_EVENT_RUNTIME_STATE_SAVE.

The virtual switch extension protocol driver issues an object identifier (OID) method request of [OID_SWITCH_NIC_SAVE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-save) during an operation to save run-time data for a virtual switch port. The filter driver returns this data so that run-time data for a virtual switch port can be saved and restored at a later time.

After the run-time data blob from all callouts are collected, WFP fills the [NDIS_SWITCH_NIC_SAVE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_save_state) structure with the harvested data and completes the save state request.

A callout can return STATUS_PENDING from *vSwitchRuntimeStateSaveNotifyFn*. In this case, WFP will return STATUS_PENDING in the [FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) handler and will complete it at a later time. The callout driver will call the [FwpsvSwitchNotifyComplete0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitchnotifycomplete0) function to complete the pending operation.

See the *vSwitchRuntimeStateRestoreNotifyFn* ([FWPS_VSWITCH_RUNTIME_STATE_RESTORE_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_runtime_state_restore_callback0)) function for information about restoring the run-time state.

## See also

[Callout Driver Callout Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[FWPS_VSWITCH_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_vswitch_event_type_)

[FWPS_VSWITCH_RUNTIME_STATE_RESTORE_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_runtime_state_restore_callback0)

[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request)

[FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)

[FwpsvSwitchNotifyComplete0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitchnotifycomplete0)

[NDIS_SWITCH_NIC_SAVE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_nic_save_state)

[NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters)

[OID_SWITCH_NIC_SAVE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-save)