# D3DKMTEscape function

## Description

The **D3DKMTEscape** function exchanges information between the user-mode display driver (UMD) (or client driver) and the kernel-mode display miniport driver (KMD).

## Parameters

### `unnamedParam1` [in]

Pointer to a [**D3DKMT_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_escape) structure that describes the exchanged information.

## Return value

**D3DKMTEscape** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | Information was successfully shared. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |
| STATUS_NO_MEMORY | **D3DKMTEscape** could not complete because of insufficient memory. |
| STATUS_PRIVILEGED_INSTRUCTION | **D3DKMTEscape** detected non-privileged instructions (that is, instructions that access memory beyond the privilege of the current CPU process). |
| STATUS_ILLEGAL_INSTRUCTION | **D3DKMTEscape** detected instructions that cannot be supported by graphics hardware. |

This function might also return other **NTSTATUS** values.

## Remarks

The UMD or client driver calls **D3DKMTEscape** to exchange data directly with the KMD. For testing purposes, **D3DKMTEscape** can be called to control the video memory manager (*VidMm*) and GPU scheduler (which are part of *Dxgkrnl.sys*) and the behavior of the operating system's Timeout Detection and Recovery (TDR) process.

Hardware vendors can use **D3DKMTEscape** in their drivers as an extension mechanism. However, vendors should report necessary extensions to Microsoft so the extensions can be natively supported by the operating system.

## See also

[**D3DKMT_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_escape)