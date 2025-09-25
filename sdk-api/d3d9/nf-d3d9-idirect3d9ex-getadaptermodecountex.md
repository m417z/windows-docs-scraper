# IDirect3D9Ex::GetAdapterModeCountEx

## Description

Returns the number of display modes available.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number denoting the display adapter from which to retrieve the display mode count.

### `pFilter` [in]

Type: **const [D3DDISPLAYMODEFILTER](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodefilter)***

Specifies the characteristics of the desired display mode. See [D3DDISPLAYMODEFILTER](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddisplaymodefilter).

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of display modes available. A return of value zero from this method is an indication that no such display mode is supported or simply this monitor is no longer available.

## Remarks

Events such as display mode changes on other heads of the same hardware, monitor change or its connection status change, and desktop extension/unextension could all affect the number of display mode available.

To fullscreen applications, S_PRESENT_MODE_CHANGED returned from [PresentEx](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-presentex) or [CheckDeviceState](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-checkdevicestate) is the indication of display mode setting failure due to those events.

To increase the chance of setting a currently available display mode successfully, fullscreen applications should try to requery the available display mode list upon receiving S_PRESENT_MODE_CHANGED.

## See also

[IDirect3D9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9ex)