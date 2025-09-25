# CSecureChannelServer::SACGetProtocols

## Description

The **SACGetProtocols** method reports the protocols supported by a component.

## Parameters

### `ppdwProtocols`

Pointer to a pointer to an array of **DWORD** values specifying the supported protocols.

### `pdwProtocolCount`

Pointer to a **DWORD** specifying the number of protocols in the array to which *ppdwProtocols* points.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| S_OK | The method succeeded. |
| E_INVALIDARG | A parameter is invalid or is a **NULL** pointer. |
| E_FAIL | An unspecified error occurred. |

## Remarks

This method is used by the service provider to implement the public [IComponentAuthenticate::SACGetProtocols](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-icomponentauthenticate-sacgetprotocols) method. For an example of calling this method, see that method's documentation.

## See also

[CSecureChannelServer Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class)

[IComponentAuthenticate::SACGetProtocols](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-icomponentauthenticate-sacgetprotocols)