# UuidCreateSequential function

## Description

The
**UuidCreateSequential** function creates a new
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

For security reasons,
[UuidCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreate) was modified so that it no longer uses a machine's MAC address to generate [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid)s.
**UuidCreateSequential** was introduced to allow creation of **UUID**s using the MAC address of a machine's Ethernet card.

The
**UuidCreateSequential** function returns RPC_S_UUID_LOCAL_ONLY when the originating computer does not have an ethernet/token ring (IEEE 802.*x*) address. In this case, the generated [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) is a valid identifier, and is guaranteed to be unique among all **UUID**s generated on the computer. However, the possibility exists that another computer without an ethernet/token ring address generated the identical **UUID**. Therefore you should never use this **UUID** to identify an object that is not strictly local to your computer. Computers with ethernet/token ring addresses generate **UUID**s that are guaranteed to be globally unique.

**Note** The
**UuidCreateSequential** function tends to be slightly faster than the
[UuidCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreate) function. When the performance of the generation of a [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) is a significant consideration, the
**UuidCreateSequential** function may be used.

## See also

[UuidCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreate)

[UuidFromString](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidfromstring)

[UuidToString](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidtostring)