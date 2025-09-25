# D3DDDI_DRIVERESCAPETYPE enumeration

## Description

**D3DDDI_DRIVERESCAPETYPE** defines the known driver escape types ([**D3DDDI_ESCAPEFLAGS::DriverKnownEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_escapeflags)).

## Constants

### `D3DDDI_DRIVERESCAPETYPE_TRANSLATEALLOCATIONHANDLE:0`

Driver escape type to translate allocation handle; used to translate the guest allocation to the corresponding host handle. For more information, see [GPU paravirtualization](https://learn.microsoft.com/windows-hardware/drivers/display/gpu-paravirtualization).

### `D3DDDI_DRIVERESCAPETYPE_TRANSLATERESOURCEHANDLE:1`

Driver escape type to translate resource handle; used to translate the resource handle to the corresponding host handle. For more information, see [GPU paravirtualization](https://learn.microsoft.com/windows-hardware/drivers/display/gpu-paravirtualization).

### `D3DDDI_DRIVERESCAPETYPE_CPUEVENTUSAGE:2`

Driver escape type for CPU event usage; used to notify the kernel-mode driver (KMD) about the intended use of a KMD CPU event object. Available starting in Windows 11 (WDDM 3.0). See [Signaling a CPU event from KMD](https://learn.microsoft.com/windows-hardware/drivers/display/signaling-cpu-event-from-kmd) for more information.

### `D3DDDI_DRIVERESCAPETYPE_BUILDTESTCOMMANDBUFFER:3`

Driver escape type for building a test command buffer; used to build a test command buffer for kernel-mode testing. Available starting in Windows 11, version 24H2 (WDDM 3.2). See [Kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features) for more information.

### `D3DDDI_DRIVERESCAPETYPE_MAX`

The maximum value for this enumeration.

## See also

[**D3DDDI_DRIVERESCAPE_CPUEVENTUSAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_driverescape_cpueventusage)

[**D3DDDI_DRIVERESCAPETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_driverescapetype)

[**DXGKARG_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_escape)

[**DXGKDDI_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape)