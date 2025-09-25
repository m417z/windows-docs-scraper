# DXAPI_INTERFACE structure

## Description

The DXAPI_INTERFACE structure contains the interface callback functions that a [video miniport driver](https://learn.microsoft.com/windows-hardware/drivers/display/video-miniport-drivers-in-the-windows-2000-display-driver-model) implements to support [Kernel-Mode Video Transport](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-video-transport).

## Members

### `Size`

Specifies the size in bytes of this DXAPI_INTERFACE structure.

### `Version`

Specifies the version of the video miniport driver's [DxApi interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/). This value is DXAPI_HALVERSION defined in *dxmini.h*.

### `Context`

Points to the device extension of the device.

### `InterfaceReference`

Unused by the driver.

### `InterfaceDereference`

Unused by the driver.

### `DxGetIrqInfo`

Points to the driver-supplied [DxGetIRQInfo](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_getirqinfo) miniport driver callback function.

### `DxEnableIrq`

Points to the driver-supplied [DxEnableIRQ](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_enableirq) miniport driver callback function.

### `DxSkipNextField`

Points to the driver-supplied [DxSkipNextField](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_skipnextfield) miniport driver callback function.

### `DxBobNextField`

Points to the driver-supplied [DxBobNextField](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_bobnextfield) miniport driver callback function.

### `DxSetState`

Points to the driver-supplied [DxSetState](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_setstate) miniport driver callback function.

### `DxLock`

Points to the driver-supplied [DxLock](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_lock) miniport driver callback function.

### `DxFlipOverlay`

Points to the driver-supplied [DxFlipOverlay](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_flipoverlay) miniport driver callback function.

### `DxFlipVideoPort`

Points to the driver-supplied [DxFlipVideoPort](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_flipvideoport) miniport driver callback function.

### `DxGetPolarity`

Points to the driver-supplied [DxGetPolarity](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_getpolarity) miniport driver callback function.

### `DxGetCurrentAutoflip`

Points to the driver-supplied [DxGetCurrentAutoflip](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_getcurrentautoflip) miniport driver callback function.

### `DxGetPreviousAutoflip`

Points to the driver-supplied [DxGetPreviousAutoflip](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_getpreviousautoflip) miniport driver callback function.

### `DxTransfer`

Points to the driver-supplied [DxTransfer](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_transfer) miniport driver callback function.

### `DxGetTransferStatus`

Points to the driver-supplied [DxGetTransferStatus](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_gettransferstatus) miniport driver callback function.

## See also

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)