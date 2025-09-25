## Description

Used to build a [DNS_SERVICE_INSTANCE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_instance) structure from data that describes it.

## Parameters

### `pServiceName`

A string that represents the name of the service.

### `pHostName`

A string that represents the name of the host of the service.

### `pIp4`

A pointer to an **IP4_ADDRESS** structure that represents the service-associated IPv4 address.

### `pIp6`

A pointer to an [IP6_ADDRESS](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-ip6_address) structure that represents the service-associated IPv6 address.

### `wPort`

A value that represents the port on which the service is running.

### `wPriority`

A value that represents the service priority.

### `wWeight`

A value that represents the service weight.

### `dwPropertiesCount`

The number of properties—defines the number of elements in the arrays of the `keys` and `values` parameters.

### `keys`

A pointer to an array of string values that represent the property keys.

### `values`

A pointer to an array of string values that represent the corresponding property values.

## Return value

A pointer to a newly allocated [DNS_SERVICE_INSTANCE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_instance) structure, built from the passed-in parameters. Your application is responsible for freeing the associated memory by calling [DnsServiceFreeInstance](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsservicefreeinstance).

## Remarks

The **dwInterfaceIndex** field of the returned structure is set to 0.

## See also