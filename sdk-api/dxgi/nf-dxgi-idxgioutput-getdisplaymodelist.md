# IDXGIOutput::GetDisplayModeList

## Description

[Starting with Direct3D 11.1, we recommend not to use **GetDisplayModeList** anymore to retrieve the matching display mode. Instead, use [IDXGIOutput1::GetDisplayModeList1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutput1-getdisplaymodelist1), which supports stereo display mode.]

Gets the display modes that match the requested format and other input options.

## Parameters

### `EnumFormat`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The color format (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)).

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Options for modes to include (see [DXGI_ENUM_MODES](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-enum-modes)).
DXGI_ENUM_MODES_SCALING needs to be specified to expose the display modes that require scaling. Centered modes, requiring no
scaling and corresponding directly to the display output, are enumerated by default.

### `pNumModes` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Set *pDesc* to **NULL** so that *pNumModes* returns the number of display modes that match the format and the options.
Otherwise, *pNumModes* returns the number of display modes returned in *pDesc*.

### `pDesc` [out, optional]

Type: **[DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85))***

A pointer to a list of display modes (see [DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85))); set to **NULL** to get the number of display modes.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error). It is rare, but possible, that the display modes available can change immediately after calling
this method, in which case DXGI_ERROR_MORE_DATA is returned (if there is not enough room for all the display modes).
If **GetDisplayModeList** is called from a Remote Desktop Services session (formerly Terminal Services session), DXGI_ERROR_NOT_CURRENTLY_AVAILABLE is returned.

## Remarks

In general, when switching from windowed to full-screen mode, a swap chain automatically chooses a display mode that meets (or exceeds) the resolution, color
depth and refresh rate of the swap chain. To exercise more control over the display mode, use this API to poll the set of display modes that are validated
against monitor capabilities, or all modes that match the desktop (if the desktop settings are not validated against the monitor).

As shown, this API is designed to be called twice. First to get the number of modes available, and second to return a description of the modes.

```

UINT num = 0;
DXGI_FORMAT format = DXGI_FORMAT_R32G32B32A32_FLOAT;
UINT flags         = DXGI_ENUM_MODES_INTERLACED;

pOutput->GetDisplayModeList( format, flags, &num, 0);

...

DXGI_MODE_DESC * pDescs = new DXGI_MODE_DESC[num];
pOutput->GetDisplayModeList( format, flags, &num, pDescs);

```

## See also

[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)