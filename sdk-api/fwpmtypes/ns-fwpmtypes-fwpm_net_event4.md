## Description

The **FWPM_NET_EVENT4** structure contains information about all event types. [FWPM_NET_EVENT3](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event3) and [FWPM_NET_EVENT2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event2) are available. For Windows 7, [FWPM_NET_EVENT1](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event1) is available. For Windows Vista, [FWPM_NET_EVENT0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event0) is available.

## Members

### `header`

Information common to all events.

### `type`

The type of event.

### `ikeMmFailure`

Information about an IKE main mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_MM_FAILURE**.

### `ikeQmFailure`

Information about an IKE quick mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_QM_FAILURE**.

### `ikeEmFailure`

Information about an IKE user mode failure.

Available when **type** is **FWPM_NET_EVENT_TYPE_IKEEXT_EM_FAILURE**.

### `classifyDrop`

Information about a drop event.

Available when **type** is **FWPM_NET_EVENT_TYPE_CLASSIFY_DROP**.

### `ipsecDrop`

Information about an IPsec kernel drop event.

Available when **type** is **FWPM_NET_EVENT_TYPE_IPSEC_KERNEL_DROP**.

### `idpDrop`

Information about an IPsec DoS Protection event.

Available when **type** is **FWPM_NET_EVENT_IPSEC_DOSP_DROP**.

### `classifyAllow`

Information about an allow event.

### `capabilityDrop`

Information about a capability-related drop event.

### `capabilityAllow`

Information about a capability-related allow event.

### `classifyDropMac`

Information about a MAC layer drop event.

## Remarks

## See also

[Windows Filtering Platform API structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)