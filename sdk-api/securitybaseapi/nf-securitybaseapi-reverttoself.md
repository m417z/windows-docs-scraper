# RevertToSelf function

## Description

The **RevertToSelf** function terminates the impersonation of a client application.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) should call the **RevertToSelf** function after finishing any impersonation begun by using the [DdeImpersonateClient](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeimpersonateclient), [ImpersonateDdeClientWindow](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-impersonateddeclientwindow), [ImpersonateLoggedOnUser](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser), [ImpersonateNamedPipeClient](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-impersonatenamedpipeclient), [ImpersonateSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateself), [ImpersonateAnonymousToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateanonymoustoken) or [SetThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadtoken) function.

An RPC server that used the
[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient) function to impersonate a client must call the
[RpcRevertToSelf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcreverttoself) or
[RpcRevertToSelfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcreverttoselfex) to end the impersonation.

If **RevertToSelf** fails, your application continues to run in the context of the client, which is not appropriate. You should shut down the process if **RevertToSelf** fails.

#### Examples

For an example that uses this function, see
[Verifying Client Access with ACLs](https://learn.microsoft.com/windows/desktop/SecAuthZ/verifying-client-access-with-acls-in-c--).

## See also

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[DdeImpersonateClient](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeimpersonateclient)

[ImpersonateAnonymousToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateanonymoustoken)

[ImpersonateDdeClientWindow](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-impersonateddeclientwindow)

[ImpersonateLoggedOnUser](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser)

[ImpersonateNamedPipeClient](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-impersonatenamedpipeclient)

[ImpersonateSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateself)

[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient)

[RpcRevertToSelf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcreverttoself)

[RpcRevertToSelfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcreverttoselfex)

[SetThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreadtoken)