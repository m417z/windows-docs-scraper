# DXGK_SEGMENTDESCRIPTOR4 structure

## Description

The **DXGK_SEGMENTDESCRIPTOR4** structure describes a programmable CPU host aperture.

## Members

### `Flags`

Segment bit field flags

### `BaseAddress`

The physical base address for the segment in the GPU.

### `Size`

The size of the segment in bytes.

### `CommitLimit`

The maximum number of bytes that can be committed to this segment. This value applies to the aperture segment only.

### `SystemMemoryEndAddress`

For segments that are partially composed of system memory, all allocations ending after this address are purged during hibernate.

### `CpuTranslatedAddress`

If **Flags.SupportsCpuHostAperture**==**FALSE** and the segment is CPU visible, this will be the CPU physical base address of the segment.

### `CpuHostAperture`

If **Flags.SupportsCpuHostAperture**==**TRUE**, this will have the CPU address and size of the **CPUHostAperture**.

### `NumInvalidMemoryRanges`

The number of invalid memory ranges in the segment. If this value is not zero, the kernel mode driver will be called with DdiQueryAdapterInfo(DXGKQAITYPE_SEGMENTMEMORYSTATE) to get information about invalid memory ranges.

### `VprRangeStartOffset`

Start offset of the video protected region range, in bytes.

### `VprRangeSize`

Size of the video protected region range, in bytes.

### `VprAlignment`

Alignment of the video protected region range, in bytes. This value applies to both the size and start offset of the video protected region range.

### `NumVprSupported`

Number of supported video protected ranges in the VPR range. A value of zero indicates support for an infinite number.

### `VprReserveSize`

Size of the area in the VPR range that is reserved for the driver/hardware to use, in bytes. A value of zero indicates no reserve.

### `NumUEFIFrameBufferRanges`

Number of UEFI frame buffer ranges in the segment. Supported starting in WDDM 2.2.

## Remarks

This structure is used by a WDDM 2.0 or later kernel-mode display miniport drivers to return information about memory segments in response to a [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function call in which the graphics subsystem specifies the **DXGKQAITYPE_QUERYSEGMENT4** value in the **Type** member of the [**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo) structure.

This structure is pointed to by the **pSegmentDescriptor** member of the [**DXGK_QUERYSEGMENTOUT4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentout4) structure.

## See also

[**DXGK_QUERYSEGMENTOUT4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentout4)

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)