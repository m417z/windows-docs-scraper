# MFCreateNetSchemePlugin function

## Description

Creates the scheme handler for the network source.

## Parameters

### `riid` [in]

Interface identifier (IID) of the interface to retrieve.

### `ppvHandler` [out]

Receives a pointer to the requested interface. The caller must release the interface. The scheme handler exposes the [IMFSchemeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfschemehandler) interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)