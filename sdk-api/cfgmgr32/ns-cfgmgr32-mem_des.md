# MEM_DES structure

## Description

The MEM_DES structure is used for specifying either a resource list or a resource requirements list that describes memory usage for a device instance. For more information about resource lists and resource requirements lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `MD_Count`

#### For a resource list:

Zero.

#### For a resource requirements list:

The number of elements in the [MEM_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mem_range) array that is included in the [MEM_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mem_resource) structure.

### `MD_Type`

Must be set to the constant value **MType_Range**.

### `MD_Alloc_Base`

#### For a resource list:

The lowest-numbered of a range of contiguous physical memory addresses allocated to the device.

#### For a resource requirements list:

Zero.

### `MD_Alloc_End`

#### For a resource list:

The highest-numbered of a range of contiguous physical memory addresses allocated to the device.

#### For a resource requirements list:

Zero.

### `MD_Flags`

One bit flag from *each* of the flag sets described in the following table.

|  | Flag | Definition |
| --- | --- | --- |
| *Read-Only Flags* | |  |
|  | **fMD_ROM** | The specified memory range is read-only. |
|  | **fMD_RAM** | The specified memory range is not read-only. |
|  | **mMD_MemoryType** | Bitmask for the bit within **MD_Flags** that specifies the read-only attribute. |
| *Write-Only Flags* | |  |
|  | **fMD_ReadDisallowed** | The specified memory range is write-only. |
|  | **fMD_ReadAllowed** | The specified memory range is not write-only. |
|  | **mMD_Readable** | Bitmask for the bit within **MD_Flags** that specifies the write-only attribute. |
| *Address Size Flags* | |  |
|  | **fMD_24** | 24-bit addressing (*not used*). |
|  | **fMD_32** | 32-bit addressing. |
|  | **mMD_32_24** | Bitmask for the bit within **MD_Flags** that specifies the address size. |
| *Prefetch Flags* | |  |
|  | **fMD_PrefetchAllowed** | The specified memory range can be prefetched. |
|  | **fMD_PrefetchDisallowed** | The specified memory range cannot be prefetched. |
|  | **mMD_Prefetchable** | Bitmask for the bit within **MD_Flags** that specifies the prefetch ability. |
| *Caching Flags* | |  |
|  | **fMD_Cacheable** | The specified memory range can be cached. |
|  | **fMD_NonCacheable** | The specified memory range cannot be cached. |
|  | **mMD_Cacheable** | Bitmask for the bit within **MD_Flags** that specifies the caching ability. |
| *Combined-Write Caching Flags* | |  |
|  | **fMD_CombinedWriteAllowed** | Combined-write caching is allowed. |
|  | **fMD_CombinedWriteDisallowed** | Combined-write caching is not allowed. |
|  | **mMD_CombinedWrite** | Bitmask for the bit within **MD_Flags** that specifies the combine-write caching ability. |

### `MD_Reserved`

*For internal use only.*

## See also

[MEM_RANGE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mem_range)

[MEM_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-mem_resource)