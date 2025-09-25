# NetAddr_DisplayErrorTip macro

## Syntax

```cpp
HRESULT NetAddr_DisplayErrorTip(
  [in]  HWND hwnd
);
```

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

## Description

Displays an error message in the balloon tip associated with the network address control.

## Parameters

### `hwnd` [in]

A handle to the network address control.

## Remarks

Call this macro to display an error message when an address typed into the control does not validate against the allowed network address types set with macro [NetAddr_SetAllowType](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-netaddr_setallowtype). Use the macro [NetAddr_GetAddress](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-netaddr_getaddress) to validate the address.

## See also

[NetAddr_GetAllowType](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-netaddr_getallowtype)