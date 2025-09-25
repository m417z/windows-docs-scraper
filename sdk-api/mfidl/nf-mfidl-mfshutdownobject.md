# MFShutdownObject function

## Description

Shuts down a Media Foundation object and releases all resources associated with the object.

This function is a helper function that wraps the [IMFShutdown::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfshutdown-shutdown) method. The function queries the object for the [IMFShutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfshutdown) interface and, if successful, calls **Shutdown** on the object.

## Parameters

### `pUnk`

Pointer to the **IUnknown** interface of the object.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

This function is not related to the [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) function, which shuts down the Media Foundation platform, as described in [Initializing Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/initializing-media-foundation).

## See also

[IMFShutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfshutdown)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)