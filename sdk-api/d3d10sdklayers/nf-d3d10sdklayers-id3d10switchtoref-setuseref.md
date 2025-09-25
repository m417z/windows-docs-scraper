# ID3D10SwitchToRef::SetUseRef

## Description

Switch between a hardware and a software device.

## Parameters

### `UseRef` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A boolean value. Set this to **TRUE** to change to a software device, set this to **FALSE** to change to a hardware device.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The previous value of *UseRef*.

## Remarks

This API will fail if the device is not switchable; you must have created a device that is switchable by specifying the D3D10_CREATE_DEVICE_SWITCH_TO_REF flag during device creation (when calling [D3D10CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d10misc/nf-d3d10misc-d3d10createdevice)).

Switching from a software device to a hardware device clears all cached objects from system memory. Switching from a hardware device to a software device causes resources to be downloaded to system memory.

## See also

[D3D10CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d10misc/nf-d3d10misc-d3d10createdevice)

[ID3D10SwitchToRef Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10switchtoref)