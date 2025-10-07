# Connections structure

> [!Note]
> The Network Access Protection platform is not available starting with Windows 10

The **Connections** structure contains information about the list of connections maintained by an enforcer.

## Members

**count**

The number of active connections currently maintained by an enforcer within the range 0 (zero) to [**maxConnectionCountPerEnforcer**](https://learn.microsoft.com/windows/win32/nap/nap-type-constants).

**connections**

A COM pointer to a list of [**INapEnforcementClientConnection**](https://learn.microsoft.com/windows/win32/nap/inapenforcementclientconnection) interfaces that represent client connections.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | NapEnforcementClient.h |
| IDL<br> | NapEnforcementClient.idl |

## See also

[NAP Reference](https://learn.microsoft.com/windows/win32/nap/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/win32/nap/nap-structures)

[**INapEnforcementClientConnection**](https://learn.microsoft.com/windows/win32/nap/inapenforcementclientconnection)

