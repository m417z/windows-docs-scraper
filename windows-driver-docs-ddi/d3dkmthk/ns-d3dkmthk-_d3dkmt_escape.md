# D3DKMT_ESCAPE structure

## Description

The **D3DKMT_ESCAPE** structure describes information that is exchanged between a user-mode display driver (UMD) (or client driver) and the kernel-mode display miniport driver (KMD).

## Members

### `hAdapter` [in]

A handle to the graphics adapter that information is exchanged on.

### `hDevice` [in]

A handle to a display device that is optionally specified if the information to be exchanged is specific to a particular device.

### `Type` [in]

A [**D3DKMT_ESCAPETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_escapetype) enumeration value that indicates either to exchange information with the KMD or to control kernel-mode components. The following table shows the possible values.

| **Value** | **Meaning** |
|:--|:--|
| D3DKMT_ESCAPE_DRIVERPRIVATE (0) | The **pPrivateDriverData** member is targeted at the KMD. The hardware vendor defines the format of the escape data. |
| D3DKMT_ESCAPE_VIDMM (1) | Don't use; for testing purposes only. The UMD/client driver controls the video memory manager (*VidMm*). The buffer that **pPrivateDriverData** points to contains a [D3DKMT_VIDMM_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_vidmm_escape) structure that supports various types of control of *VidMm*. |
| D3DKMT_ESCAPE_TDRDBGCTRL (2) | Don't use; for testing purposes only. The escape operation lets the user control the behavior of the operating system's Timeout Detection and Recovery (TDR) process. This functionality is disabled by default. To enable this functionality, the TdrTestMode = TdrTestMode DWORD registry value, which is stored in the HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\GraphicsDrivers key, must be set to 1. The **PrivateDriverDataSize** member is set to sizeof(int). The **pPrivateDriverData** member is set to an integer with a value from the [D3DKMT_TDRDBGCTRLTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_tdrdbgctrltype) enumeration type. |
| D3DKMT_ESCAPE_VIDSCH (3) | Don't use; for testing purposes only. The UMD/client driver controls the GPU scheduler (which is part of *Dxgkrnl*). The buffer that **pPrivateDriverData** points to contains a [D3DKMT_VIDSCH_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_vidsch_escape) structure that supports preemption control and suspending or resuming the scheduler. |
| D3DKMT_ESCAPE_DEVICE (4) | Don't use; for testing purposes only. The UMD/client driver controls the display device. The buffer that **pPrivateDriverData** points to contains a [D3DKMT_DEVICE_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_device_escape) structure that supports obtaining the video present source from the primary allocation. |
| D3DKMT_ESCAPE_DMM (5) | Don't use; for testing purposes only. The UMD/client driver controls the display mode manager. The buffer that **pPrivateDriverData** points to contains a [D3DKMT_DMM_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_dmm_escape) structure. |
| D3DKMT_ESCAPE_DEBUG_SNAPSHOT (6) | Don't use; for testing purposes only. The UMD/client driver retrieves a debug snapshot buffer. The buffer that **pPrivateDriverData** points to contains a [D3DKMT_DEBUG_SNAPSHOT_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_debug_snapshot_escape) structure. |
| D3DKMT_ESCAPE_SETDRIVERUPDATESTATUS (7) | Don't use; for testing purposes only. The UMD/client driver sets the KMD update status. |
| D3DKMT_ESCAPE_DRT_TEST (8) | Don't use; for testing purposes only. |
| D3DKMT_ESCAPE_DIAGNOSTICS (9) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_OUTPUTDUPL_SNAPSHOT (10) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_OUTPUTDUPL_DIAGNOSTICS (11) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_BDD_PNP (12) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_BDD_FALLBACK (13) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_ACTIVATE_SPECIFIC_DIAG(14) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_MODES_PRUNED_OUT(15) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_WQHL_INFO(16) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_BRIGHTNESS(17) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_EDID_CACHE(18) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_GENERIC_ADAPTER_DIAG_INFO(19) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_MIRACAST_DISPLAY_REQUEST (20) | Don't use; for testing purposes only. Supported starting with Windows 8.1. |
| D3DKMT_ESCAPE_HISTORY_BUFFER_STATUS (21) | Don't use; for testing purposes only. Supported starting with Windows 8.1. |
| D3DKMT_ESCAPE_MIRACAST_ADAPTER_DIAG_INFO (23) | Don't use; for testing purposes only. Supported starting with Windows 8.1. |
| D3DKMT_ESCAPE_WIN32K_START(1024) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_WIN32K_HIP_DEVICE_INFO(1024) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_WIN32K_QUERY_CD_ROTATION_BLOCK (1025) | Don't use; for testing purposes only. Supported starting with Windows 8. |
| D3DKMT_ESCAPE_WIN32K_DPI_INFO (1026) | Don't use; for testing purposes only. Supported starting with Windows 8.1. |
| D3DKMT_ESCAPE_WIN32K_PRESENTER_VIEW_INFO (1027) | Don't use; for testing purposes only. Supported starting with Windows 8.1. |
| D3DKMT_ESCAPE_WIN32K_SYSTEM_DPI (1028) | Don't use; for testing purposes only. Supported starting with Windows 8.1. |

