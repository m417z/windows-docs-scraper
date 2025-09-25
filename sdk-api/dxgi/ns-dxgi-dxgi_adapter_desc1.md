# DXGI_ADAPTER_DESC1 structure

## Description

Describes an adapter (or video card) using DXGI 1.1.

## Members

### `Description`

Type: **WCHAR[128]**

A string that contains the adapter description. On [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9 graphics hardware, [GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter1-getdesc1) returns “Software Adapter” for the description string.

### `VendorId`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The PCI ID or ACPI ID of the adapter's hardware vendor. If this value is less than or equal to 0xFFFF, it is a PCI ID; otherwise, it is an ACPI ID. On [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9 graphics hardware, [GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter1-getdesc1) returns zero for this value.

### `DeviceId`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The PCI ID or ACPI ID of the adapter's hardware device. If **VendorId** is a PCI ID, it is also a PCI ID; otherwise, it is an ACPI ID. On [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9 graphics hardware, [GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter1-getdesc1) returns zero for this value.

### `SubSysId`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The PCI ID or ACPI ID of the adapter's hardware subsystem. If **VendorId** is a PCI ID, it is also a PCI ID; otherwise, it is an ACPI ID. On [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9 graphics hardware, [GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter1-getdesc1) returns zero for this value.

### `Revision`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The adapter's PCI or ACPI revision number. If **VendorId** is a PCI ID, it is a PCI device revision number; otherwise, it is an ACPI device revision number. On [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9 graphics hardware, [GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter1-getdesc1) returns zero for this value.

### `DedicatedVideoMemory`

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bytes of dedicated video memory that are not shared with the CPU.

### `DedicatedSystemMemory`

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bytes of dedicated system memory that are not shared with the CPU. This memory is allocated from available system memory at boot time.

### `SharedSystemMemory`

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bytes of shared system memory. This is the maximum value of system memory that may be consumed by the adapter during operation. Any incidental memory consumed by the driver as it manages and uses video memory is additional.

### `AdapterLuid`

Type: **[LUID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549708(v=vs.85))**

A unique value that identifies the adapter. See [LUID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549708(v=vs.85)) for a definition of the structure. **LUID** is defined in dxgi.h.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value of the [DXGI_ADAPTER_FLAG](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_adapter_flag) enumerated type that describes the adapter type. The **DXGI_ADAPTER_FLAG_REMOTE** flag is reserved.

## Remarks

The **DXGI_ADAPTER_DESC1** structure provides a DXGI 1.1 description of an adapter. This structure is initialized by using the [IDXGIAdapter1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter1-getdesc1) method.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)

[IDXGIAdapter1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiadapter1-getdesc1)