# ImpersonateDdeClientWindow function

## Description

Enables a Dynamic Data Exchange (DDE) server application to impersonate a DDE client application's security context. This protects secure server data from unauthorized DDE clients.

## Parameters

### `hWndClient` [in]

Type: **HWND**

A handle to the DDE client window to be impersonated. The client window must have established a DDE conversation with the server window identified by the
*hWndServer* parameter.

### `hWndServer` [in]

Type: **HWND**

A handle to the DDE server window. An application must create the server window before calling this function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application should call the [RevertToSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-reverttoself) function to undo the impersonation set by the **ImpersonateDdeClientWindow** function.

A DDEML application should use the [DdeImpersonateClient](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeimpersonateclient) function.

### Security Considerations

Using this function incorrectly might compromise the security of your program. It is very important to check the return value of the call. If the function fails for any reason, the client is not impersonated and any subsequent client request is made in the security context of the calling process. If the calling process is running as a highly privileged account, such as LocalSystem or as a member of an administrative group, the user may be able to perform actions that would otherwise be disallowed. Therefore, if the call fails or raises an error do not continue execution of the client request.

## See also

[About Dynamic Data Exchange](https://learn.microsoft.com/windows/desktop/dataxchg/about-dynamic-data-exchange)

**Conceptual**

[DdeImpersonateClient](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeimpersonateclient)

**Other Resources**

**Reference**

[RevertToSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-reverttoself)