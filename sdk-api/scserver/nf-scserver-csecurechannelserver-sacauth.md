# CSecureChannelServer::SACAuth

## Description

The **SACAuth** method establishes a secure authenticated channel between components.

## Parameters

### `dwProtocolID`

**DWORD** specifying the protocol identifier. This parameter must be set to SAC_PROTOCOL_V1.

### `dwPass`

**DWORD** containing the number of the current pass.

### `pbDataIn` [in]

Pointer to the first byte of the input authentication data.

### `dwDataInLen`

**DWORD** specifying the length of the data to which *pbDataIn* points.

### `ppbDataOut` [out]

Pointer to a pointer to the output authentication data.

### `pdwDataOutLen`

Pointer to a **DWORD** specifying the length of the data to which *ppbDataOut* points.

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

This method is called one or more times as dictated by the protocol identifier. The structure of the data in *pbDataIn* and *pbDataOut* is determined by the values of *dwProtocolID* and *dwPass*. The *dwPass* parameter indicates the number of the communication pass that is under way.

This method is used by the service provider to implement the public [IComponentAuthenticate::SACAuth](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-icomponentauthenticate-sacauth) method. For an example of calling this method, see that method's documentation.

## See also

[CSecureChannelServer Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class)

[IComponentAuthenticate::SACAuth](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-icomponentauthenticate-sacauth)

[Message Authentication](https://learn.microsoft.com/windows/desktop/WMDM/message-authentication)