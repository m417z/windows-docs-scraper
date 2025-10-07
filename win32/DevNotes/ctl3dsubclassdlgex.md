# Ctl3dSubclassDlgEx function

Subclasses all controls in a dialog box and in the dialog window itself.

## Parameters

*hwndDlg*

A handle to the dialog window.

*grbit*

The control types to be subclassed. This value can be any of the following.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------|
|

**CTL3D\_BUTTONS**

0x0001

| Subclass buttons.<br> |
|

**CTL3D\_LISTBOXES**

0x0002

| Subclass list boxes.<br> |
|

**CTL3D\_EDITS**

0x0004

| Subclass edit controls.<br> |
|

**CTL3D\_COMBOS**

0x0008

| Subclass combo boxes.<br> |
|

**CTL3D\_STATICTEXTS**

0x0010

| Subclass static text controls.<br> |
|

**CTL3D\_STATICFRAMES**

0x0020

| Subclass static frames.<br> |
|

**CTL3D\_ALL**

0xffff

| Subclass all controls.<br> |
|

**CTL3D\_NODLGWINDOW**

0x00010000

| Do not subclass the dialog window.<br> |

## Return value

Returns **TRUE** if the function succeeds; otherwise, it returns **FALSE**.

## Remarks

This function is especially useful in applications based on C++.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Ctl3d32.dll |

