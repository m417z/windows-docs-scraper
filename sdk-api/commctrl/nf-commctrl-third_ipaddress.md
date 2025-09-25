# THIRD_IPADDRESS macro

## Syntax

```cpp
BYTE THIRD_IPADDRESS(
   LPARAM x
);
```

## Return value

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a BYTE value that contains the field 2 value.

## Description

Extracts the field 2 value from a packed IP address retrieved with the [IPM_GETADDRESS](https://learn.microsoft.com/windows/desktop/Controls/ipm-getaddress) message.

## Parameters

### `x`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The packed IP address value.