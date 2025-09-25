# FWPS_VSWITCH_POLICY_EVENT_CALLBACK0 callback function

## Description

The filter engine calls the *vSwitchPolicyEventNotifyFn* (*FWPS_VSWITCH_POLICY_EVENT_CALLBACK0*) callout function to notify the callout driver about virtual switch policy events.

**Note** *FWPS_VSWITCH_POLICY_EVENT_CALLBACK0* is a specific version of *FWPS_VSWITCH_POLICY_EVENT_CALLBACK*. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

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

### `vSwitchPortProperty` [in, optional]

A pointer to an [NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters) structure. The virtual switch port property.

### `vSwitchPortPropertyDelete` [in, optional]

A pointer to an [NDIS_SWITCH_PORT_PROPERTY_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_delete_parameters) structure. The virtual switch port property.

## Return value

A callout's
*FWPS_VSWITCH_POLICY_EVENT_CALLBACK0* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout driver accepts the notification from the filter engine. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The callout driver will call the [FwpsvSwitchNotifyComplete0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitchnotifycomplete0) function to complete the pending operation. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver registers a *vSwitchPolicyEventNotifyFn* function by calling the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)
function.

If the *vSwitchPolicyEventNotifyFn* callback is registered, the callout on the target host will be notified about the policy configured for the virtual switch port during live migration and before the migrating VM can run on the new host.

Without live migration, *vSwitchPolicyEventNotifyFn* will also be invoked for a VM save operation.

Changes to vendor filtering policies that are configured through the VMMS WMI interface are passed to the WFP virtual switch extension with OID requests. These OIDs carry a [NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters) structure with the **PropertyType** member set to the **NdisSwitchPortPropertyTypeCustom** type.

The WFP filter driver passes the information in the [OID_SWITCH_PORT_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-add) OID request to *vSwitchPolicyEventNotifyFn* with the FWPS_VSWITCH_EVENT_POLICY_ADD type set in the *eventType* parameter to notify callout drivers about the addition of a policy property for a virtual switch port.

The WFP filter driver passes the information in the [OID_SWITCH_PORT_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-update) OID request to *vSwitchPolicyEventNotifyFn* with the FWPS_VSWITCH_EVENT_POLICY_UPDATE type set in the *eventType* parameter to notify callout filter drivers about the update of a property for a virtual switch port policy.

These OIDs also include a property identifier GUID that uniquely identifies which WFP provider the policy belongs to. The property identifier GUID is provided when an vendor configures its policy through VMMS, and the GUID must be the same GUID the vendor uses to register its provider with WFP.

WFP attempts to match the property identifier GUID with the provider GUID specified from the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0) function. If there is a match, WFP invokes the corresponding *vSwitchPolicyEventNotifyFn* and passes the [NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters) structure to the callout.

The WFP filter driver passes the information in the [OID_SWITCH_PORT_PROPERTY_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-delete) OID request to *vSwitchPolicyEventNotifyFn* with the FWPS_VSWITCH_EVENT_POLICY_DELETE type set in the *eventType* parameter to notify callout filter drivers about the deletion of a policy property for a virtual switch port. The delete properties are specified in the [NDIS_SWITCH_PORT_PROPERTY_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_delete_parameters) structure.

If the callout returns STATUS_PENDING from *vSwitchPolicyEventNotifyFn*, WFP returns STATUS_PENDING to the [FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) handler. The callout driver will call the [FwpsvSwitchNotifyComplete0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitchnotifycomplete0) function to complete the pending operation.

## See also

[Callout Driver Callout Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[FWPS_VSWITCH_EVENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_vswitch_event_type_)

[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request)

[FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)

[FwpsvSwitchNotifyComplete0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitchnotifycomplete0)

[NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters)

[NDIS_SWITCH_PORT_PROPERTY_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_delete_parameters)

[NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters)

[OID_SWITCH_PORT_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-add)

[OID_SWITCH_PORT_PROPERTY_DELETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-delete)

[OID_SWITCH_PORT_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-update)