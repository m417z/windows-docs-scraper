# IDMLDebugDevice::SetMuteDebugOutput

## Description

Determine whether to mute DirectML from sending messages to the [ID3D12InfoQueue](https://learn.microsoft.com/windows/win32/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue).

## Parameters

### `mute`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **TRUE**, DirectML is muted, and it will not send messages to the [ID3D12InfoQueue](https://learn.microsoft.com/windows/win32/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue). If **FALSE**, DirectML is not muted, and it will send messages to the **ID3D12InfoQueue**. The default value is **FALSE**.

## See also

[IDMLDebugDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldebugdevice)