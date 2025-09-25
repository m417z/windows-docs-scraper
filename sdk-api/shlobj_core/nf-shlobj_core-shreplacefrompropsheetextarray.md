# SHReplaceFromPropSheetExtArray function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Requests each property sheet in a property sheet extension array to replace pages. Each page is allowed up to one replacement.

## Parameters

### `hpsxa` [in]

Type: **HPSXA**

A property sheet array handle (HPSXA) returned from a call to [SHCreatePropSheetExtArray](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-shcreatepropsheetextarray).

### `uPageID`

Type: **UINT**

The ID of the page to replace.

### `lpfnReplaceWith` [in]

Type: **LPFNADDPROPSHEETPAGE**

A pointer to an [AddPropSheetPageProc](https://learn.microsoft.com/windows/desktop/api/prsht/nc-prsht-lpfnaddpropsheetpage) function used by the property sheet extension to add a page to a property sheet.

### `lParam`

Type: **LPARAM**

An application-defined value.

## Return value

Type: **UINT**

The number of replacements actually performed.