## Description

A kernel-mode display miniport driver (KMD) returns the GPU's native fence capabilities in **DXGK_NATIVE_FENCE_CAPS** when its [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function is called with the [**DXGKQAITYPE_NATIVE_FENCE_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype) query adapter info type.

## Members

### `MonitoredValueStride`

To save memory, the OS packs non-shareable native GPU fence objects together into the same memory page. **MonitoredValueStride** specifies the stride in bytes between OS-managed storage for different fence objects sharing the same memory page.

### `MapToGpuSystemProcess`

Specifies whether native fence current and monitored values should be mapped to a GPU system process address space for use by the context management processor.

### `MinimumAddress`

Minimum virtual address for GPU VA mappings (optional).

### `MaximumAddress`

Maximum virtual address for GPU VA mappings (optional).

### `Reserved[28]`

Reserved for system use.

## Remarks

The **CurrentValueStride** and **MonitoredValueStride** values specify the stride in bytes between OS-managed storage for different fence objects sharing the same memory page.

When the driver sets **MapToGpuSystemProcess**, it's instructing the OS to reserve a system process GPU virtual address space for the context management processor to use, and to create GPU VA mappings into that address space for native fence **CurrentValue** and **MonitoredValue**. These GPU VAs are subsequently passed to the KMD fence creation callback as [**DXGKARG_CREATENATIVEFENCE's**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createnativefence) **CurrentValueSystemProcessGpuVa** and **MonitoredValueSystemProcessGpuVa**.

The KMD can also specify an optional **MinimumAddress** and **MaximumAddress** to restrict native fence GPU VA mappings within a chosen range for both process address space and system address space. This limit will apply to all native fences created on the system.

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[**DXGKQAITYPE_NATIVE_FENCE_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)