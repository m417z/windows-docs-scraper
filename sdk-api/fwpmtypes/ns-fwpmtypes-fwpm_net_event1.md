# FWPM_NET_EVENT1 structure

## Description

The **FWPM_NET_EVENT1** structure contains information about all event types.
[FWPM_NET_EVENT0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event0) is available.

## Members

### `header`

An [FWPM_NET_EVENT_HEADER1](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_header1) structure that contains information common to all events.

### `type`

An [FWPM_NET_EVENT_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-fwpm_net_event_type) value that specifies the type of event.

### `ikeMmFailure`

Address of an [FWPM_NET_EVENT_IKEEXT_MM_FAILURE1](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_mm_failure1) structure that contains information about an IKE main mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_MM_FAILURE**.

### `ikeQmFailure`

Address of an [FWPM_NET_EVENT_IKEEXT_QM_FAILURE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_qm_failure0) structure that contains information about an IKE quick mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_QM_FAILURE**.

### `ikeEmFailure`

Address of an [FWPM_NET_EVENT_IKEEXT_EM_FAILURE1](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_em_failure1) structure that contains information about an IKE user mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_EM_FAILURE**.

### `classifyDrop`

Address of an [FWPM_NET_EVENT_CLASSIFY_DROP1](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_classify_drop1) structure that contains information about a drop event.

Available when **type** is **FWPM_NET_EVENT_TYPE_CLASSIFY_DROP**.

### `ipsecDrop`

Address of an [FWPM_NET_EVENT_IPSEC_KERNEL_DROP0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ipsec_kernel_drop0) structure that contains information about an IPsec kernel drop event.

Available when **type** is **FWPM_NET_EVENT_TYPE_IPSEC_KERNEL_DROP**.

### `idpDrop`

Address of an [FWPM_NET_EVENT_IPSEC_DOSP_DROP0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ipsec_dosp_drop0) structure that contains information about an IPsec DoS Protection event.

Available when **type** is **FWPM_NET_EVENT_IPSEC_DOSP_DROP**.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)