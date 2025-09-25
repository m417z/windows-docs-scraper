## Description

Represents a DNS service running on the network.

## Members

### `pszInstanceName`

A string that represents the service name. This is a fully qualified domain name that begins with a service name, and ends with ".local". It takes the generalized form "\.\_\.\_\.local". For example, "MyMusicServer._http._tcp.local".

### `pszHostName`

A string that represents the name of the host of the service.

### `ip4Address`

A pointer to an **IP4_ADDRESS** structure that represents the service-associated IPv4 address.

### `ip6Address`

A pointer to an [IP6_ADDRESS](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-ip6_address) structure that represents the service-associated IPv6 address.

### `wPort`

A value that represents the port on which the service is running.

### `wPriority`

A value that represents the service priority.

### `wWeight`

A value that represents the service weight.

### `dwPropertyCount`

The number of properties—defines the number of elements in the arrays of the `keys` and `values` parameters.

### `keys`

A pointer to an array of string values that represent the property keys.

### `values`

A pointer to an array of string values that represent the corresponding property values.

### `dwInterfaceIndex`

A value that contains the interface index on which the service was discovered.

## Remarks

`pszInstanceName`. A string that represents the service name. This is a fully qualified domain name that begins with a service name, and ends with ".local". It takes the generalized form "\.\_\.\_\.local". For example, "MyMusicServer._http._tcp.local".

`pszHostName`. A string that represents the name of the host of the service.

`keys`. A pointer to an array of string values that represent the property keys.

`values`. A pointer to an array of string values that represent the corresponding property values.

## See also