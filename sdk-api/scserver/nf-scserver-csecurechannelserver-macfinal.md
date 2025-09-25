# CSecureChannelServer::MACFinal

## Description

The **MACFinal** method releases the message authentication code (MAC) channel and retrieves a final MAC value.

## Parameters

### `hMAC` [in]

Handle to the MAC for the current parameter data. The handle is returned from the **MACInit** method. The handle is no longer valid after this method call.

### `abData` [out]

Pointer to an 8-byte buffer to receive the final MAC value for the current parameter data.

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
| E_INVALIDARG | A parameter is invalid. |
| E_FAIL | An unspecified error occurred. |

## See also

[CSecureChannelServer Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class)

[CSecureChannelServer::MACInit](https://learn.microsoft.com/previous-versions/ms868514(v=msdn.10))

[CSecureChannelServer::MACUpdate](https://learn.microsoft.com/previous-versions/ms868515(v=msdn.10))

[Message Authentication](https://learn.microsoft.com/windows/desktop/WMDM/message-authentication)