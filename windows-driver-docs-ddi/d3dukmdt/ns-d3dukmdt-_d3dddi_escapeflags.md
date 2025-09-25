# D3DDDI_ESCAPEFLAGS structure

## Description

The **D3DDDI_ESCAPEFLAGS** structure identifies how the user-mode display driver (UMD) (or client driver) shares information with the kernel-mode display miniport driver (KMD).

## Members

### `HardwareAccess`

A UINT value that specifies whether the OS performs the [second level of synchronization](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level) into the KMD for the [**DxgkDdiEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape) call. If the driver requires the second level of synchronization and the **HardwareAccess** flag isn't set, the call to the driver's **DxgkDdiEscape** function should fail.

Starting in Windows 8.1, if this member is set, **DeviceStatusQuery** and **ChangeFrameLatency** must be set to zero.

### `DeviceStatusQuery`

If set, when the [**pfnEscapeCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb) function is called and the [**D3DDDICB_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_escape).**PrivateDriverDataSize** member is ```sizeof(D3DDDI_EXECUTIONSTATEESCAPE)```, the Direct3D runtime interprets the **D3DDDICB_ESCAPE**.**pPrivateDriverData** member as a pointer to a buffer that contains a [**D3DDDI_EXECUTIONSTATEESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_executionstateescape) structure. In addition, the runtime processes the **pfnEscapeCb** as a status query by writing the requested info into the provided buffer instead of sending a [**DxgkDdiEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape) call to the KMD.

If this member is set, **HardwareAccess** and **ChangeFrameLatency** must be set to zero.

Supported starting with Windows 8.1.

The operating system ignores this member if it is prior to Windows 8.1, or if the user-mode driver was initialized with an **OpenAdapterXxx** call where the **pOpenData**->**Interface** member indicates Direct3D version 8 or earlier.

### `ChangeFrameLatency`

If set, when the [**pfnEscapeCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb) function is called, the [**D3DDDICB_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_escape).**PrivateDriverDataSize** member is ```sizeof(D3DDDI_FRAMELATENCYESCAPE)``` and conditions in Remarks are also met, the Direct3D runtime interprets the **D3DDDICB_ESCAPE**.**pPrivateDriverData** member as a pointer to a buffer that contains a [**D3DDDI_FRAMELATENCYESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_framelatencyescape) structure. In addition, the runtime processes the **pfnEscapeCb** as a request to change the DirectX graphics kernel subsystem's maximum frame latency by writing the requested info into the provided buffer instead of sending a [**DxgkDdiEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape) call to the KMD.

If this member is set, **HardwareAccess** and **DeviceStatusQuery** must be set to zero.

Supported starting with Windows 8.1.

The operating system ignores this member if it is prior to Windows 8.1, or if the user-mode driver was initialized with an **OpenAdapterXxx** call where the **pOpenData**->**Interface** member indicates Direct3D version 8 or earlier.

### `NoAdapterSynchronization`

### `VirtualMachineData`

Indicates that [**DxgkDdiEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape) is called from a virtual machine. This flag can't be set from user mode. Supported starting with WDDM 2.2.

### `DriverKnownEscape`

The driver private data points to a well known structure.

### `DriverCommonEscape`

The private data points to a D3D runtime-defined structure.

### `Reserved2`

This member is reserved and should be set to zero.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

A member in the union that is contained in D3DDDI_ESCAPEFLAGS that can hold one 32-bit value that identifies how to share information.

## Remarks

If **ChangeFrameLatency** is set, a [**pfnEscapeCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb) call will succeed only if:

* The KMD is responsible for a linked adapter configuration (LDA) provided by a single vendor.
* The app has taken exclusive full-screen ownership of the display at some point in its lifetime.
* The app has not overridden the default maximum frame latency value of 3.

If these conditions are not met, **pfnEscapeCb** call returns an E_INVALIDARG error code.

## See also

[**D3DDDICB_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_escape)

[**D3DDDI_EXECUTIONSTATEESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_executionstateescape)

[**D3DDDI_FRAMELATENCYESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_framelatencyescape)

[**DXGKARG_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_escape)

[**DxgkDdiEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape)

[**pfnEscapeCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb)