# DXGKARG_COLLECTDBGINFO structure

## Description

The **DXGKARG_COLLECTDBGINFO** structure describes information for a debug report.

## Members

### `Reason` [in]

The [bug-check code](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2) for which to return debug information in the buffer that **pBuffer** points to. These are possible values:

| Value | Meaning |
| ----- | ------- |
| **VIDEO_TDR_TIMEOUT_DETECTED** 0x117|A [**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine) operation has reset a logical adapter. |
| **VIDEO_ENGINE_TIMEOUT_DETECTED** 0x141|A [**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine) operation has reset one or more nodes within a physical adapter. Available starting in Windows 8. |

### `pBuffer` [out]

A pointer to a buffer that receives the debug information for the reason that **Reason** specifies.

### `BufferSize` [in]

The maximum size, in bytes, to copy to the buffer that **pBuffer** points to.

### `pExtension` [out]

A pointer to an OS-allocated [**DXGKARG_COLLECTDBGINFO_EXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_collectdbginfo_ext) structure that the driver optionally populates with debug extension information.

## Remarks

See [**DxgkDdiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2) for extended TDR debug information.

## See also

[**DXGKARG_COLLECTDBGINFO_EXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_collectdbginfo_ext)

[**DxgkDdiCollectDbgInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo)

[**DxgkDdiCollectDbgInfo2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_collectdbginfo2)

[**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine)