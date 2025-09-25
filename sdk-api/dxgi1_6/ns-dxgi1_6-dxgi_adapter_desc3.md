# DXGI_ADAPTER_DESC3 structure

## Description

Describes an adapter (or video card) that uses Microsoft DirectX Graphics Infrastructure (DXGI) 1.6.

## Members

### `Description`

A string that contains the adapter description.

### `VendorId`

The PCI ID or ACPI ID of the adapter's hardware vendor. If this value is less than or equal to 0xFFFF, it is a PCI ID; otherwise, it is an ACPI ID.

### `DeviceId`

The PCI ID or ACPI ID of the adapter's hardware device. If **VendorId** is a PCI ID, it is also a PCI ID; otherwise, it is an ACPI ID.

### `SubSysId`

The PCI ID or ACPI ID of the adapter's hardware subsystem. If **VendorId** is a PCI ID, it is also a PCI ID; otherwise, it is an ACPI ID.

### `Revision`

The adapter's PCI or ACPI revision number. If **VendorId** is a PCI ID, it is a PCI device revision number; otherwise, it is an ACPI device revision number.

### `DedicatedVideoMemory`

The number of bytes of dedicated video memory that are not shared with the CPU.

### `DedicatedSystemMemory`

The number of bytes of dedicated system memory that are not shared with the CPU. This memory is allocated from available system memory at boot time.

### `SharedSystemMemory`

The number of bytes of shared system memory. This is the maximum value of system memory that may be consumed by the adapter during operation. Any incidental memory consumed by the driver as it manages and uses video memory is additional.

### `AdapterLuid`

A unique value that identifies the adapter. See [LUID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549708(v=vs.85)) for a definition of the structure. **LUID** is defined in dxgi.h.

### `Flags`

A value of the [DXGI_ADAPTER_FLAG3](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/ne-dxgi1_6-dxgi_adapter_flag3) enumeration that describes the adapter type. The **DXGI_ADAPTER_FLAG_REMOTE** flag is reserved.

### `GraphicsPreemptionGranularity`

A value of the [DXGI_GRAPHICS_PREEMPTION_GRANULARITY](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_graphics_preemption_granularity) enumerated type that describes the granularity level at which the GPU can be preempted from performing its current graphics rendering task.

### `ComputePreemptionGranularity`

A value of the [DXGI_COMPUTE_PREEMPTION_GRANULARITY](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_compute_preemption_granularity) enumerated type that describes the granularity level at which the GPU can be preempted from performing its current compute task.

## Remarks

The **DXGI_ADAPTER_DESC3** structure provides a DXGI 1.6 description of an adapter. This structure is initialized by using the [IDXGIAdapter4::GetDesc3](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/nf-dxgi1_6-idxgiadapter4-getdesc3) method.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)

[IDXGIAdapter4::GetDesc3](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/nf-dxgi1_6-idxgiadapter4-getdesc3)