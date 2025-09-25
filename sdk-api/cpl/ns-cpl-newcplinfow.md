## Description

Contains resource information and an application-defined value for a dialog box supported by a Control Panel application.

## Members

### `dwSize`

Type: **DWORD**

The length of the structure, in bytes.

### `dwFlags`

Type: **DWORD**

This member is ignored.

### `dwHelpContext`

Type: **DWORD**

This member is ignored.

### `lData`

Type: **LONG_PTR**

A pointer to data defined by the application. When the Control Panel sends the [CPL_DBLCLK](https://learn.microsoft.com/windows/desktop/shell/fa-associationarray) and [CPL_STOP](https://learn.microsoft.com/windows/desktop/shell/library-functions-bumper) messages, it passes this value back to your application.

### `hIcon`

Type: **HICON**

The identifier of the icon that represents the dialog box. This icon is intended to be displayed by the application that controls the Control Panel application.

### `szName`

Type: **TCHAR[32]**

A null-terminated string that contains the dialog box name. The name is intended to be displayed below the icon.

### `szInfo`

Type: **TCHAR[64]**

A null-terminated string containing the dialog box description. The description is intended to be displayed when the icon for the dialog box is selected.

### `szHelpFile`

Type: **TCHAR[128]**

This member is ignored.

## Remarks

The [CPlApplet](https://learn.microsoft.com/windows/desktop/api/cpl/nc-cpl-applet_proc) function of the Control Panel application returns this information to the Control Panel in response to a [CPL_NEWINQUIRE](https://learn.microsoft.com/windows/desktop/shell/glossary) message.

> [!NOTE]
> The cpl.h header defines NEWCPLINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CPLINFO](https://learn.microsoft.com/windows/desktop/api/cpl/ns-cpl-cplinfo)