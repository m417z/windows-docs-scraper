# _NDIS_RSS_PROFILE enumeration

## Description

This enumeration is not supported.

## Constants

### `NdisRssProfileClosest`

Default behavior is consistent with that of Windows Server 2008 R2.

### `NdisRssProfileClosestStatic`

No dynamic load balancing. Distribute but don't load-balance at runtime.

### `NdisRssProfileNuma`

Assign RSS CPUs on a round-robin basis across every NUMA node to enable applications that are running on NUMA servers to scale well.

### `NdisRssProfileNumaStatic`

RSS processor selection is the same as for NUMA scalability without dynamic load-balancing.

### `NdisRssProfileConservative`

RSS uses as few processors as possible to sustain the load. This option helps reduce the number of interrupts.

### `NdisRssProfileMaximum`

This enumeration value is reserved. Do not use.

## Remarks

The **NDIS_RSS_PROFILE** enumeration type specifies the current RSS load balancing profile.

NDIS network drivers use the **NDIS_RSS_PROFILE** enumeration type to set the value of the **RssProfile** member of the [NDIS_RSS_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor_info) structure.

## See also

[NDIS_RSS_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor_info)

[NdisGetRssProcessorInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetrssprocessorinformation)

[Standardized INF Keywords for RSS](https://learn.microsoft.com/windows-hardware/drivers/network/standardized-inf-keywords-for-rss)