# ISCPSecureAuthenticate2::GetSCPSession

## Description

The **GetSCPSession** method is used to obtain a pointer to the [ISCPSecureQuery](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecurequery) interface that represents a session object.

## Parameters

### `ppSCPSession` [out]

Pointer to an [ISCPSession](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsession) object.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method is used to obtain a secure content provider (SCP) session. An SCP session is useful during transfer of multiple files, where the session can help SCP do some of the operations only once instead of once for every file transfer. This results in better transfer performance.

## See also

[ISCPSecureAuthenticate2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsecureauthenticate2)