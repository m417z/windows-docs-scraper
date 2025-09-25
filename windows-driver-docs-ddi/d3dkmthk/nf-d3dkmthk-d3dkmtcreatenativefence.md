## Description

The D3D runtime calls **D3DKMTCreateNativeFence** to create a native GPU fence object on a particular device.

## Parameters

### `unnamedParam1`

[in/out] Pointer to a [**D3DKMT_CREATENATIVEFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_createnativefence) structure that describes the fence object to create.

## Return value

**D3DKMTCreateNativeFence** returns STATUS_SUCCESS on successful creation. Otherwise it returns an NTSTATUS error code such as STATUS_INVALID_PARAMETER.

## Remarks

The specified [**D3DDDI_NATIVEFENCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_nativefence_type) dictates the type of native fence that the OS creates. These fences differ in functionality, performance characteristics, and storage requirements for **CurrentValue** and **MonitoredValue**. The following table shows these differences, where CVal stands for **CurrentValue** and MVal stands for **MonitoredValue**.

| Type | CurrentValue | MonitoredValue | Supports Cross-process Sharing on CPU | Supports Cross-Adapter Sharing | UM CPUVA CVal | KM CPUVA CVal | GPU VA CVal | CMPVA CVal | UM MVal | KM MVal | GPU VA MVal | CMPVA MVal | Use Case |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| **D3DDDI_NATIVEFENCE_TYPE_DEFAULT** | Sysmem | Sysmem | Yes | Yes | ReadOnly | Read/Write | Read/Write | Read/Write | N/A | Write | ReadOnly (or Read/Write) | Read/Write | Application fences with reduced CPU interrupts. GPU waiter is unblocked without waking up CPU |
| **D3DDDI_NATIVEFENCE_TYPE_DEFAULT** (*OPTIMIZED*) | Sysmem | VRAM | Yes | Yes | ReadOnly | Read/Write | Read/Write | Read/Write | N/A | Write | ReadOnly (or Read/Write) | Read/Write | Same as Type 0 but with reduced PCI bus traffic as MVal reads are local to the GPU. The GPU signal command completes faster because of this reduced latency (throughput++). |
| **D3DDDI_NATIVEFENCE_TYPE_INTRA_GPU** | VRAM | VRAM | Yes | No | N/A | N/A | Read/Write | Read/Write | N/A | N/A | ReadOnly (or Read/Write) | Read/Write | Command buffer level (not application visible) synchronization within the same GPU. Read/Write to fence value (CVal) is local, so signal/unblock operations are fast. |

* **D3DDDI_NATIVEFENCE_TYPE_DEFAULT**
  * Supported in Windows 11, version 24H2.
  * This fence type supports all existing D3DKMT sync object Wait/Signal from CPU/GPU operations.
  * Both **CurrentValue** and **MonitoredValue** storage for this fence type are allocated in system memory segment.

* **D3DDDI_NATIVEFENCE_TYPE_DEFAULT** (*Optimized*)
  * This capability is not currently supported by the OS.
  * The optimized version of **D3DDDI_NATIVEFENCE_TYPE_DEFAULT**, in which the **MonitoredValue** storage can be allocated in VRAM, will speed up reads of **MonitoredValue** from the GPU engine.
  * This optimization is not exposed to UMD. Instead, *Dxgkrnl* and KMD will decide whether the default fence type can be optimized by allocating MonitoredValue storage in VRAM.
  * **MonitoredValue** storage allocated in VRAM may still be demoted to system memory if the system is under local memory pressure.
  * If the OS supports this fence type, it sets **SupportOptimizedDefaultFenceType** to TRUE in the [**DXGKARGCB_FEATURE_NATIVEFENCE_CAPS_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_feature_nativefence_caps_1) feature interface table. KMD is expected to query the feature interface table during driver initialization to determine this OS capability.

* **D3DDDI_NATIVEFENCE_TYPE_INTRA_GPU**
  * This capability is not currently supported by the OS.
  * A **D3DDDI_NATIVEFENCE_TYPE_INTRA_GPU** fence doesn't support any CPU operations; that is, the OS doesn't allow user mode to queue wait and signals to this fence object.
  * Hence, this type can't be used for DX application fences that must support CPU wait and signal semantics. This type is mainly used for internal UMD fences for synchronization between GPU engines. Creating this type as a D3DKMT native fence object provides visibility into these fences for tools such as *GpuView* and debugging.
  * The supported segment for this fence must be a non-CPU visible local memory segment.
  * Storage allocated in local memory may still be demoted to system memory if the system is under local memory pressure.
  * If the OS supports this fence type, it sets **SupportIntraGpuFenceType** to TRUE in the [**DXGKARGCB_FEATURE_NATIVEFENCE_CAPS_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_feature_nativefence_caps_1) feature interface table. KMD is expected to query the feature interface table during driver initialization to determine this OS capability.

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**D3DKMT_CREATENATIVEFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_createnativefence)

[**D3DKMTOpenNativeFenceFromNTHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopennativefencefromnthandle)

[**D3DKMTDestroySynchronizationObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroysynchronizationobject)

[**DxgkDdiCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createnativefence)