# IMFNetProxyLocator::FindFirstProxy

## Description

Initializes the proxy locator object.

## Parameters

### `pszHost` [in]

Null-terminated wide-character string containing the hostname of the destination server.

### `pszUrl` [in]

Null-terminated wide-character string containing the destination URL.

### `fReserved` [in]

Reserved. Set to **FALSE**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFNetProxyLocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetproxylocator)