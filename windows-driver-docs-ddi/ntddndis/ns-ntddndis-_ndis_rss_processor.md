# _NDIS_RSS_PROCESSOR structure

## Description

The NDIS_RSS_PROCESSOR structure specifies information about a processor in the local computer for
receive side scaling (RSS).

## Members

### `ProcNum`

The processor number that is assigned to the processor.

### `PreferenceIndex`

The preference rating of the processor, which is based on Non-Uniform Memory Access (NUMA) distance.
A lower value for
**PreferenceIndex** indicates a smaller NUMA distance to the miniport
driver.

When choosing between multiple processors, miniport drivers should select the processor with a lower
**PreferenceIndex** value. This results in less overhead for the driver.

### `Reserved`

Reserved for NDIS.

## Remarks

The NDIS_RSS_PROCESSOR structure is used in the
[NDIS_RSS_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor_info) structure.

## See also

[NDIS_RSS_PROCESSOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor_info)