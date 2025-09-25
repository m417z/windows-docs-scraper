# SHFormatDrive function

## Description

[**SHFormatDrive** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Opens the Shell's **Format** dialog box.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the parent window of the dialog box. The **Format** dialog box must have a parent window; therefore, this parameter cannot be **NULL**.

### `drive`

Type: **UINT**

The drive to format. The value of this parameter represents a letter drive starting at 0 for the A: drive. For example, a value of 2 stands for the C: drive.

### `fmtID`

Type: **UINT**

The ID of the physical format. Only the following flag is currently defined.

#### SHFMT_ID_DEFAULT (0xFFFF)

The default format ID.

### `options`

Type: **UINT**

This value must be 0 or one of the following values that alter the default format options in the dialog box. This value is regarded as a bitfield and should be treated accordingly.

#### SHFMT_OPT_FULL (0x0001)

0x001. If this flag is set, then the **Quick Format** option is selected.

This function is included in Shlobj.h only in Windows XP with SP1 and later.

**Windows XP:** Prior to Windows XP with SP1, this function is accessible through Shell32.lib.

#### SHFMT_OPT_SYSONLY (0x0002)

0x002. Selects the **Create an MS-DOS startup disk** option, creating a system boot disk.

## Return value

Type: **DWORD**

Returns the format ID of the last successful format or one of the following values. The LOWORD of this value can be passed on subsequent calls as the *fmtID* parameter to repeat the last format.

| Return code | Description |
| --- | --- |
| **SHFMT_ERROR** | An error occurred during the last format. This does not indicate that the drive is unformattable. |
| **SHFMT_CANCEL** | The last format was canceled. |
| **SHFMT_NOFORMAT** | The drive cannot be formatted. |

## Remarks

The format is controlled by the dialog box interface. That is, the user must click the **OK** button to actually begin the format—the format cannot be started programmatically.

#### Examples

This call to **SHFormatDrive** brings up the Shell's Format dialog box for a disk in drive A, with the default formatting options selected.

``` syntax
SHFormatDrive(hMainWnd, 0, SHFMT_ID_DEFAULT, 0);
```