### `Flags` [in]

A [**D3DDDI_ESCAPEFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_escapeflags) structure that indicates, in bit-field flags, how to share information. The UMD/client driver should specify the **HardwareAccess** bit-field flag to indicate that the KMD must access graphics hardware in such a way that the OS must perform the [second level of synchronization](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level) into the KMD for the [**DxgkDdiEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape) call.

**HardwareAccess** should be set to zero when virtualization is being used. For more information, see [GPU paravirtualization](https://learn.microsoft.com/windows-hardware/drivers/display/gpu-paravirtualization).

### `pPrivateDriverData` [in/out]

A pointer to a buffer that the UMD or client driver allocates that contains a known driver escape structure. This structure contains information that the driver either exchanges with the KMD or uses to control kernel-mode components. The following table describes the content of the buffer that **pPrivateDriverData** points to, depending on the value of **Type**.

| Value of Type | Content of the pPrivateDriverData buffer |
|:--|:--|
| D3DKMT_ESCAPE_DRIVERPRIVATE | Driver-specific. The buffer isn't usable unless a tight coupling exists between the UMD/client driver and the KMD. |
| D3DKMT_ESCAPE_VIDMM | Don't use; for testing purposes only. A [D3DKMT_VIDMM_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_vidmm_escape) structure. |
| D3DKMT_ESCAPE_TDRDBGCTRL | Don't use; for testing purposes only. A [D3DKMT_TDRDBGCTRLTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_tdrdbgctrltype) enumeration type. |
| D3DKMT_ESCAPE_VIDSCH | Don't use; for testing purposes only. A [D3DKMT_VIDSCH_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_vidsch_escape) structure. |
| D3DKMT_ESCAPE_DEVICE | Don't use; for testing purposes only. A [D3DKMT_DEVICE_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_device_escape) structure. |
| D3DKMT_ESCAPE_DMM | Don't use; for testing purposes only. A [D3DKMT_DMM_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_dmm_escape) structure. |
| D3DKMT_ESCAPE_DEBUG_SNAPSHOT | Don't use; for testing purposes only. A [**D3DKMT_DEBUG_SNAPSHOT_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_debug_snapshot_escape) structure. |

### `PrivateDriverDataSize` [in]

The size, in bytes, of the buffer that **pPrivateDriverData** points to. The UMD/client driver must specify the size of the buffer when it calls the [**D3DKMTEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape) function.

### `hContext` [in]

A handle to a context that is optionally specified if the information to be exchanged is specific to a particular device context. If the UMD/client driver sets **hContext** to a non-NULL value, the driver must have also set **hDevice** to a non-NULL value, and **hDevice** must correspond to the device that owns the context.

## See also

[**D3DKMTEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape)

[**D3DKMT_DEBUG_SNAPSHOT_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_debug_snapshot_escape)

[**D3DKMT_DEVICE_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_device_escape)

[**D3DKMT_DMM_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_dmm_escape)

[**D3DKMT_TDRDBGCTRLTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_tdrdbgctrltype)

[**D3DKMT_VIDMM_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_vidmm_escape)

[**D3DKMT_VIDSCH_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_vidsch_escape)