# CoRevertToSelf function

## Description

Restores the authentication information on a thread of execution.

## Return value

This function supports the standard return values, including S_OK to indicate success.

## Remarks

**CoRevertToSelf**, which is a helper function that calls [IServerSecurity::RevertToSelf](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-reverttoself), restores the authentication information on a thread to the authentication information on the thread before impersonation began.

**CoRevertToSelf** encapsulates the following common sequence of calls (error handling excluded):

``` syntax
    CoGetCallContext(IID_IServerSecurity, (void**)&pss);
    pss->RevertToSelf();
    pss->Release();

```

## See also

[CoGetCallContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcallcontext)

[IServerSecurity::RevertToSelf](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-reverttoself)

[Security in COM](https://learn.microsoft.com/windows/desktop/com/security-in-com)