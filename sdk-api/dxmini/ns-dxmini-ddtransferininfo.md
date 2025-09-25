# DDTRANSFERININFO structure

## Description

The DDTRANSFERININFO structure contains the transfer information for the surface

## Members

### `lpSurfaceData`

Points to a [DDSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsurfacedata) structure that represents the surface that contains the information to be transferred. The information in this structure is supplied by DirectDraw.

### `dwStartLine`

Indicates the first line in the surface from which data is transferred.

### `dwEndLine`

Indicates the last line in the surface from which data is transferred, inclusive.

### `dwTransferID`

Specifies an identification for the transfer supplied by DirectDraw. This transfer ID is used by the driver in the [DDGETTRANSFERSTATUSOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgettransferstatusoutinfo) structure.

### `dwTransferFlags`

Indicates the type of transfer. One of the following:

| Flag | Meaning |
| --- | --- |
| DDTRANSFER_CANCEL | DirectDraw previously requested a transfer, but is now canceling that request. |
| DDTRANSFER_HALFLINES | Due to half line issues, the odd field contains an extra line of useless data at the top that the driver must account for. |
| DDTRANSFER_INVERT | During bus mastering, the capture driver is requesting an inversion. |
| DDTRANSFER_NONLOCALVIDMEM | The transfer is from display memory to AGP memory. |
| DDTRANSFER_SYSTEMMEMORY | The transfer is from display memory to system memory. |

### `lpDestMDL`

Points to a destination [memory descriptor list (MDL)](https://learn.microsoft.com/windows-hardware/drivers/) structure.

## See also

[DDGETTRANSFERSTATUSOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgettransferstatusoutinfo)

[DDSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddsurfacedata)

[DxTransfer](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_transfer)