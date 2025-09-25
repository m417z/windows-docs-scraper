# AutoProxyHelperVtbl structure

## Description

The **AutoProxyHelperVtbl** structure creates a v-table of pointers to Proxy AutoConfig (PAC) helper functions.

See the [Navigator Proxy Auto-Config (PAC) File Format](https://web.archive.org/web/20060424005037/wp.netscape.com/eng/mozilla/2.0/relnotes/demo/proxy-live.html) documentation for a specification of the form and use of Proxy Auto-Config helper functions.

## Members

### `IsResolvable`

Tries to resolve a specified host name. This PAC function is described in the specification under the same name. Returns **TRUE** if the host name can be resolved, or **FALSE** otherwise.

#### lpszHost

Pointer to a string that contains the host name.

### `GetIPAddress`

Places the IP address of the local machine in a specified buffer. This PAC functions is described in the specification under the name **myIPAddress**. Returns zero if successful, or an error code if not.

#### lpszIPAddress

Pointer to a buffer in which the IP address is to be returned.

#### lpdwIPAddressSize

Size of the buffer pointed to by **lpszIPAddress**.

### `ResolveHostName`

Places an IP address that corresponds to a host-name string in a specified buffer. This PAC function is described in the specification under the name, **dnsResolve**. Returns **TRUE** if successful, or **FALSE** otherwise.

#### lpszHostName

Pointer to the host name to resolve.

#### lpszIPAddress

Pointer to a buffer in which the IP address is to be returned.

#### lpdwIPAddressSize

Size of the buffer pointed to by **lpszIPAddress**.

### `IsInNet`

Determines whether a specified IP address masked by a specified mask value matches a specified destination address. This PAC function is described in the specification under the same name.

The comparison is performed by converting the string representations to binary, logically ANDing the mask and the address specified in *lpszIPAddress*, and comparing the result with the address specified in *lpszDest*.

#### lpszIPAddress

Pointer to a string representation of the IP address to mask; corresponds to the *host* parameter in the specification.

#### lpszDest

Pointer to a string representation of the IP address against which to compare; corresponds to the *pattern* parameter in the specification.

#### lpszMask

Pointer to a string representation of the mask to apply against the address pointed to by *lpszIPAddress*.

### `IsResolvableEx`

Tries to resolve a specified host name. This PAC function is described in the specification under the same name. Returns **TRUE** if the host name can be resolved, or **FALSE** otherwise.

**Windows XP and earlier:** Available only in Windows XP with SP2 with Internet Explorer 7. Otherwise, not available.

#### lpszHost

String that contains the host name.

### `GetIPAddressEx`

Places the IP address of the local machine in a specified buffer. This PAC functions is described in the specification under the name **myIPAddress**. Returns zero if successful, or an error code if not.

**Windows XP and earlier:** Available only in Windows XP with SP2 with Internet Explorer 7. Otherwise, not available.

#### lpszIPAddress

Pointer to a buffer in which the IP address is to be returned.

#### lpdwIPAddressSize

The size of the buffer pointed to by *lpszIPAddress*.

### `ResolveHostNameEx`

Places an IP address that corresponds to a host-name string in a specified buffer. This PAC function is described in the specification under the name, **dnsResolve**. Returns **TRUE** if successful, or **FALSE** otherwise.

**Windows XP and earlier:** Available only in Windows XP with SP2 with Internet Explorer 7. Otherwise, not available.

#### lpszHostName

Pointer to the host name to resolve.

#### lpszIPAddress

Pointer to a buffer in which the IP address is to be returned.

#### lpdwIPAddressSize

Size of the buffer pointed to by *lpszIPAddress*.

### `IsInNetEx`

Determines whether a specified IP address masked by a specified mask value matches a specified destination address. This PAC function is described in the specification under the same name.

**Windows XP and earlier:** Available only in Windows XP with SP2 with Internet Explorer 7. Otherwise, not available.

#### lpszIPAddress

Pointer to a string representation of the IP address to mask; corresponds to the *host* parameter in the specification.

#### lpszIPPrefix

Pointer so a string containing the IP address prefix.

### `SortIpList`

Sorts a list of IP addresses.

**Windows XP and earlier:** Available only in Windows XP with SP2 with Internet Explorer 7. Otherwise, not available.

#### lpszIPAddressList

Pointer to the list to sort.

#### lpszIPSortedList

Pointer to the sorted list.

#### lpdwIPSortedListSize

Pointer to a buffer containing the size of the sorted list.

## Remarks

Together with the [AutoProxyHelperFunctions](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-autoproxyhelperfunctions) structure, **AutoProxyHelperVtbl** serves to create a standard v-table that can be declared and populated using C, without requiring the use of C++.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[AutoProxyHelperFunctions](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-autoproxyhelperfunctions)

[InternetInitializeAutoProxyDll](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetinitializeautoproxydll)