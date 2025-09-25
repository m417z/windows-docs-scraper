# DXGK_VIDMMCAPS structure

## Description

The **DXGK_VIDMMCAPS** structure identifies the video memory management capabilities that a kernel-mode display miniport driver (KMD) supports.

## Members

### `OutOfOrderLock`

Specifies whether the driver can lock allocation instances other than the latest instance. The driver typically sets this value for DDI threading and load balancing if a DDI thread must lock a vertex buffer that an application thread had previously locked and discarded.

### `DedicatedPagingEngine`

This member is reserved and should be set to zero.

### `PagingEngineCanSwizzle`

This member is reserved and should be set to zero.

### `SectionBackedPrimary`

Specifies whether the driver supports section-backed primary allocations. Supported starting with Windows 8.

### `CrossAdapterResource`

Specifies whether the driver provides tier 1 support of copying to and from cross-adapter resources in a [hybrid system](https://learn.microsoft.com/windows-hardware/drivers/display/using-cross-adapter-resources-in-a-hybrid-system). Supported starting with Windows 8.1.

Starting in WDDM 2.4, DXGI enables the current hybrid presentation optimizations for the broader scenario wherever rendering is on one GPU and presenting on another GPU’s monitor. This is only possible if both GPUs support cross-adapter resources.

The cross adapter resource properties are listed below.

* The resource can be paged-in only to the aperture GPU memory segment
* The resource is allocated as shared.
* The resource must be marked CPU Visible.
* The allocation will be created by the OS as write-combined.
* The resource has only one allocation and has the linear format.
* The resource has standard pitch alignment (128 bytes). The D3DKMT_CROSS_ADAPTER_RESOURCE_PITCH_ALIGNMENT definition is added for the pitch alignment. The resource must be created at the smallest multiple of this alignment that will contain the resource contents.
* The resource has a standard height alignment (4 rows). The D3DKMT_CROSS_ADAPTER_RESOURCE_HEIGHT_ALIGNMENT is added. The resource must be created at the smallest multiple of this alignment that will contain the resource contents.

```cpp
#define D3DKMT_CROSS_ADAPTER_RESOURCE_PITCH_ALIGNMENT 128

#define D3DKMT_CROSS_ADAPTER_RESOURCE_HEIGHT_ALIGNMENT 4
```

* The start address of the resource memory is aligned to one page boundary.
* The resource might be e created as a standard allocation from kernel mode and later opened by the UMD.
* The resource might be created by the UMD.

The cross adapter allocation could be used as a primary, but the driver will not get information, that is usually provided when the primary is created

### `VirtualAddressingSupported`

Specifies whether the driver supports virtual memory addressing. To express support for GPU virtual memory addressing, the driver should set the **VirtualAddressingSupported** cap and **GpuMmuSupported** or **IoMmuSupported** caps.
**GpuMmuSupported** and **IoMmuSupported** cannot be set at the same time. Supported starting with Windows 10 (WDDM 2.0).

### `GpuMmuSupported`

Specifies whether the adapter supports the *GpuMmu* model. An adapter cannot support the *GpuMmu* and the *IoMmu* models on different engines at the same time. See [GpuMmu model](https://learn.microsoft.com/windows-hardware/drivers/display/gpummu-model) for more information. Supported starting with Windows 10 (WDDM 2.0).

### `IoMmuSupported`

Specifies whether the adapter supports the *IoMmu* model. An adapter cannot support the *GpuMmu* and the *IoMmu* models on different engines at the same time. See [IoMmu model](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-model) for more information. Supported starting with Windows 10 (WDDM 2.0).

### `ReplicateGdiContent`

Specifies whether the adapter supports the replication of GDI content. Supported starting with Windows 10 (WDDM 2.0).

### `NonCpuVisiblePrimary`

Indicates that GDI allocations are not required to be CPU visible. Supported starting with Windows 10 (WDDM 2.0).

### `ParavirtualizationSupported`

Indicates that the KMD supports [GPU paravirtualization](https://learn.microsoft.com/windows-hardware/drivers/display/gpu-paravirtualization). The host KMD needs to set the cap if all DDIs are implemented. Introduced in Windows 10 version 1703 (WDDM 2.2).

### `IoMmuSecureModeSupported`

Indicates that the driver supports [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation). Supported starting with Windows 10 version 1803 (WDDM 2.4).

### `DisableSelfRefreshVRAMInS3`

Disable support for VRAM self-refresh in S3. Supported starting with Windows 10 version 1803.

### `IoMmuSecureModeRequired`

Indicates that IOMMU hardware and isolation support (referred to by the **IommuSecureModeSupported** flag) is required or the OS will otherwise not start the adapter. Supported starting with Windows 10 version 2004 (WDDM 2.7).

### `MapAperture2Supported`

Indicates that the driver supports the [**DXGK_OPERATION_MAP_APERTURE_SEGMENT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_buildpagingbuffer_operation) paging buffer operation, which is required for [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping). Supported starting with WDDM version 2.9.

### `CrossAdapterResourceTexture`

Specifies whether the driver provides tier 2 support of texturing from cross-adapter resources. A driver that indicates support for **CrossAdapterResourceTexture** must also indicate support for **CrossAdapterResource**. Supported starting with WDDM version 2.9.

### `CrossAdapterResourceScanout`

Specifies whether the driver provides tier 3 support of scanning out cross-adapter resources. A driver that indicates support for **CrossAdapterResourceScanout** must also indicate support for **CrossAdapterResource** and **CrossAdapterResourceTexture**. Supported starting with WDDM version 2.9.

Tier 3 support requires that the driver be able to perform the supported flipping capabilities, declared by driver in [**DXGK_FLIPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_flipcaps), for cross-adapter resources of the following minimum specifications:

* Cross-adapter primary buffer size of 1920 x 1080 or smaller
* Buffer pixel format of any of the following supported DisplayScanOut formats:
  * DXGI_FORMAT_R16G16B16A16_FLOAT
  * DXGI_FORMAT_R10G10B10A2_UNORM
  * DXGI_FORMAT_R8G8B8A8_UNORM
  * DXGI_FORMAT_R8G8B8A8_UNORM_SRGB
  * DXGI_FORMAT_B8G8R8A8_UNORM
  * DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM
  * DXGI_FORMAT_B8G8R8A8_UNORM_SRGB

The DXGI runtime will query for driver's **CrossAdapterResourceScanout** support and if supported, the presentation stack shall go down the 1 copy path. Therefore, drivers that declare support for **CrossAdapterResourceScanout** are also required to:

* Support [**DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport3).
* Support all the relevant presentation-related DDIs for cross-adapter primaries of the above minimum specifications. A few examples are pfnCreateResource, pfnCheckMultiplaneOverlaySupport and pfnPresentMultiplaneOverlay/pfnPresent1. Please refer to existing specs for the necessary detail, such as MPO spec and Hybrid spec. Please refer to the section below for more details about falling out of CASO.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 31 bits (after setting **OutOfOrderLock**) of the **Value** member to zeros. Note that **Reserved** is available only if DXGKDDI_INTERFACE_VERSION < DXGKDDI_INTERFACE_VERSION_WIN7.

### `Value`

This value is used to operate over the members collectively.

### `PagingNode`

The zero-based index of the node to use for paging operations. If the driver does not set the **MultiEngineAware** bit-field member of the **SchedulingCaps** member of the [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure, the DirectX graphics kernel subsystem ignores the setting of **PagingNode**. This member applies to WDDM 1.x only. In WDDM 2.x, **PagingNode** was moved to [**DXGK_PHYSICALADAPTERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_physicaladaptercaps).

## See also

[**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DXGK_PHYSICALADAPTERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_physicaladaptercaps)