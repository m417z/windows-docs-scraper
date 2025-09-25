# NetAddr_SetAllowType macro

## Syntax

```cpp
HRESULT NetAddr_SetAllowType(
  [in]  HWND hwnd,
  [in]  WPARAM addrMask
);
```

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

## Description

Sets the network address types that a specified network address control accepts.

## Parameters

### `hwnd` [in]

A handle to the network address control.

### `addrMask` [in]

Specifies the network address types as one or more of the [NET_STRING](https://learn.microsoft.com/windows/desktop/shell/net-string) constants.

## Remarks

The mask set is the criterion used to validate a network address in the macro [NetAddr_GetAddress](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-netaddr_getaddress).

Use this macro for a network address control only. To instantiate, use the class **msctls_netaddress** defined in Shellapi.h. Call [InitNetworkAddressControl](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-initnetworkaddresscontrol) at run time before calling this macro. This initializes the common controls library that contains the network address control.

## See also

[NetAddr_GetAllowType](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-netaddr_getallowtype)