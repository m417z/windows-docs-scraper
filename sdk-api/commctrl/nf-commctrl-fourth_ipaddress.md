# FOURTH_IPADDRESS macro

## Syntax

```cpp
BYTE FOURTH_IPADDRESS(
   LPARAM x
);
```

## Return value

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a BYTE value that contains the field 3 value.

## Description

Extracts the field 3 value from a packed IP address retrieved with the [IPM_GETADDRESS](https://learn.microsoft.com/windows/desktop/Controls/ipm-getaddress) message.

## Parameters

### `x`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The packed IP address value.