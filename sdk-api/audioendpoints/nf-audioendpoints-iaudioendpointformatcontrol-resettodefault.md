# IAudioEndpointFormatControl::ResetToDefault

## Description

Resets the format to the default setting provided by the device manufacturer.

## Parameters

### `ResetFlags` [in]

Allows the application to specify which formats are reset. If
no flags are set, then this method reevaluates both the endpoint's
device format and mix format and sets them to their default values.

ENDPOINT_FORMAT_RESET_MIX_ONLY: Only reset the mix format. The endpoint's device
format will not be reset if this flag is set.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAudioEndpointFormatControl](https://learn.microsoft.com/windows/desktop/api/audioendpoints/nn-audioendpoints-iaudioendpointformatcontrol)