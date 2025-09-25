# OPENASINFO structure

## Description

Stores information for the [SHOpenWithDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shopenwithdialog) function.

## Members

### `pcszFile`

Type: **LPCWSTR**

A pointer to the file name.

### `pcszClass`

Type: **LPCWSTR**

A pointer to the file type description. Set this parameter to **NULL** to use the file name extension of **pcszFile**.

### `oaifInFlags`

Type: **OPEN_AS_INFO_FLAGS**

The characteristics of the [SHOpenWithDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shopenwithdialog) dialog box. One or more of the following values.

#### OAIF_ALLOW_REGISTRATION (0x00000001)

Enable the "always use this program" checkbox. If not passed, it will be disabled.

#### OAIF_REGISTER_EXT (0x00000002)

Do the registration after the user hits the **OK** button.

#### OAIF_EXEC (0x00000004)

Execute file after registering.

#### OAIF_FORCE_REGISTRATION (0x00000008)

Force the **Always use this program** checkbox to be checked. Typically, you won't use the OAIF_ALLOW_REGISTRATION flag when you pass this value.

#### OAIF_HIDE_REGISTRATION (0x00000020)

**Introduced in Windows Vista**. Hide the **Always use this program** checkbox. If this flag is specified, the OAIF_ALLOW_REGISTRATION and OAIF_FORCE_REGISTRATION flags will be ignored.

#### OAIF_URL_PROTOCOL (0x00000040)

**Introduced in Windows Vista**. The value for the extension that is passed is actually a protocol, so the **Open With** dialog box should show applications that are registered as capable of handling that protocol.

#### OAIF_FILE_IS_URI (0x00000080)

**Introduced in Windows 8**. The location pointed to by the *pcszFile* parameter is given as a URI.

## Remarks

Starting in Windows 10, the **OAIF_ALLOW_REGISTRATION**, **OAIF_FORCE_REGISTRATION**, and **OAIF_HIDE_REGISTRATION** flags will be ignored by [SHOpenWithDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shopenwithdialog). The **Open With** dialog box can no longer be used to change the default program used to open a file extension. You can only use **SHOpenWithDialog** to open a single file.