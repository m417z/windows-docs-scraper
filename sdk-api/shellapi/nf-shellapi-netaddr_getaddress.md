# NetAddr_GetAddress macro

## Syntax

```cpp
HRESULT NetAddr_GetAddress(
             HWND hwnd,
  [in, out]  LPARAM pv
);
```

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns one of the following values of type **HRESULT**:

- **E_INVALIDARG** - The calling application failed to allocate a **NC_ADDRESS** structure.
- **ERROR_INSUFFICIENT_BUFFER** - The out buffer is too small to hold the parsed network address.
- **ERROR_INVALID_PARAMETER** - The network address string is not of any type specified.
- **ERROR_SUCCESS** - The operation was successful.
- **S_FALSE** - There is no address in the network address control to validate.

## Description

Indicates whether a network address conforms to a specified type and format.

## Parameters

### `hwnd`

A handle to the network address control that contains the address to validate.

### `pv` [in, out]

A pointer to an [NC_ADDRESS](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-nc_address) structure to receive network address information in parsed form, if the address format and type in the control specified by *hwnd* are validated. The calling application is responsible for allocating the memory for this structure.

## Remarks

Use the **NetAddr_GetAddress** macro to validate a network address in a network address control against a preset network address type mask. To instantiate, use the class **msctls_netaddress** defined in Shellapi.h. Call [InitNetworkAddressControl](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-initnetworkaddresscontrol) at run time before calling this macro. This initializes the common controls library that contains the network address control.

This macro gets the network address string from a network address control, parses the string, and checks whether the string matches a network address type mask. If the string matches the mask, the function returns S_OK and returns the string in parsed form to the calling application (including the port number, prefix length, and other address information), using the [NC_ADDRESS](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-nc_address) structure pointed to by *pv*. This macro returns E_INVALIDARG if the calling application fails to allocate the structure pointed to by *pv*.

Representations of Internet Protocol (IP) address versions 4 and 6 (v4/v6) for services and networks, as well as named Internet addresses and services using Domain Name System (DNS) format are parsed. If the network address string represents a named host name (DNS) or service, the value returned in the **PrefixLength** member of [NC_ADDRESS](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-nc_address) is zero.

Set the network address type mask using the [NetAddr_SetAllowType](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-netaddr_setallowtype) macro before you call the **NetAddr_GetAddress** macro.

## See also

[NetAddr_GetAllowType](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-netaddr_getallowtype)