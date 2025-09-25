# DXGK_QUERYADAPTERINFOTYPE enumeration

## Description

The **DXGK_QUERYADAPTERINFOTYPE** enumeration indicates the type of information the kernel-mode display miniport driver (KMD) should return in the buffer that **pOutputData** points to when its [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function is called. See [**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo) for details regarding those types that require input (**pInputData**).

## Constants

### `DXGKQAITYPE_UMDRIVERPRIVATE:0`

Indicates a private, proprietary-defined data structure for the display driver.

### `DXGKQAITYPE_DRIVERCAPS:1`

The KMD should populate a [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure with its driver capabilities.

### `DXGKQAITYPE_QUERYSEGMENT:2`

The KMD should populate a [**DXGK_QUERYSEGMENTOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentout) structure with its memory-segment information.

### `DXGKQAITYPE_RESERVED:3`

Reserved for system use. Do not use in your driver. This constant occurs starting in Windows 7.

### `DXGKQAITYPE_QUERYSEGMENT2:4`

Reserved for system use. Do not use in your driver. This constant occurs starting in Windows 7.

### `DXGKQAITYPE_QUERYSEGMENT3:5`

The KMD should populate a [**DXGK_QUERYSEGMENTOUT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentout3) structure with memory-segment information. Supported starting in Windows 8.

### `DXGKQAITYPE_NUMPOWERCOMPONENTS:6`

The display miniport should provide a UINT value that specifies the number of power components that it uses. Supported starting in Windows 8.

### `DXGKQAITYPE_POWERCOMPONENTINFO:7`

The KMD should populate a [**DXGK_POWER_RUNTIME_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_power_runtime_component) structure with information about the *n*th power component, where *n* is the component index specified by **[DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo).pInputData** in a call to [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo). Supported starting in Windows 8.

### `DXGKQAITYPE_PREFERREDGPUNODE:8`

Reserved for system use. Do not use in your driver. This constant occurs starting in Windows 8.

### `DXGKQAITYPE_POWERCOMPONENTPSTATEINFO:9`

Reserved for system use. Do not use in your driver. Supported starting in Windows 8.1.

### `DXGKQAITYPE_HISTORYBUFFERPRECISION:10`

The KMD should populate a [**DXGKARG_HISTORYBUFFERPRECISION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_historybufferprecision) structure with information about the precision of history buffer data that it uses. Supported starting in Windows 8.1.

### `DXGKQAITYPE_QUERYSEGMENT4:11`

The KMD should populate a [**DXGK_QUERYSEGMENTOUT4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentout4) structure to indicate its memory-segment information. Supported starting in Windows 10.

### `DXGKQAITYPE_SEGMENTMEMORYSTATE:12`

The KMD should populate a [**DXGK_MEMORYRANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_memoryrange) structure with its bad memory ranges. Supported starting in Windows 10.

### `DXGKQAITYPE_GPUMMUCAPS:13`

The KMD should populate a [**DXGK_GPUMMUCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gpummucaps) structure with its virtual memory management capabilities. Supported starting in Windows 10.

### `DXGKQAITYPE_PAGETABLELEVELDESC:14`

Reserved for system use. Do not use in your driver. This constant occurs starting in Windows 10.

### `DXGKQAITYPE_PHYSICALADAPTERCAPS:15`

Reserved for system use. Do not use in your driver. This constant occurs starting in Windows 10.

### `DXGKQAITYPE_DISPLAY_DRIVERCAPS_EXTENSION:16`

Reserved for system use. Do not use in your driver. This constant occurs starting in Windows 10.

### `DXGKQAITYPE_INTEGRATED_DISPLAY_DESCRIPTOR:17`

Supported starting in Windows 10, version 1703. Indicates a request for an integrated panel descriptor where the input buffer to the query will be a [**DXGK_QUERYINTEGRATEDDISPLAYIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_qaitargetin) structure and the output buffer is a [**DXGK_QUERYINTEGRATEDDISPLAYOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_queryintegrateddisplayout2) structure.

Although this function addresses a target, only DxgKrnl adapter locks are taken over this call, not child device locks. In practice, since this call will be made before the child device is exposed, there should be no concurrent DDI calls which address the same target.

NOTE: Unlike most QueryAdapterInfo calls, the output buffer size is variable although it is still known in advance from the DescriptorLength field of the [**DXGK_INTEGRATED_DISPLAY_CHILD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_integrated_display_child) structure for the target id. The size of the output buffer is:
```DescriptorLength + FIELD_OFFSET( DXGK_QUERYINTEGRATEDDISPLAYOUT, Descriptor )```.

### `DXGKQAITYPE_UEFIFRAMEBUFFERRANGES:18`

Indicates request for the UEFI frame buffer ranges. Supported starting in Windows 10, version 1703.

### `DXGKQAITYPE_QUERYCOLORIMETRYOVERRIDES:19`

Supported starting in Windows 10, version 1703. Indicates a request for colorimetry overrides for an external display, where the input buffer to the query will be a [**DXGK_QUERYCOLORIMETRYOVERRIDESIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_qaitargetin) structure, containing only the target id being addressed and the output buffer is a [**DXGK_COLORIMETRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_colorimetry) structure into which the driver writes overrides for the monitor attached to the target.

Although this function addresses a target, only DxgKrnl adapter locks are taken over this call, not child device locks. Since this call will be made before the child device is exposed, there should be no concurrent DDI calls which address the same target.

The output buffer is zeroed when passed to the driver. If the driver has no overrides for the monitor, it should return STATUS_SUCCESS and leave the output buffer zeroed. If the driver has overrides, it fill in all fields of the DXGK_COLORIMETRY to describe the monitor capabilities as the OS will not accept partial overrides.

### `DXGKQAITYPE_DISPLAYID_DESCRIPTOR:20`

Indicates a request for an integrated panel descriptor where the input buffer to the query will be a [**DXGK_QAITARGETIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_qaitargetin) structure and the output buffer is a [**DXGK_QUERYINTEGRATEDDISPLAYOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_queryintegrateddisplayout2) structure. Supported starting in Windows 10, version 1709.

### `DXGKQAITYPE_FRAMEBUFFERSAVESIZE:21`

The KMD should populate a [**DXGK_FRAMEBUFFERSAVEAREA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_framebuffersavearea) structure with the size of the frame buffer to save to system memory during power transitions. Supported starting in Windows 10, version 1803.

### `DXGKQAITYPE_HARDWARERESERVEDRANGES:22`

The KMD should populate a [**DXGK_HARDWARERESERVEDRANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_hardwarereservedranges) structure with its hardware reserved memory ranges. Supported starting in Windows 10, version 1803.

### `DXGKQAITYPE_INTEGRATED_DISPLAY_DESCRIPTOR2:23`

Supported starting in Windows 10, version 1803. Indicates a request for an integrated panel descriptor where the input buffer to the query will be a [**DXGK_QAITARGETIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_qaitargetin) structure and the output buffer is a [**DXGK_QUERYINTEGRATEDDISPLAYOUT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_queryintegrateddisplayout2) structure. This query replaces use of the **DXGKQAITYPE_INTEGRATED_DISPLAY_DESCRIPTOR** query for WDDM 2.4 drivers.

[**TypeIntegratedDisplay** child devices](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-_dxgk_child_device_type) are reported by calling [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) with the *Type* set to this value.

### `DXGKQAITYPE_NODEPERFDATA:24`

The KMD should populate a [**DXGK_NODE_PERFDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_node_perfdata) structure that represents performance data collected per engine from an adapter on an interval basis. Supported starting in Windows 10, version 1803.

### `DXGKQAITYPE_ADAPTERPERFDATA:25`

The KMD should populate a [**DXGK_ADAPTER_PERFDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_adapter_perfdata) structure that represents performance data collected per adapter on an interval basis. Supported starting in Windows 10, version 1803.

### `DXGKQAITYPE_ADAPTERPERFDATA_CAPS:26`

The KMD should populate a [**DXGK_ADAPTER_PERFDATACAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_adapter_perfdatacaps) structure that represents data capabilities that are static and queried once per GPU during initialization. Supported starting in Windows 10, version 1803.

### `DXGKQAITYPE_GPUVERSION:27`

The KMD should populate a [**DXGK_GPUVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_gpuversion) structure used to collect the BIOS version and GPU architecture name once during GPU initialization. Supported starting in Windows 10, version 1803.

### `DXGKQAITYPE_DEVICE_TYPE_CAPS:28`

The KMD should populate a [**DXGK_DEVICE_TYPE_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_device_type_caps) structure that describes the type of capabilities for a device. Supported starting in Windows 10, version 1809.

### `DXGKQAITYPE_WDDMDEVICECAPS:29`

The KMD should populate a [**DXGK_WDDMDEVICECAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_wddmdevicecaps) structure that contains the WDDM capabilities that are queried by the OS during device initialization. Supported starting in Windows 10, version 1903.

### `DXGKQAITYPE_GPUPCAPS:30`

The KMD should populate a [**DXGK_GPUPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gpupcaps) structure that contains the GPU capabilities for a kernel mode display driver. Supported starting in Windows 10, version 1903.

### `DXGKQAITYPE_QUERYTARGETGAMMACAPS:31`

The KMD should populate a [**DXGK_TARGET_GAMMA_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_target_gamma_caps) structure that describes the gamma capabilities of The KMD. Supported starting in Windows 10, version 1903.

### `DXGKQAITYPE_SCANOUT_CAPS:33`

The KMD should populate a DXGK_QUERY_SCANOUT_CAPS_OUT structure that describes the scanout capabilities of the driver. Supported starting in Windows 10, version 1903.

### `DXGKQAITYPE_PHYSICAL_MEMORY_CAPS:34`

The KMD should populate a [**DXGK_PHYSICAL_MEMORY_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_physical_memory_caps) structure that describes the physical memory restrictions (the highest visible physical address) of the device. Supported starting in Windows Server 2022 (WDDM 2.9).

See **DXGKQAITYPE_IOMMU_CAPS** for details on how to indicate driver support for IOMMU linear remapping.

### `DXGKQAITYPE_IOMMU_CAPS:35`

The KMD should populate a [**DXGK_IOMMU_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_iommu_caps) structure that indicates that IOMMU linear remapping is supported by the driver. Supported starting in Windows Server 2022 (WDDM 2.9). To indicate support for linear remapping, the driver must also inform *Dxgkernel* about its physical memory restrictions through the **DXGKQAITYPE_PHYSICAL_MEMORY_CAPS** cap.

Logical remapping can only be done if no existing physical memory is referenced by the device, so *Dxgkrnl*'s call sequence is as follows:

* Call [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) for all physical adapters, so that the driver can gather information for all linked physical adapters.

* Call [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) with DXGKQAITYPE_PHYSICAL_MEMORY_CAPS and DXGKQAITYPE_IOMMU_CAPS so that it can then create and attach the device to an IOMMU domain before any memory can be accessed.

* Call [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) to start the device.

### `DXGKQAITYPE_HARDWARERESERVEDRANGES2:36`

### `DXGKQAITYPE_NATIVE_FENCE_CAPS:37`

The KMD should populate a [**DXGK_NATIVE_FENCE_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_native_fence_caps) structure that contains the driver's support details for native GPU fences. Supported starting in Windows 11, version 24H2. For more information, see [Native GPU fences](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

### `DXGKQAITYPE_USERMODESUBMISSION_CAPS:38`

The KMD should populate a [**DXGK_USERMODESUBMISSION_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_usermodesubmission_caps) structure that contains the driver's support details for user-mode work submission. Supported starting in Windows 11, version 24H2. For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

### `DXGKQAITYPE_DIRTYBITTRACKINGCAPS:39`

The KMD should populate a [**DXGK_DIRTY_BIT_TRACKING_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_dirty_bit_tracking_caps) structure that contains the driver's support details for dirty bit tracking. Supported starting in Windows 11, version 24H2. For more information, see [Dirty bit tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

### `DXGKQAITYPE_DIRTYBITTRACKINGSEGMENTCAPS:40`

The KMD should populate a [**DXGK_DIRTY_BIT_TRACKING_SEGMENT_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_dirty_bit_tracking_segment_caps) structure that contains the driver's support details for dirty bit tracking on a specific memory segment. Supported starting in Windows 11, version 24H2. For more information, see [Dirty bit tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

### `DXGKQAITYPE_SCATTER_RESERVE:41`

The KMD should populate a [**DXGK_QUERYSCATTERRESERVEOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_queryscatterreserveout) structure that contains the driver's support details for scatter reserve. Supported starting in Windows 11, version 24H2. For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

### `DXGKQAITYPE_QUERYPAGINGBUFFERINFO:42`

### `DXGKQAITYPE_QUERYSEGMENTCOUNT:43`

### `DXGKQAITYPE_QUERYSEGMENT5:44`

### `DXGKQAITYPE_QUERYMMUCOUNT:45`

### `DXGKQAITYPE_QUERYMMUS:46`

### `DXGKQAITYPE_64BITONLYCAPS:47`

### `DXGKQAITYPE_PAGINGPROCESSGPUVASIZE:48`

KMD should return the size of the paging process GPU VA space, in megabytes. For more information, see [Allocation Notification](https://learn.microsoft.com/windows-hardware/drivers/display/allocation-notification). Available starting in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

*Dxgkrnl* calls The KMD's [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) callback to retrieve configuration information from the graphics adapter. The driver fills the requested information in the buffer pointed to by the **pOutputData** member of the [**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo) structure. See each enumeration value for the type of structure to fill in.

## See also

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)