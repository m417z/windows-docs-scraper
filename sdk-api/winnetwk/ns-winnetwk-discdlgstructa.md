# DISCDLGSTRUCTA structure

## Description

The
**DISCDLGSTRUCT** structure is used in the
[WNetDisconnectDialog1](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetdisconnectdialog1a) function. The structure contains required information for the disconnect attempt.

## Members

### `cbStructure`

Type: **DWORD**

The size, in bytes, of the
**DISCDLGSTRUCT** structure. The caller must supply this value.

### `hwndOwner`

Type: **HWND**

A handle to the owner window of the dialog box.

### `lpLocalName`

Type: **LPTSTR**

A pointer to a **NULL**-terminated string that specifies the local device name that is redirected to the network resource, such as "F:" or "LPT1".

### `lpRemoteName`

Type: **LPTSTR**

A pointer to a **NULL**-terminated string that specifies the name of the network resource to disconnect. This member can be NULL if the **lpLocalName** member is specified. When **lpLocalName** is specified, the connection to the network resource redirected from **lpLocalName** is disconnected.

### `dwFlags`

Type: **DWORD**

A set of bit flags describing the connection. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **DISC_UPDATE_PROFILE** | If this value is set, the specified connection is no longer a persistent one (automatically restored every time the user logs on). This flag is valid only if the **lpLocalName** member specifies a local device. |
| **DISC_NO_FORCE** | If this value is not set, the system applies force when attempting to disconnect from the network resource. <br><br>This situation typically occurs when the user has files open over the connection. This value means that the user will be informed if there are open files on the connection, and asked if he or she still wants to disconnect. If the user wants to proceed, the disconnect procedure re-attempts with additional force. |

## See also

[WNetDisconnectDialog1](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetdisconnectdialog1a)

[Windows Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows Networking Structures](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-structures)

## Remarks

> [!NOTE]
> The winnetwk.h header defines DISCDLGSTRUCT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).