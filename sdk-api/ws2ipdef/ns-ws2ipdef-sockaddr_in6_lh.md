# SOCKADDR_IN6_LH structure

## Description

The SOCKADDR_IN6 structure specifies a transport address and port for the
[AF_INET6](https://learn.microsoft.com/windows-hardware/drivers/network/af-inet6) address family.

## Members

### `sin6_family`

The address family for the transport address. This member should always be set to AF_INET6.

### `sin6_port`

A transport protocol port number.

### `sin6_flowinfo`

The IPv6 flow information.

### `sin6_addr`

An
[IN6_ADDR](https://learn.microsoft.com/windows/desktop/api/in6addr/ns-in6addr-in6_addr) structure that contains an IPv6 transport
address.

### `sin6_scope_id`

A ULONG representation of the IPv6 scope identifier that is defined in the
**sin6_scope_struct** member.

### `sin6_scope_struct`

A SCOPE_ID structure that contains the scope identifier for the IPv6 transport address. The
SCOPE_ID structure is defined as follows:

```
typedef struct {
  union {
    struct {
      ULONG  Zone : 28;
      ULONG  Level : 4;
    };
    ULONG  Value;
  };
} SCOPE_ID, *PSCOPE_ID;
```

#### Zone

The zone index that identifies the zone to which the transport address pertains. Zones of the
different scopes are instantiated as follows:

* Each interface on a node comprises a single zone of interface-local scope.

* Each link, and the interfaces attached to that link, comprise a single zone of link-local
  scope.

* There is a single zone of global scope that comprises all of the links and interfaces in the
  Internet.

* The boundaries of zones of scope other than interface-local, link-local, and global are
  defined by network administrators.

A value of zero specifies the default zone.

#### Level

The scope of the IPv6 transport address. This scope must be the same as the IPv6 scope value
that is embedded in the IPv6 transport address. This member can be one of the following:

**ScopeLevelInterface**

The transport address has interface-local scope.

**ScopeLevelLink**

The transport address has link-local scope.

**ScopeLevelSubnet**

The transport address has subnet-local scope.

**ScopeLevelAdmin**

The transport address has admin-local scope.

**ScopeLevelSite**

The transport address has site-local scope.

**ScopeLevelOrganization**

The transport address has organization-local scope.

**ScopeLevelGlobal**

The transport address has global scope.

#### Value

A ULONG representation of the IPv6 scope identifier.

## Remarks

All of the data in the SOCKADDR_IN6 structure, except for the address family, must be specified in
network-byte-order (big-endian).

The size of the SOCKADDR_IN6 structure is too large to fit in the memory space that is provided by a
[SOCKADDR](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-sockaddr) structure. For a structure that is
guaranteed to be large enough to contain a transport address for all possible address families, see
[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh).

## See also

[AF_INET6](https://learn.microsoft.com/windows-hardware/drivers/network/af-inet6)

[IN6_ADDR](https://learn.microsoft.com/windows/desktop/api/in6addr/ns-in6addr-in6_addr)

[SOCKADDR](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-sockaddr)

[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh)