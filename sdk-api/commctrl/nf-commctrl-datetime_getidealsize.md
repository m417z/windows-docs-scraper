# DateTime_GetIdealSize macro

## Syntax

```cpp
BOOL DateTime_GetIdealSize(
  [in]  HWND hdp,
  [out] SIZE psize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE**.

## Description

Gets the size needed to display the control without clipping. Use this macro or send the [DTM_GETIDEALSIZE](https://learn.microsoft.com/windows/desktop/Controls/dtm-getidealsize) message explicitly.

## Parameters

### `hdp` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the DTP control.

### `psize` [out]

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)**

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure to receive the size. The caller is responsible for allocating this structure.