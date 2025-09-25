# DXGKCB_MIRACAST_REPORT_CHUNK_INFO callback function

## Description

Called by the display miniport driver to report info about an encode chunk.

## Parameters

### `MiracastHandle` [in]

A driver-supplied handle to the Miracast display device. This handle was originally passed in the **MiracastHandle** member of the [DXGK_MIRACAST_DISPLAY_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_display_callbacks) structure in a call to the [DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context) function.

### `pChunkInfo` [in]

A pointer to a [DXGK_MIRACAST_CHUNK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_miracast_chunk_info) structure that contains chunk information that is to be reported by the display miniport driver.

### `pPrivateDriverData` [in]

Reserved for system use. Must be set to **NULL**.

### `PrivateDataDriverSize` [in]

Reserved for system use. Must be set to zero.

## Return value

Returns **STATUS_SUCCESS** if it successfully delivers the message. Otherwise, it returns one of the error codes that are defined in Ntstatus.h.

## Remarks

The display miniport driver calls this function when it wants to report chunk info to the operating system but won't create a chunk packet that will be queued in kernel mode and retrieved by the user-mode [GetNextChunkData](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_get_next_chunk_data) function. This call only logs Event Tracing for Windows (ETW) events and takes no other action.

## See also

[DXGK_MIRACAST_CHUNK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_miracast_chunk_info)

[DXGK_MIRACAST_DISPLAY_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_display_callbacks)

[DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context)

[GetNextChunkData](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_get_next_chunk_data)