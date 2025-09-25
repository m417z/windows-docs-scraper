# IServerSecurity::ImpersonateClient

## Description

Enables a server to impersonate a client for the duration of a call.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

Usually, a method executes on a thread that uses the access token of the process. However, when impersonating a client, the server runs in the client's security context so that the server has access to the resources that the client has access to. When impersonation is necessary, the server calls the **ImpersonateClient** method to cause an access token representing the client's credentials to be assigned to the current thread. This thread token is used for access checks. [RevertToSelf](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-reverttoself) restores the current thread's access token.

What the server can do on behalf of the client depends on the impersonation level set by the client, which is specified using one of the [impersonation level constants](https://learn.microsoft.com/windows/desktop/com/com-impersonation-level-constants). The server may impersonate the client on an encrypted call at identify, impersonate, or delegate level. For information about these levels of impersonation, see [Impersonation Levels](https://learn.microsoft.com/windows/desktop/com/impersonation-levels).

The identity presented to a server called during impersonation depends on the type of cloaking value, if any, that is set by the client. For more information, see [Cloaking](https://learn.microsoft.com/windows/desktop/com/cloaking).

At the end of each method call, COM will call [RevertToSelf](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-reverttoself) if the application does not.

Traditionally, impersonation information is not nested: The last call to any impersonation mechanism overrides any previous impersonation. However, in the apartment model, impersonation is maintained during nested calls. Thus if the server A receives a call from B, impersonates, calls C, receives a call from D, impersonates, reverts, and receives the reply from C, the impersonation token will be set back to B, not A.

For information on using impersonation with asynchronous calls, see [Impersonation and Asynchronous Calls](https://learn.microsoft.com/windows/desktop/com/impersonation-and-asynchronous-calls).

## See also

[CoImpersonateClient](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coimpersonateclient)

[IServerSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iserversecurity)