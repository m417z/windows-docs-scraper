# D3DDDI_EVICT_FLAGS structure

## Description

**D3DDDI_EVICT_FLAGS** specifies the eviction behavior.

## Members

### `EvictOnlyIfNecessary`

When set, this indicates that the resource may be used again in the near future and instructs the OS to try to defer actual resource eviction from the GPU until low memory conditions. When not set, this instructs the OS that the resource will no longer be used and that the eviction should be performed at the earliest opportunity.

**Note** This flag is ignored if the residency reference count does not hit zero because the allocation will not be evicted until that time.

### `NotWrittenTo`

When set, this indicates that the resource has not been written to by the GPU since the time it was made resident. This allows the OS to optimize the eviction process by discarding the allocation contents instead of paging it out to the system memory. The driver must opt-in to use this flag. By default, the value is zero and the allocation is considered dirty during eviction. Unlike **EvictOnlyIfNecessary**, the driver does not need to defer setting this flag until the last call to **Evict** ([pfnEvictCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_evictcb) or [D3DKMTEvict](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtevict)), and the effects of specifying this flag take place immediately. In other words, if the driver calls **MakeResident** multiple times, it is valid for any one of the subsequent **Evict** operations to specify this flag. The driver is not expected to track this flag until the last call.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

The consolidated value of the flags in the structure.

## See also

[D3DKMTEvict](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtevict)

[pfnEvictCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_evictcb)