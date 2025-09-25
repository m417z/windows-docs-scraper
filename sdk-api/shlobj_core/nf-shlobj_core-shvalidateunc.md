# SHValidateUNC function

## Description

[**SHValidateUNC** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Validates a Universal Naming Convention (UNC) path by calling [WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a). The function makes it possible for the user to type a remote network access (RNA) UNC application or document name from the **Run** dialog box on the **Start** menu.

## Parameters

### `hwndOwner` [in, optional]

Type: **HWND**

Handle of the parent window, used to display UI. If this is not needed, this value can be set to **NULL**.

### `pszFile` [in, out]

Type: **PWSTR**

A pointer to a null-terminated Unicode string that specifies the UNC path to validate. Note: This string must not be a constant string.

### `fConnect`

Type: **UINT**

One or more of the following values.

#### VALIDATEUNC_CONNECT (0x0001)

Connect a drive letter. When this flag is set, the value in *pszFile* is changed to the local drive to which the UNC is mapped on the local machine.

#### VALIDATEUNC_NOUI (0x0002)

On either failure or success, display no UI.

#### VALIDATEUNC_PRINT (0x0004)

Validate as a print share rather than disk share.

#### VALIDATEUNC_PERSIST (0x0008)

**Windows Vista and later**. The connection should be made persistent.

#### VALIDATEUNC_VALID

Mask value used to verify that the flags passed to **SHValidateUNC** are valid.

## Return value

Type: **BOOL**

Returns **TRUE** if the UNC path exists; **FALSE** if the UNC path does not exist or if some other failure occurred.