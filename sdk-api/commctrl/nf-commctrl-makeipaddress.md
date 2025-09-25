# MAKEIPADDRESS macro

## Syntax

```cpp
LPARAM MAKEIPADDRESS(
   BYTE b1,
   BYTE b2,
   BYTE b3,
   BYTE b4
);
```

## Return value

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns an LPARAM value that contains the address.

## Description

Packs four byte-values into a single LPARAM suitable for use with the [IPM_SETADDRESS](https://learn.microsoft.com/windows/desktop/Controls/ipm-setaddress) message.

## Parameters

### `b1`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The field 0 address.

### `b2`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The field 1 address.

### `b3`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The field 2 address.

### `b4`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The field 3 address.