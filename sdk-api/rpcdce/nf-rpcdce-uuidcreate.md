# UuidCreate function

## Description

The
**UuidCreate** function creates a new
[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid).

## Parameters

### `Uuid`

Returns a pointer to the created [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_UUID_LOCAL_ONLY** | The [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) is guaranteed to be unique to this computer only. |
| **RPC_S_UUID_NO_ADDRESS** | Cannot get Ethernet or token-ring hardware address for this computer. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

For security reasons, it is often desirable to keep ethernet addresses on networks from becoming available outside a company or organization. The
**UuidCreate** function generates a [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) that cannot be traced to the ethernet address of the computer on which it was generated. It also cannot be associated with other **UUID**s created on the same computer. If you do not need this level of security, your application can use the
[UuidCreateSequential](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreatesequential) function, which behaves exactly as the
**UuidCreate** function does on all other versions of the operating system.

## See also

[UuidFromString](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidfromstring)

[UuidToString](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidtostring)