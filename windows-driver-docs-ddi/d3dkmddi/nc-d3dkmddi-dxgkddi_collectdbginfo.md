# DXGKDDI_COLLECTDBGINFO callback function

## Description

The **DxgkDdiCollectDbgInfo** function outputs driver information for a debug report.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport (KMD) previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device).

### `pCollectDbgInfo` [in/out]

A pointer to a [**DXGKARG_COLLECTDBGINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_collectdbginfo) structure that contains information for the debug report.

## Return value

**DxgkDdiCollectDbgInfo** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| **STATUS_SUCCESS** | **DxgkDdiCollectDbgInfo** successfully output driver information for a debug report; OR, the OS ignored the content in the buffer that [**pBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_collectdbginfo) points to and didn't add information from **DxgkDdiCollectDbgInfo** to the debug report. |
| **STATUS_NO_MEMORY** | **DxgkDdiCollectDbgInfo** couldn't allocate memory that was required for it to complete. |
| **STATUS_UNSUCCESSFUL** | Another error prevented the driver from collecting valid debug information. |

## Remarks

*Dxgkrnl* calls KMD's **DxgkDdiCollectDbgInfo** function whenever the OS is about to generate a driver-related debug report. **DxgkDdiCollectDbgInfo** might be called either immediately before [Timeout Detection and Recovery (TDR) work](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-changes-in-windows-8) or immediately before the OS bug checks. While **DxgkDdiCollectDbgInfo** should return as quickly as possible, there is no system-defined maximum amount of time that the driver can spend in this function.

KMD should collect debug information. When **DxgkDdiCollectDbgInfo** is called, the driver receives a bug-check code in [**pCollectDbgInfo->Reason**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_collectdbginfo) that indicates the type of information required for the debug report. The driver copies the required debug information into the buffer that **pCollectDbgInfo->pBuffer** points to. The maximum number of bytes of information that the driver can copy is specified by **pCollectDbgInfo->BufferSize**.

**DxgkDdiCollectDbgInfo** generally runs at an undefined IRQL. However, if **pCollectDbgInfo->Reason** is set to [**VIDEO_TDR_TIMEOUT_DETECTED**](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x117---video-tdr-timeout-detected) (to indicate an adapter-wide reset) or [**VIDEO_ENGINE_TIMEOUT_DETECTED**](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x141---video-engine-timeout-detected) (available starting with Windows 8 to indicate a reset of one or more nodes within a physical adapter), the driver must ensure that **DxgkDdiCollectDbgInfo** is pageable, runs at IRQL = **PASSIVE_LEVEL**, and supports [synchronization zero level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level).

## See also

[**DXGKARG_COLLECTDBGINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_collectdbginfo)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiResetFromTimeout**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetfromtimeout)