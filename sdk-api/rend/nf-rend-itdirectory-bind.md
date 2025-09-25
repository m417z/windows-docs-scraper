# ITDirectory::Bind

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**Bind** method binds to the server.

## Parameters

### `pDomainName` [in]

Pointer to a **BSTR** containing the user's domain name.

### `pUserName` [in]

Pointer to a **BSTR** containing the user's name.

### `pPassword` [in]

Pointer to a **BSTR** containing the user's password.

### `lFlags` [in]

[RENDBIND](https://learn.microsoft.com/windows/desktop/Tapi/rendbind--constants) flags indicator of whether all parameters must be validated or can take a default.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDomainName*, *pUserName*, or *pPassword* parameter is not a valid pointer. |
| **E_INVALIDARG** | A password is required but was not supplied, the domain and user are not supplied, or the domain was supplied but the user was not. |
| **RND_NOT_CONNECTED** | The [ITDirectory::Connect](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectory-connect) method has not been invoked or did not succeed. |

## Remarks

The input variables *pDomainName*, *pUserName*, and *pPassword* can be **NULL**.

Calling this function is optional. However, some directory operations require the user to be authenticated first. It is always safe to call
**Bind**.

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pDomainName*, *pUserName*, and *pPassword* parameters. The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variables are no longer needed.

## See also

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)