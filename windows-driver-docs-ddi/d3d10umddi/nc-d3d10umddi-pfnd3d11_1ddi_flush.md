# PFND3D11_1DDI_FLUSH callback function

## Description

Submits outstanding hardware commands that are in the hardware command buffer to the display miniport driver. Implemented by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `FlushFlags`

A value from the [D3D11_1_DDI_FLUSH_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1_ddi_flush_flags) enumeration that indicates whether the driver should continue to submit command buffers if there have been no new commands.

## Return value

Returns **TRUE** if the hardware commands were successfully flushed. Otherwise returns **FALSE**.

## Remarks

After the *Flush(D3D11_1)* function completes, all previously issued commands no longer depend on actions that occur within the application's user-mode context. In addition, applications can safely suspend themselves without blocking rendering until the kernel restarts them (such as, when an asynchronous query is used).

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interfered with the operation of *Flush(D3D11_1)* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10_1DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_1ddi_devicefuncs)

[D3D11_1_DDI_FLUSH_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1_ddi_flush_flags)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)