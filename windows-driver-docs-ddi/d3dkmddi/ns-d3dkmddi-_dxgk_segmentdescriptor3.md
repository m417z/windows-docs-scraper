# DXGK_SEGMENTDESCRIPTOR3 structure

## Description

The **DXGK_SEGMENTDESCRIPTOR3** structure contains information about a driver-supported segment that is composed of both BIOS-reserved memory (which is purged during a transition to a low-power state) and driver-reserved memory.

## Members

### `Flags` [out]

A [**DXGK_SEGMENTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentflags) structure that identifies properties, in bit-field flags, for the segment.

Note that for an AGP-type aperture segment, the driver must exclusively set the **Agp** member of the structure in the union that DXGK_SEGMENTFLAGS contains. Although the AGP-type aperture segment is an aperture and is accessible to the CPU, if any other members are set, the adapter fails to initialize.

### `BaseAddress` [out]

The base address of the segment, as determined by the graphics processing unit (GPU). The physical address of an allocation that the video memory manager paged in the segment is assigned a GPU address that is offset from the base address that **BaseAddress** specifies.

The video memory manager ignores the base address of AGP-type aperture segments (where the **Agp** bit-field flag is specified in the **Flags** member) and instead uses the actual physical address of the segment within the AGP aperture, as determined on the bus where the GPU is located. In this situation, the driver can use addresses that the video memory manager generated for allocation directly without requiring translation.

### `CpuTranslatedAddress` [out]

The base address of the segment, relative to the bus that the GPU is connected on. For example, when the GPU is connected on the PCI bus, **CpuTranslatedAddress** is the base address of the usable range that is specified by a PCI base-address register (BAR). The driver specifies this address only if it specifies a CPU-accessible segment by setting the **CpuVisible** bit-field flag in the **Flags** member.

This member is ignored for aperture segments, including the AGP-type aperture segment. The only exception occurs when the user-mode display driver has not set up an alternate virtual address for a primary allocation (that is, when the driver has not set **UseAlternateVA** in the **Flags** member of the [**D3DDDICB_LOCKFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags) structure during a call to the [**pfnLockCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function).

Before the video memory manager maps a virtual address to the physical range, the video memory manager translates this physical address based on the CPU view of the bus and informs the driver about the operation so the driver can set up an aperture to access the content of the segment at the specified location.

### `Size` [out]

The size, in bytes, of the segment. This size must be a multiple of the native host page size (for example, 4 KB on the x86 architecture).

For AGP-type aperture segments (where the **Agp** bit-field flag is specified in the **Flags** member), the video memory manager allocates as much aperture space as possible, so this member is ignored.

### `NbOfBanks` [out]

The number of banks in the segment, if banking is used (that is, if the **UseBanking** bit-field flag is set in the **Flags** member).

### `pBankRangeTable` [out]

An array of values that indicates the ranges that delimit each bank in the segment. The driver specifies this array only if it also sets the **UseBanking** bit-field flag in the **Flags** member.

The array specifies the end addresses of the first bank through the ***NbOfBanks***th bank (that is, the end offsets into the segment for each bank). Note the following:

* Banks are contiguous.

* The first bank starts at offset zero of the segment.

* The last bank ends at the end of the segment, so the driver is not required to specify the end address of the last bank.

### `CommitLimit` [out]

The maximum number of bytes that can be committed to the segment. For a memory segment, the commit limit is always the same as the size of the segment, which is specified in the **Size** member. For an aperture segment, the driver can limit the amount of memory that can be committed to the segment on systems with small amounts of physical memory.

### `SystemMemoryEndAddress`

For segments that are partially composed of system memory, all allocations that begin after this address are purged in a transition to a hibernate state. Allocations that exist entirely in system memory, where the segment address is less than or equal to **SystemMemoryEndAddress**, are not evicted in this transition.

The display miniport driver should set this member to a non-**NULL** value if the segment is partially preserved in a transition to a hibernate state, in which case the **PartiallyPreservedDuringHibernate** member in the [**DXGK_SEGMENTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentflags) structure should be set.

Driver-reserved memory runs from segment address 0 through **SystemMemoryEndAddress**, inclusive. BIOS-reserved memory runs from (**SystemMemoryEndAddress**+1) through the end of the segment.

### `Reserved`

This member is reserved and should be set to zero.

## Remarks

This structure is used by a WDDM 1.2 or later kernel-mode display miniport drivers to return information about memory segments in response to a [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function call in which the graphics subsystem specifies the **DXGKQAITYPE_QUERYSEGMENT3** value in the **Type** member of the [**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo) structure.

This structure is pointed to by the **pSegmentDescriptor** member of the [**DXGK_QUERYSEGMENTOUT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentout3) structure.

## See also

[**D3DDDICB_LOCKFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags)

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[**DXGK_QUERYSEGMENTOUT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentout3)

[**DXGK_SEGMENTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentflags)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)