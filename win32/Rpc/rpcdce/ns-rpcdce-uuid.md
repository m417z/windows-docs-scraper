# UUID structure

The **UUID** structure defines a Universally Unique Identifier (UUID). A **UUID** provides a unique designation of an object such as an interface, a manager entry-point vector, or a client object.

The **UUID** structure is a `typedef`'d synonym for the [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure.

## Remarks

The RPC run-time libraries use **UUID**s to check for compatibility between clients and servers, and to select among multiple implementations of an interface.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | Defined in rpcdce.h; include rpc.h |

## See also

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)
[UUID\_VECTOR](https://learn.microsoft.com/windows/win32/api/rpcdce/ns-rpcdce-uuid_vector)