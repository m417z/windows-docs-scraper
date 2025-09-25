# FWPM_NET_EVENT2 structure

## Description

The **FWPM_NET_EVENT2** structure contains information about all event types.
[FWPM_NET_EVENT0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event0) is available.

## Members

### `header`

Type: **[FWPM_NET_EVENT_HEADER2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_header2)**

Information common to all events.

### `type`

Type: **[FWPM_NET_EVENT_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-fwpm_net_event_type)**

The type of event.

### `ikeMmFailure`

Type: **[FWPM_NET_EVENT_IKEEXT_MM_FAILURE1](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_mm_failure1)***

Information about an IKE main mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_MM_FAILURE**.

### `ikeQmFailure`

Type: **[FWPM_NET_EVENT_IKEEXT_QM_FAILURE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_qm_failure0)***

Information about an IKE quick mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_QM_FAILURE**.

### `ikeEmFailure`

Type: **[FWPM_NET_EVENT_IKEEXT_EM_FAILURE1](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_em_failure1)***

Information about an IKE user mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_EM_FAILURE**.

### `classifyDrop`

Type: **[FWPM_NET_EVENT_CLASSIFY_DROP2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_classify_drop2)***

Information about a drop event.

Available when **type** is **FWPM_NET_EVENT_TYPE_CLASSIFY_DROP**.

### `ipsecDrop`

Type: **[FWPM_NET_EVENT_IPSEC_KERNEL_DROP0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ipsec_kernel_drop0)***

Information about an IPsec kernel drop event.

Available when **type** is **FWPM_NET_EVENT_TYPE_IPSEC_KERNEL_DROP**.

### `idpDrop`

Type: **[FWPM_NET_EVENT_IPSEC_DOSP_DROP0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ipsec_dosp_drop0)***

Information about an IPsec DoS Protection event.

Available when **type** is **FWPM_NET_EVENT_IPSEC_DOSP_DROP**.

### `classifyAllow`

Type: **[FWPM_NET_EVENT_CLASSIFY_ALLOW0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_classify_allow0)***

Information about an allow event.

### `capabilityDrop`

Type: **[FWPM_NET_EVENT_CAPABILITY_DROP0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_capability_drop0)***

Information about a capability-related drop event.

### `capabilityAllow`

Type: **[FWPM_NET_EVENT_CAPABILITY_ALLOW0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_capability_allow0)***

Information about a capability-related allow event.

### `classifyDropMac`

Type: **[FWPM_NET_EVENT_CLASSIFY_DROP_MAC0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_classify_drop_mac0)***

Information about a MAC layer drop event.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)