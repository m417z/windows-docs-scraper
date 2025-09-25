# SHStartNetConnectionDialogW function

## Description

[**SHStartNetConnectionDialog** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Displays a general browsing dialog box for a network resource connection.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to the parent window.

### `pszRemoteName` [in, optional]

Type: **LPCTSTR**

A pointer to a null-terminated character string that specifies the remote network name. This value can be set to **NULL**.

### `dwType`

Type: **DWORD**

A bitfield that contains a set of flags that identify the type of resource that the dialog box is set to find. This value can contain one of the following values, defined in Winnetwk.h:

#### RESOURCETYPE_ANY (0x00000000)

All resources

#### RESOURCETYPE_DISK (0x00000001)

Disk resources

#### RESOURCETYPE_PRINT (0x00000002)

Print resources

##### - dwType.RESOURCETYPE_ANY (0x00000000)

All resources

##### - dwType.RESOURCETYPE_DISK (0x00000001)

Disk resources

##### - dwType.RESOURCETYPE_PRINT (0x00000002)

Print resources

## Return value

Type: **HRESULT**

Always returns S_OK.

## Remarks

> [!NOTE]
> The shlobj_core.h header defines SHStartNetConnectionDialog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).