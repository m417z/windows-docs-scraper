# IDXGIOutput1::GetDisplayModeList1

## Description

Gets the display modes that match the requested format and other input options.

## Parameters

### `EnumFormat`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value for the color format.

### `Flags`

A combination of [DXGI_ENUM_MODES](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-enum-modes)-typed values that are combined by using a bitwise OR operation. The resulting value specifies options for display modes to include. You must specify DXGI_ENUM_MODES_SCALING to expose the display modes that require scaling. Centered modes that require no
scaling and correspond directly to the display output are enumerated by default.

### `pNumModes` [in, out]

A pointer to a variable that receives the number of display modes that **GetDisplayModeList1** returns in the memory block to which *pDesc* points. Set *pDesc* to **NULL** so that *pNumModes* returns the number of display modes that match the format and the options.
Otherwise, *pNumModes* returns the number of display modes returned in *pDesc*.

### `pDesc` [out, optional]

A pointer to a list of display modes; set to **NULL** to get the number of display modes.

## Return value

Returns one of the error codes described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic. It is rare, but possible, that the display modes available can change immediately after calling
this method, in which case DXGI_ERROR_MORE_DATA is returned (if there is not enough room for all the display modes).

## Remarks

**GetDisplayModeList1** is updated from [GetDisplayModeList](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-getdisplaymodelist) to return a list of [DXGI_MODE_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_mode_desc1) structures, which are updated mode descriptions. **GetDisplayModeList** behaves as though it calls **GetDisplayModeList1** because **GetDisplayModeList** can return all of the modes that are specified by [DXGI_ENUM_MODES](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-enum-modes), including stereo mode. However, **GetDisplayModeList** returns a list of [DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85)) structures, which are the former mode descriptions and do not indicate stereo mode.

The **GetDisplayModeList1** method does not enumerate stereo modes unless you specify the [DXGI_ENUM_MODES_STEREO](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-enum-modes) flag in the *Flags* parameter. If you specify DXGI_ENUM_MODES_STEREO, stereo modes are included in the list of returned modes that the *pDesc* parameter points to. In other words, the method returns both stereo and mono modes.

In general, when you switch from windowed to full-screen mode, a swap chain automatically chooses a display mode that meets (or exceeds) the resolution, color
depth, and refresh rate of the swap chain. To exercise more control over the display mode, use **GetDisplayModeList1** to poll the set of display modes that are validated
against monitor capabilities, or all modes that match the desktop (if the desktop settings are not validated against the monitor).

The following example code shows that you need to call **GetDisplayModeList1** twice. First call **GetDisplayModeList1** to get the number of modes available, and second call **GetDisplayModeList1** to return a description of the modes.

```

UINT num = 0;
DXGI_FORMAT format = DXGI_FORMAT_R32G32B32A32_FLOAT;
UINT flags         = DXGI_ENUM_MODES_INTERLACED;

pOutput->GetDisplayModeList1( format, flags, &num, 0);

...

DXGI_MODE_DESC1 * pDescs = new DXGI_MODE_DESC1[num];
pOutput->GetDisplayModeList1( format, flags, &num, pDescs);

```

## See also

[IDXGIOutput1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutput1)