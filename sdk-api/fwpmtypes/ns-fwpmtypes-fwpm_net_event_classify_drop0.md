# FWPM_NET_EVENT_CLASSIFY_DROP0 structure

## Description

The **FWPM_NET_EVENT_CLASSIFY_DROP0** structure contains information that describes a layer drop failure.
[FWPM_NET_EVENT_CLASSIFY_DROP1](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_classify_drop1) is available. For Windows 8, [FWPM_NET_EVENT_CLASSIFY_DROP2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_classify_drop2) is available.

## Members

### `filterId`

A LUID identifying the filter where the failure occurred.

### `layerId`

Indicates the identifier of the filtering layer where the failure occurred. For more information, see [Filtering Layer Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)