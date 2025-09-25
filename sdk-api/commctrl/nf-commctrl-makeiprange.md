# MAKEIPRANGE macro

## Syntax

```cpp
LPARAM MAKEIPRANGE(
   BYTE low,
   BYTE high
);
```

## Return value

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns an LPARAM value that contains the range.

## Description

Packs two byte-values into a single LPARAM suitable for use with the [IPM_SETRANGE](https://learn.microsoft.com/windows/desktop/Controls/ipm-setrange) message.

## Parameters

### `low`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The lower limit of the range.

### `high`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The upper limit of the range.