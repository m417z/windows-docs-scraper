# FWPM_NET_EVENT0 structure

## Description

The **FWPM_NET_EVENT0** structure contains information about all event types.
[FWPM_NET_EVENT1](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event1) is available. For Windows 8, [FWPM_NET_EVENT2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event2) is available.

## Members

### `header`

A [FWPM_NET_EVENT_HEADER0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_header0) structure that contains information common to all events.

### `type`

A [FWPM_NET_EVENT_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-fwpm_net_event_type) value that specifies the type of event.

### `ikeMmFailure`

Address of an [FWPM_NET_EVENT_IKEEXT_MM_FAILURE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_mm_failure0) structure that contains information about an IKE main mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_MM_FAILURE**.

### `ikeQmFailure`

Address of an [FWPM_NET_EVENT_IKEEXT_QM_FAILURE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_qm_failure0) structure that contains information about an IKE quick mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_QM_FAILURE**.

### `ikeEmFailure`

Address of an [FWPM_NET_EVENT_IKEEXT_EM_FAILURE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_em_failure0) structure that contains information about an IKE user mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_EM_FAILURE**.

### `classifyDrop`

Address of an [FWPM_NET_EVENT_CLASSIFY_DROP0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_classify_drop0) structure that contains information about a drop event.

Available when **type** is **FWPM_NET_EVENT_TYPE_CLASSIFY_DROP**.

### `ipsecDrop`

Address of an [FWPM_NET_EVENT_IPSEC_KERNEL_DROP0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ipsec_kernel_drop0) structure that contains information about an IPsec kernel drop event.

Available when **type** is **FWPM_NET_EVENT_TYPE_IPSEC_KERNEL_DROP**.

### `idpDrop`

Address of an [FWPM_NET_EVENT_IPSEC_DOSP_DROP0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ipsec_dosp_drop0) structure that contains information about an IPsec DoS Protection event.

Available when **type** is **FWPM_NET_EVENT_IPSEC_DOSP_DROP**.

> [!Note]
> Available only in Windows Server 2008 R2, Windows 7, and later.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)