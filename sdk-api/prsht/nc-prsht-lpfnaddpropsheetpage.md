# LPFNADDPROPSHEETPAGE callback function

## Description

Specifies an application-defined callback function that a property sheet extension uses to add a page to a property sheet.

## Parameters

### `unnamedParam1`

Type: **HPROPSHEETPAGE**

Handle to a property sheet page. This parameter is typically called *hPage*.

### `unnamedParam2`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined 32-bit value. This parameter is typically called *lParam*.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

**Note** This function is not supported when using the Aero wizard style ([PSH_AEROWIZARD](https://learn.microsoft.com/windows/win32/controls/pss-propsheetheader)).