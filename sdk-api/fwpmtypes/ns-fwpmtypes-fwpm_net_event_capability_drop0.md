# FWPM_NET_EVENT_CAPABILITY_DROP0 structure

## Description

The **FWPM_NET_EVENT_CAPABILITY_DROP0** structure contains information about network traffic dropped in relation to an app container network capability. Traffic is dropped due to the specified app container network capability and enforced by the specified filter identifier.

## Members

### `networkCapabilityId`

Type: **[FWPM_APPC_NETWORK_CAPABILITY_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-fwpm_appc_network_capability_type)**

The specific app container network capability which was missing, therefore causing this traffic to be denied.

### `filterId`

Type: **UINT64**

A LUID identifying the WFP filter where the traffic drop occurred.

### `isLoopback`

Type: **BOOL**

True if the packet originated from (or was heading to) the loopback adapter; otherwise, false.

## See also

[FWPM_APPC_NETWORK_CAPABILITY_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-fwpm_appc_network_capability_type)

[FWPM_NET_EVENT_CAPABILITY_ALLOW0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_capability_allow0)