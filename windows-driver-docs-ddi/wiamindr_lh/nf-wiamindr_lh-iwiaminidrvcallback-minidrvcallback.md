## Description

The **MiniDrvCallback** method provides a callback method for WIA minidrivers to use during a callback data transfer.

## Parameters

### `lReason` [in]

Specifies a constant value that designates a callback status message. This value is used to determine the purpose of the callback, and can be one of the following values:

| Message | Definition |
|--|--|
| IT_MSG_DATA | Indicates that the transfer buffer contains a block of data. |
| IT_MSG_DATA_HEADER | Received before any data transfers. Indicates that the transfer buffer points to a [WIA_DATA_CALLBACK_HEADER](https://learn.microsoft.com/windows/win32/api/wia_xp/ns-wia_xp-wia_data_callback_header) structure that defines elements of the data transfer. |
| IT_MSG_DEVICE_STATUS | Callback contains only status information about the device. |
| IT_MSG_FILE_PREVIEW_DATA | Indicates preview data is being transferred to the application. |
| IT_MSG_FILE_PREVIEW_DATA_HEADER | Indicates a header is being transferred to the application, prior to the preview data being transferred. |
| IT_MSG_NEW_PAGE | Indicates that the data transfer of a page is complete, and a new page is being sent. |
| IT_MSG_STATUS | Callback contains only status information about the transfer. |
| IT_MSG_TERMINATION | Indicates that the data transfer is complete. |

### `lStatus` [in]

Specifies the status of the transfer. This parameter is a bitwise OR of the following values:

| Status | Definition |
|--|--|
| IT_STATUS_TRANSFER_FROM_DEVICE | Transferring data from device. |
| IT_STATUS_PROCESSING_DATA | Device and/or minidriver are processing the data. |
| IT_STATUS_TRANSFER_TO_CLIENT | Transferring data from the minidriver to the WIA service. |

### `lPercentComplete` [in]

Specifies the current percentage of data transferred.

### `lOffset` [in]

Specifies the current offset (in bytes) into the transfer buffer from the beginning of the buffer.

### `lLength` [in]

Specifies the number of bytes contained in the transfer.

### `pTranCtx` [in]

Points to a [MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context) structure containing the data transfer values.

### `lReserved` [in]

Reserved. Set to zero.

## Return value

If the method succeeds, it returns **S_OK**. If the callback is canceled by the client application, the method returns **S_FALSE**. If the method fails, it returns a standard COM error code.

## Remarks

The percent complete values are sent directly from the driver. The WIA service does not adjust the values.

**IT_MSG_FILE_PREVIEW_DATA_HEADER** is for out-of-band-data. This allows the application doing a file transfer to display the banded data. This is useful for scroll-fed scanners that have an unknown length and no preview scan. The information reported in this message should be treated the same as **IT_MSG_DATA_HEADER**. If a driver supports this message, it can supply preview data during its file transfer.

## See also

[IWiaMiniDrvCallBack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nn-wiamindr_lh-iwiaminidrvcallback)

[MINIDRV_TRANSFER_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_minidrv_transfer_context)