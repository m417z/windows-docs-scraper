# _NDIS_SWITCH_PARAMETERS structure

## Description

The **NDIS_SWITCH_PARAMETERS** structure contains the configuration data for a Hyper-V extensible switch.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PARAMETERS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_PARAMETERS** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PARAMETERS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_PARAMETERS_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `SwitchName`

 An **NDIS_SWITCH_NAME** value that specifies the unique internal name of the extensible switch.

The internal switch name is used by WMI-based policy management applications. For more information, see [Managing Hyper-V Extensible Switch Policies](https://learn.microsoft.com/windows-hardware/drivers/network/managing-hyper-v-extensible-switch-extensibility-policies).

### `SwitchFriendlyName`

 An **NDIS_SWITCH_FRIENDLYNAME** value that specifies the user-friendly description of the extensible switch.

### `NumSwitchPorts`

A UINT32 value that specifies the number of ports configured on the extensible switch.

### `IsActive`

A BOOLEAN that if TRUE indicates that the Hyper-V extensible switch activation has finished and it is safe to query for other switch configuration such as enumerating ports, NICs, and properties. If FALSE, the extension must wait for the [NetEventSwitchActivate](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpnp/ns-netpnp-_net_pnp_event) PNP event to be issued before querying for switch configuration.

## Remarks

The **NDIS_SWITCH_PARAMETERS** structure is used in the
OID request of [OID_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-parameters).

This structure is also passed in the *vSwitch* parameter of the following callout functions for Windows Filtering Platform callout drivers:

* [FWPS_VSWITCH_INTERFACE_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_interface_event_callback0)
* [FWPS_VSWITCH_LIFETIME_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_lifetime_event_callback0)
* [FWPS_VSWITCH_POLICY_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_policy_event_callback0)
* [FWPS_VSWITCH_PORT_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_port_event_callback0)
* [FWPS_VSWITCH_RUNTIME_STATE_RESTORE_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_runtime_state_restore_callback0)
* [FWPS_VSWITCH_RUNTIME_STATE_SAVE_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_runtime_state_save_callback0)

**Note** The **NDIS_SWITCH_NAME** and **NDIS_SWITCH_FRIENDLYNAME** data types are type-defined by the [IF_COUNTED_STRING](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-if_counted_string_lh) structure. A string that is defined by this structure does not have to be null-terminated. However, the length of the string must be set in the **Length** member of this structure. If the string is null-terminated, the **Length** member must not include the terminating null character.

## See also

[FWPS_VSWITCH_LIFETIME_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_lifetime_event_callback0)

[FWPS_VSWITCH_POLICY_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_policy_event_callback0)

[FWPS_VSWITCH_PORT_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_port_event_callback0)

[FWPS_VSWITCH_RUNTIME_STATE_RESTORE_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_runtime_state_restore_callback0)

[FWPS_VSWITCH_RUNTIME_STATE_SAVE_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_runtime_state_save_callback0)

[IF_COUNTEDFWPS_VSWITCH_INTERFACE_EVENT_CALLBACK0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_vswitch_interface_event_callback0)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NetEventSwitchActivate](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpnp/ns-netpnp-_net_pnp_event)

[OID_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-parameters)

[_STRING](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-if_counted_string_lh)