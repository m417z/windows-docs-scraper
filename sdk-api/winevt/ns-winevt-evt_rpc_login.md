# EVT_RPC_LOGIN structure

## Description

Contains the information used to connect to a remote computer.

## Members

### `Server`

The name of the remote computer to connect to.

### `User`

The user name to use to connect to the remote computer.

### `Domain`

The domain to which the user account belongs. Optional.

### `Password`

The password for the user account.

### `Flags`

The authentication method to use to authenticate the user when connecting to the remote computer. For possible authentication methods, see the [EVT_RPC_LOGIN_FLAGS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_rpc_login_flags) enumeration.

## Remarks

You can set **User**, **Domain**, and **Password** to **NULL** to use the credentials of the current user.

If you set **Password**, consider using the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function to clear the password after calling [EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession).

## See also

[EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession)