# CONNECTDLGSTRUCTA structure

## Description

The
**CONNECTDLGSTRUCT** structure is used by the
[WNetConnectionDialog1](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetconnectiondialog1a) function to establish browsing dialog box parameters.

## Members

### `cbStructure`

Type: **DWORD**

The size, in bytes, of the
**CONNECTDLGSTRUCT** structure. The caller must supply this value.

### `hwndOwner`

Type: **HWND**

The handle to the owner window for the dialog box.

### `lpConnRes`

Type: **LPNETRESOURCE**

A pointer to a [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcea) structure.

If the **lpRemoteName** member of
**NETRESOURCE** is specified, it will be entered into the path field of the dialog box. With the exception of the **dwType** member, all other members of the
**NETRESOURCE** structure must be set to **NULL**. The **dwType** member must be equal to RESOURCETYPE_DISK.

 The system does not support the **RESOURCETYPE_PRINT** flag for browsing and connecting to print resources.

### `dwFlags`

Type: **DWORD**

A set of bit flags that describe options for the dialog box display. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **SidTypeUser** | The account is a user account. |
| **CONNDLG_RO_PATH** | Display a read-only path instead of allowing the user to type in a path. <br><br>This flag should be set only if the **lpRemoteName** member of the [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcea) structure pointed to by **lpConnRes** member is not **NULL** (or an empty string), and the **CONNDLG_USE_MRU** flag is not set. |
| **CONNDLG_CONN_POINT** | Internal flag. Do not use. |
| **CONNDLG_USE_MRU** | Enter the most recently used paths into the combination box. Set this value to simulate the [WNetConnectionDialog](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetconnectiondialog) function. |
| **CONNDLG_HIDE_BOX** | Show the check box allowing the user to restore the connection at logon. |
| **CONNDLG_PERSIST** | Restore the connection at logon. |
| **CONNDLG_NOT_PERSIST** | Do not restore the connection at logon. |

For more information, see the following Remarks section.

### `dwDevNum`

Type: **DWORD**

If the call to the
[WNetConnectionDialog1](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetconnectiondialog1a) function is successful, this member returns the number of the connected device. The value is 1 for A:, 2 for B:, 3 for C:, and so on. If the user made a deviceless connection, the value is –1.

## Remarks

If neither the CONNDLG_RO_PATH nor the CONNDLG_USE_MRU flag is set, and the **lpRemoteName** member of the
**NETRESOURCE** structure does not specify a remote path, the request defaults to the CONNDLG_RO_PATH dialog display type.

The CONNDLG_PERSIST and CONNDLG_NOT_PERSIST values cannot both be set. If neither is set, the dialog box defaults to the last option that was selected in this dialog box for the particular type of device connection.

> [!NOTE]
> The winnetwk.h header defines CONNECTDLGSTRUCT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcea)

[WNetConnectionDialog1](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetconnectiondialog1a)

[Windows Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows Networking Structures](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-structures)