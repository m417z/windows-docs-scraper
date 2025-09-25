# DXGK_MIRACAST_DISPLAY_CALLBACKS structure

## Description

The **DXGK_MIRACAST_DISPLAY_CALLBACKS** structure contains pointers to functions that define the wireless display (Miracast) callback interface that the display miniport driver can call to send messages and report encode chunk info.

## Members

### `MiracastHandle`

A driver-supplied handle to the Miracast display device.

### `DxgkCbMiracastSendMessage`

A pointer to the display port driver's [**DxgkCbMiracastSendMessage**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_send_message) function.

### `DxgkCbReportChunkInfo`

A pointer to the display port driver's [**DxgkCbReportChunkInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_report_chunk_info) function.