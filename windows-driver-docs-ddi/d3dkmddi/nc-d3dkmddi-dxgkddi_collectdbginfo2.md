## Description

The **DxgkDdiCollectDbgInfo2** function outputs driver information for a debug report.

## Parameters

### `hAdapter`

[in] A handle to a context block that is associated with a display adapter. The display miniport (KMD) previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device).

### `pCollectDbgInfo2`

[in/out] A pointer to a [**DXGKARG_COLLECTDBGINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_collectdbginfo2) structure that contains information for the debug report.

## Return value

**DxgkDdiCollectDbgInfo2** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| **STATUS_SUCCESS** | **DxgkDdiCollectDbgInfo2** successfully output driver information for a debug report; OR, the OS ignored the content in the buffer that [**pBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_collectdbginfo) points to and didn't add information from **DxgkDdiCollectDbgInfo2** to the debug report. |
| **STATUS_NO_MEMORY** | **DxgkDdiCollectDbgInfo2** couldn't allocate memory that was required for it to complete. |
| **STATUS_UNSUCCESSFUL** | Another error prevented the driver from collecting valid debug information. |

## Remarks

*Dxgkrnl* calls KMD's **DxgkDdiCollectDbgInfo2** function whenever the OS is about to generate a driver-related debug report. **DxgkDdiCollectDbgInfo2** might be called either immediately before [Timeout Detection and Recovery (TDR) work](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-changes-in-windows-8) or immediately before the OS bug checks. While **DxgkDdiCollectDbgInfo2** should return as quickly as possible, there is no system-defined maximum amount of time that the driver can spend in this function.

**DxgkDdiCollectDbgInfo2** receives more detailed information about the root cause of the TDR than [**DxgkDdiCollectDbgInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo) does. KMD can save state that is relevant to the part of the GPU responsible for the TDR.

* A WDDM 3.2 driver isn't required to implement **DxgkddiCollectDbgInfo2**, in which case the OS calls **DxgkddiCollectDbgInfo**.

KMD should collect debug information. When **DxgkDdiCollectDbgInfo2** is called, the driver receives a bug-check code in [**pCollectDbgInfo2->Reason**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_collectdbginfo) that indicates the type of information required for the debug report. The driver copies the required debug information into the buffer that **pCollectDbgInfo2->pBuffer** points to. The maximum number of bytes of information that the driver can copy is specified by **pCollectDbgInfo2->BufferSize**.

**DxgkDdiCollectDbgInfo** generally runs at an undefined IRQL. However, if **pCollectDbgInfo2->Reason** is set to [**VIDEO_TDR_TIMEOUT_DETECTED**](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x117---video-tdr-timeout-detected) (to indicate an adapter-wide reset) or [**VIDEO_ENGINE_TIMEOUT_DETECTED**](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x141---video-engine-timeout-detected) (available starting with Windows 8 to indicate a reset of one or more nodes within a physical adapter), the driver must ensure that **DxgkDdiCollectDbgInfo2** is pageable, runs at IRQL = **PASSIVE_LEVEL**, and supports [synchronization zero level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level).

For more information, see [TDR debuggability improvements](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-debuggability-improvements).

## See also

[**DXGKARG_COLLECTDBGINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_collectdbginfo2)

[**DxgkDdiCollectDbgInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo)