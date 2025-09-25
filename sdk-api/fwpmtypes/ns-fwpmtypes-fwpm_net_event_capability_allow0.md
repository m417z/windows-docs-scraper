# FWPM_NET_EVENT_CAPABILITY_ALLOW0 structure

## Description

The **FWPM_NET_EVENT_CAPABILITY_ALLOW0** structure contains information about network traffic allowed in relation to an app container network capability.. The specified app container network capability grants access to network resources, and the specified filter identifier enforces allowing access.

## Members

### `networkCapabilityId`

Type: **[FWPM_APPC_NETWORK_CAPABILITY_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-fwpm_appc_network_capability_type)**

The specific app container network capability allowing this traffic.

### `filterId`

Type: **UINT64**

A LUID identifying the WFP filter enforcing the allowed access intended by the capability in **networkCapabilityId**.

### `isLoopback`

Type: **BOOL**

True if the packet originated from (or was heading to) the loopback adapter; otherwise, false.

## See also

[FWPM_APPC_NETWORK_CAPABILITY_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-fwpm_appc_network_capability_type)

[FWPM_NET_EVENT_CAPABILITY_DROP0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_capability_drop0)