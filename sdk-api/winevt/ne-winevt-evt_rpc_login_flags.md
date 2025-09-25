# EVT_RPC_LOGIN_FLAGS enumeration

## Description

Defines the types of authentication that you can use to authenticate the user when connecting to a remote computer.

## Constants

### `EvtRpcLoginAuthDefault:0`

Use the default authentication method during RPC login. The default authentication method is Negotiate.

### `EvtRpcLoginAuthNegotiate`

Use the Negotiate authentication method during RPC login. The client and server negotiate whether to use NTLM or Kerberos.

### `EvtRpcLoginAuthKerberos`

Use Kerberos authentication during RPC login.

### `EvtRpcLoginAuthNTLM`

 Use NTLM authentication during RPC login.

## See also

[EVT_LOGIN_CLASS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_login_class)

[EVT_RPC_LOGIN](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_rpc_login)

[EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession)