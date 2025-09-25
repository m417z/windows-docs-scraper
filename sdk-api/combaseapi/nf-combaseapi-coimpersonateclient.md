# CoImpersonateClient function

## Description

Enables the server to impersonate the client of the current call for the duration of the call.

## Return value

This function supports the standard return values, including S_OK.

## Remarks

This method allows the server to impersonate the client of the current call for the duration of the call. If you do not call CoRevertToSelf, COM reverts automatically for you. This function will fail unless the object is being called with RPC_C_AUTHN_LEVEL_CONNECT or higher authentication in effect (which is any authentication level except RPC_C_AUTHN_LEVEL_NONE). This function encapsulates the following sequence of common calls (error handling excluded):

``` syntax
    CoGetCallContext(IID_IServerSecurity, (void**)&pss);
    pss->ImpersonateClient();
    pss->Release();

```

**CoImpersonateClient** encapsulates the process of getting a pointer to an instance of [IServerSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iserversecurity) that contains data about the current call, calling its [ImpersonateClient](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-impersonateclient) method, and then releasing the pointer. One call to [CoRevertToSelf](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreverttoself) (or [IServerSecurity::RevertToSelf](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-reverttoself)) will undo any number of calls to impersonate the client.

## See also

[Cloaking](https://learn.microsoft.com/windows/desktop/com/cloaking)

[IServerSecurity::ImpersonateClient](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-impersonateclient)

[Impersonation](https://learn.microsoft.com/windows/desktop/com/impersonation)

[Impersonation and Asynchronous Calls](https://learn.microsoft.com/windows/desktop/com/impersonation-and-asynchronous-calls)

[Security in COM](https://learn.microsoft.com/windows/desktop/com/security-in-com)