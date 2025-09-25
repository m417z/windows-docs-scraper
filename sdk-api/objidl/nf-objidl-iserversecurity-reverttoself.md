# IServerSecurity::RevertToSelf

## Description

Restores the authentication information of a thread to what it was before impersonation began.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

**RevertToSelf** restores the authentication information on a thread to the authentication information on the thread before impersonation began. If the server does not call **RevertToSelf** before the end of the current call, it will be called automatically by COM.

When [ImpersonateClient](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-impersonateclient) is called on a thread that is not currently impersonating, COM saves the token currently on the thread. A subsequent call to **RevertToSelf** restores the saved token, and [IsImpersonating](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-isimpersonating) will then return **FALSE**. This means that if a series of impersonation calls are made using different [IServerSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iserversecurity) objects, **RevertToSelf** will restore the token that was on the thread when the first call to **ImpersonateClient** was made. Also, only one **RevertToSelf** call is needed to undo any number of **ImpersonateClient** calls.

This method will only revert impersonation changes made by [ImpersonateClient](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-impersonateclient). If the thread token is modified by other means (through the [SetThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadtoken) or [RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient) functions) the result of this function is undefined.

**RevertToSelf** affects only the current method invocation. If there are nested method invocations, each invocation can have its own impersonation token and DCOM will correctly restore the impersonation token before returning to them (regardless of whether [CoRevertToSelf](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreverttoself) or **RevertToSelf** was called).

It is important to understand that an instance of [IServerSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iserversecurity) is valid on any thread in the apartment until the call represented by **IServerSecurity** completes. However, impersonation is local to a particular thread for the duration of the current call on that thread. Therefore, if two threads in the same apartment use the same **IServerSecurity** instance to call [ImpersonateClient](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-impersonateclient), one thread can call **RevertToSelf** without affecting the other.

## See also

[CoRevertToSelf](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreverttoself)

[IServerSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iserversecurity)