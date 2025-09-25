# CSecureChannelServer::MACUpdate

## Description

The **MACUpdate** method updates the message authentication code (MAC) value with a parameter value.

## Parameters

### `hMAC` [in]

Handle to the array containing the MAC for the current parameter data. The handle is returned by the **MACInit** method.

### `pbData` [in]

Pointer to the data to be added to the MAC value for the current parameter data.

### `dwDataLen`

**DWORD** specifying the length of the data to which *pbData* points.

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

**MACUpdate** must be called repeatedly with each piece of data to add to the message authentication code (MAC) . **MACUpdate** must be called after **MACInit** because **MACInit** acquires the MAC handle. **MACFinal** must be called after **MACUpdate**.

#### Examples

See the example code for [MACInit](https://learn.microsoft.com/previous-versions/ms868514(v=msdn.10)).

## See also

[CSecureChannelServer Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class)

[CSecureChannelServer::MACInit](https://learn.microsoft.com/previous-versions/ms868514(v=msdn.10))

[Message Authentication](https://learn.microsoft.com/windows/desktop/WMDM/message-authentication)