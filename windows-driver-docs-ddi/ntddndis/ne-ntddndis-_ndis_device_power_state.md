# _NDIS_DEVICE_POWER_STATE enumeration

## Description

The **NDIS_DEVICE_POWER_STATE** enumeration defines device power state values. For more information about device power states, see:

[Device Power States for Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/device-power-states-for-network-adapters)

[Device Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states)

[Device Working State D0](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-working-state-d0)

[Device Low-Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states)

[Required Support for Device Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/required-support-for-device-power-states)

## Constants

### `NdisDeviceStateUnspecified`

The device does not support power management.

### `NdisDeviceStateD0`

Device power state D0.

### `NdisDeviceStateD1`

Device power state D1.

### `NdisDeviceStateD2`

Device power state D2.

### `NdisDeviceStateD3`

Device power state D3.

### `NdisDeviceStateMaximum`

The maximum value for this enumeration. Reserved for system use. Do not use this value in your driver. This value might change in future versions of NDIS header files and binaries.

## Remarks

Depending on the capabilities of the network adapter and its miniport driver, the device might be able to generate a wake-up signal from device states D0 through D3.

**Note** If the wake-up signal is generated from D0, the signal does not cause a system wake-up. However, the wake-up signal can be used to signal a run-time event.

**NDIS_DEVICE_POWER_STATE** enumeration values are used in the [NDIS_PM_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_capabilities), [NDIS_SRIOV_SET_VF_POWER_STATE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_set_vf_power_state_parameters), and [NET_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpnp/ns-netpnp-_net_pnp_event) structures, the [NdisMIdleNotificationConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationconfirm) function, and the [OID_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-capabilities), [OID_PNP_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-query-power), and [OID_PNP_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-set-power) OID requests.

## See also

[NDIS_PM_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_capabilities)

[NDIS_SRIOV_SET_VF_POWER_STATE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_set_vf_power_state_parameters)

[NET_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpnp/ns-netpnp-_net_pnp_event)

[NdisMIdleNotificationConfirm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismidlenotificationconfirm)

[OID_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-capabilities)

[OID_PNP_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-query-power)

[OID_PNP_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-set-power)