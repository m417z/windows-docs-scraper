# CSecureChannelServer::MACInit

## Description

The **MACInit** method acquires a message authentication code (MAC) channel for use in calls to the **MACUpdate** and **MACFinal** methods.

## Parameters

### `phMAC` [out]

Pointer to a MAC handle.

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
| E_INVALIDARG | The phMAC parameter is invalid or is a **NULL** pointer. |
| E_FAIL | An unspecified error occurred. |

## Remarks

The **MACInit** method begins a message authentication code (MAC) session. This method must be called every time a (MAC) is required. **MACUpdate** and **MACFinal** must be called sequentially after **MACInit**. After **MACFinal**, **MACInit** must be called again to acquire a new handle.

#### Examples

```cpp

g_pAppSCServer = new CsecureChannelServer();
if( dwRead )
{
    // MAC the parameters.
    HMAC hMAC;

    g_pAppSCServer->MACInit(&hMAC);
    g_pAppSCServer->MACUpdate(hMAC, (BYTE*)(pTmpData), dwRead);
    g_pAppSCServer->MACUpdate(hMAC, (BYTE*)(pdwSize), sizeof(DWORD));
    g_pAppSCServer->MACFinal(hMAC, abMac);

    g_pAppSCServer->EncryptParam(pTmpData, dwRead);

    memcpy(pData, pTmpData, dwRead);
    }

```

## See also

[CSecureChannelServer Class](https://learn.microsoft.com/windows/desktop/WMDM/csecurechannelserver-class)

[CSecureChannelServer::MACFinal](https://learn.microsoft.com/previous-versions/ms868513(v=msdn.10))

[CSecureChannelServer::MACUpdate](https://learn.microsoft.com/previous-versions/ms868515(v=msdn.10))

[Message Authentication](https://learn.microsoft.com/windows/desktop/WMDM/message-authentication)