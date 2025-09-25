## Description

The **WWAN_SINGLE_NSSAI** structure represents a single Network Slice Selection Assistance Information (NSSAI). WWAN_SINGLE_NSSAI is used to uniquely identify a network slice.

## Members

### `Bitmasks`

A 32-bit integer containing the map (logical OR) indicating if the fields that follow are present.

### `SliceServiceType`

Only valid if *Bitmasks* contains WWAN_SNSSAI_SST_VALID (0x00000001).

### `MappedSliceServiceType`

Only valid if *Bitmasks* contains WWAN_SNSSAI_MAPPED_SST_VALID (0x00000002).

### `SliceDifferentiator`

Only valid if *SliceServiceType* is valid. May be WWAN_SNSSAI_NO_SD_VALUE_ASSOCIATED_WITH_SST (0x00FFFFFF).

Defines the expected behavior of the network slice features and services. Values include enhanced mobile broadband (eMBB), ultra-reliable low latency communications (URLLC), and massive Internet of Things (MIoT).

### `MappedSliceDifferentiator`

Only valid if *MappedSliceServiceType* is valid. May be WWAN_SNSSAI_NO_SD_VALUE_ASSOCIATED_WITH_SST (0x00FFFFFF).

The slice differentiator is directly related to the *SliceServiceType* and is used as an additional differentiator if multiple network slices carry the same value in *SliceServiceType*.

## Remarks

## See also

[WWAN_CONTEXT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context_state)

[WWAN_SNSSAI_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_snssai_list)