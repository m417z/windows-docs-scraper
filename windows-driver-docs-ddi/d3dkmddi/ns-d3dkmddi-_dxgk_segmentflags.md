# DXGK_SEGMENTFLAGS structure

## Description

The **DXGK_SEGMENTFLAGS** structure identifies properties for a segment that the driver provides through a call to its [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

## Members

### `Aperture`

[out] A UINT value that specifies whether the segment is an aperture segment instead of a memory segment. An aperture segment does not have physical pages that can hold content for an allocation. When the video memory manager pages an allocation into a memory segment, the memory manager transfers the content of the allocation from the system memory backing store to the segment location. When the video memory manager pages an allocation into an aperture segment, the memory manager maps the physical pages of the allocation backing store into the segment.

If the driver specifies this member, it must also implement the map-aperture-segment and unmap-aperture-segment operation types for its [**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) function.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Agp`

[out] A UINT value that specifies whether the segment is an [AGP**](https://learn.microsoft.com/windows-hardware/drivers/display/agp-support)-type aperture segment, which uses a portion of the AGP aperture that the chipset exposes. The video memory manager allocates the page for the underlying aperture and communicates with the graphic address remapping table (GART) driver to map and unmap memory for the aperture. Because only one AGP segment can exist, the driver should not specify the **Agp** bit-field flag with any other DXGK_SEGMENTFLAGS bit-field flags.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `CpuVisible`

[out] A UINT value that specifies whether the memory segment is accessible to the CPU at the address that is specified by the **CpuTranslatedAddress** member of the [**DXGK_SEGMENTDESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor) structure that describes the memory segment.

 This member has no meaning for an aperture segment, including the AGP-type aperture segment. The only exception occurs when the user-mode display driver has not set up an alternate virtual address for a primary allocation (that is, when the driver has not set **UseAlternateVA** in the **Flags** member of the [**D3DDDICB_LOCKFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags) structure during a call to the [**pfnLockCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function).

See Remarks for more info.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `UseBanking`

[out] A UINT value that specifies whether the segment is divided into banks that the driver uses to provide hints to the video memory manager about the placement of allocations within the segment. The driver should also specify valid bank information in the **NbOfBanks** and **pBankRangeTable** members of the [**DXGK_SEGMENTDESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor) structure that describes the segment.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `CacheCoherent`

[out] A UINT value that specifies whether the aperture segment can maintain cache coherency with cacheable pages that are mapped into the aperture. This member can be set only with setting the **Aperture** member (that is, **CacheCoherent** has no meaning for a memory segment).

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `PitchAlignment`

[out] A UINT value that specifies whether an allocation that is mapped into the segment must be pitch aligned. For this type of segment, the video memory manager uses the **Size** member of the [**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure for the allocation to allocate a backing store for the allocation. However, the video memory manager uses the **PitchAlignedSize** member of DXGK_ALLOCATIONINFO to allocate resources for the segment. An allocation that is targeted for this type of segment typically has a different size for the backing store and for the segment. When the backing-store size does not match the segment size, the driver must determine how to correctly move the data in the allocation. This type of segment cannot be used for eviction.

Setting this member is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

### `PopulatedFromSystemMemory`

[out] A UINT value that specifies whether the memory segment is actually populated from system memory that the driver allocated during initialization. If the memory segment is populated from system memory that the BIOS reserved and is not accessible to the operating system (that is, the operating system does not count this system memory when the operating system reports total amount of system memory), the driver should not set this flag. This flag is invalid and ignored on aperture segments.

Setting this member is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

### `PreservedDuringStandby`

[out] A UINT value that specifies whether the segment is preserved in a transition to a standby system power state.

For more information on power transition options, see Remarks.

Setting this member is equivalent to setting the eighth bit of the 32-bit **Value** member (0x00000080).

Supported starting with Windows 8.

### `PreservedDuringHibernate`

[out] A UINT value that specifies whether the segment is preserved in a transition to a hibernate system power state. Do not set this flag unless the **PreservedDuringStandby** member is also set. For more information on power transition options, see Remarks.

Setting this member is equivalent to setting the ninth bit of the 32-bit **Value** member (0x00000100).

Supported starting with Windows 8.

### `PartiallyPreservedDuringHibernate`

[out] A UINT value that specifies whether the segment is partially preserved in a transition to a hibernate system power state. Do not set this flag unless the **PreservedDuringStandby** member is also set. For more information on power transition options, see Remarks.

Setting this member is equivalent to setting the tenth bit of the 32-bit **Value** member (0x00000200).

Supported starting with Windows 8.

### `DirectFlip`

[out] A UINT value that specifies whether a segment supports Direct Flip allocations. In this case, the driver must ensure that Direct Flip allocations can be pinned and scanned out from this segment.

Setting this member is equivalent to setting the eleventh bit of the 32-bit **Value** member (0x00000400).

Supported starting with Windows 8.

### `Use64KBPages`

[out] When set, the GPU memory segment supports 64 KB pages. Otherwise, 4 KB pages are supported. When the driver sets the cap and an allocation can be paged-in to the segment, the allocation alignment, returned by the kernel mode driver from [**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo), must be multiple a of 64 KB.

Supported starting with Windows 10.

### `ReservedSysMem`

[out] Reserved for system use and should not be set by the kernel mode driver.

Supported starting with Windows 10.

### `SupportsCpuHostAperture`

[out] When set, the segment can be mapped through the CPU host aperture. This flag cannot be used in combination with the **CpuVisible** flag.

Supported starting with Windows 10.

### `SupportsCachedCpuHostAperture`

[out] When set, this indicates that the hardware supports CPU cache coherent CPU host aperture. Additionally, the **SupportsCpuHostAperture** flag must be set. The flag is typically set by the software GPU emulation drivers.

Supported starting with Windows 10.

### `ApplicationTarget`

[out] When set, it indicates that this segment should be targeted by application budgets.

Supported starting with Windows 10.

### `VprSupported`

[out] When set, indicates that Video Protected Region (VPR) is supported.

### `VprPreservedDuringStandby`

[out] When set, indicates that content of VPRs is preserved during standby.

### `EncryptedPagingSupported`

[out] When set, indicates that hardware-protected allocations are encrypted during paging.

### `LocalBudgetGroup`

[out] When set, indicates that this segment counts against the local memory segment budget group.

### `NonLocalBudgetGroup`

[out] When set, indicates that this segment counts against the non-local memory segment budget group.

### `PopulatedByReservedDDRByFirmware`

[out] When set, indicates that this segment is populated from reserved system DDR memory by firmware. Available starting with Windows Server 2022 (WDDM 2.9).

### `Reserved`

[out] This member is reserved and should be set to zero.

### `Value`

[out] A member in the union that DXGK_SEGMENTFLAGS contains that can hold a 32-bit value that identifies properties of the segment.

## Remarks

The driver can specify properties of the segment by setting bits in the 32-bit **Value** member or by setting individual members of the structure in the union that DXGK_SEGMENTFLAGS contains.

Note that for an AGP-type aperture segment, the driver must exclusively set the **Agp** member of the structure in the union that DXGK_SEGMENTFLAGS contains. Although the AGP-type aperture segment is an aperture and visible to the CPU, if any other members are set, the adapter fails to initialize.

In the special case where the allocation uses an aperture segment on a shared primary allocation ([**DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getstandardallocationdriverdata).**StandardAllocationType** is **D3DKMDT_STANDARDALLOCATION_SHAREDPRIMARYSURFACE**), and [**DXGK_ALLOCATIONINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags).**UseAlternateVA** is not set, the driver should use a section-backed primary allocation ([**DXGK_VIDMMCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidmmcaps).**SectionBackedPrimary** is set) when the driver's [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function is called. By using a section-backed primary you can avoid the limitations of **CpuVisible** for the aperture segment.

You can avoid the limitations of **CpuVisible** for an aperture segment by using a shared, section-backed primary allocation. In this case, use an aperture segment on a shared primary allocation ([**DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getstandardallocationdriverdata).**StandardAllocationType** is **D3DKMDT_STANDARDALLOCATION_SHAREDPRIMARYSURFACE**), do not set [**DXGK_ALLOCATIONINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags).**UseAlternateVA**, and use a section-backed primary allocation (set [**DXGK_VIDMMCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidmmcaps).**SectionBackedPrimary**) when the driver's [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function is called.

### Optimized standby settings

The combination of values for the **PreservedDuringStandby**, **PreservedDuringHibernate**, and **PartiallyPreservedDuringHibernate** members determines whether a segment is purged of its content when the system enters a low-power (standby) system state, as follows.

|Preserved During Standby|Preserved During Hibernate|Partially Preserved During Hibernate|Standby State|Hibernate State|
|--- |--- |--- |--- |--- |
|1|1|1|invalid|invalid|
|1|1|0|not purged|not purged|
|1|0|1|not purged|partially purged|
|1|0|0|not purged|purged|
|0|1|1|invalid|invalid|
|0|1|0|invalid|invalid|
|0|0|1|invalid|invalid|
|0|0|0|purged|purged|

The operating system does not recognize combinations in this table that are marked "invalid".

If the [hybrid sleep](https://learn.microsoft.com/windows-hardware/customize/power-settings/sleep-settings-hybrid-sleep) mode is enabled, the system acts as if it is hibernating: it purges segments that are not preserved during hibernate, even if it is going into a low-power state.

## See also

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[**DXGK_QUERYSEGMENTIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentin)

[**DXGK_SEGMENTDESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor)

[**DXGK_SEGMENTDESCRIPTOR3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor3)

[**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)