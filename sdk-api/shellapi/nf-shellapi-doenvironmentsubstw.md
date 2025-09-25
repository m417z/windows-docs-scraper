# DoEnvironmentSubstW function

## Description

[This function is retained only for backward compatibility. Use [ExpandEnvironmentStrings](https://learn.microsoft.com/windows/win32/api/processenv/nf-processenv-expandenvironmentstringsw) instead.]

Parses an input string that contains references to one or more environment variables and replaces them with their fully expanded values.

## Parameters

### `pszSrc` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string that contains references to one or more environment variables, each in the following form. Case is ignored.

``` syntax
%VariableName%
```

Any character in the string that is not enclosed in '%' characters is ignored and returned unchanged. Therefore, if your string contains multiple environment variables, you can use any character other than '%' as a separator, including spaces or no separator.

When this function returns successfully, each %*VariableName*% is replaced with its expanded value. The replacement rules are the same as those used by the command interpreter. If the variable name is not found on the system, the %*variableName*% is left as it was submitted on entry.

If this function fails due to the expanded string being too large for the buffer, the contents of this buffer are left unchanged.

### `cchSrc`

Type: **UINT**

The size, in characters, of the buffer pointed to by *pszSrc*. Note that the buffer must be large enough to hold the returned string.

## Return value

Type: **DWORD**

If the expanded string fits in the buffer, **TRUE** is returned in the HIWORD and the length, in characters, of the new *pszSrc* is returned in the LOWORD.

If the expanded string is too large for the buffer, **FALSE** is returned in the HIWORD and *cchSrc* in the LOWORD.

## Remarks

Parameters must contain valid, non-**NULL** values. You must validate these values. Failure to do so can provide unexpected results.

Because the string that is returned in *pszSrc* will typically be longer than the input string, make sure that the buffer is large enough to hold the expanded version of the string. The allotted size of the *cchSrc* buffer for ANSI strings must be one larger than the buffer for a Unicode string. When dealing with ANSI strings, use the formula *buffer size = string length + terminating null character + 1* to determine the minimum correct buffer size.

Because environment variables can be added by the user or applications, the complete list is system-dependent. The following environment variables are standard and are available to both interactive applications and services.

* ALLUSERSPROFILE
* APPDATA
* COMPUTERNAME
* LOCALAPPDATA
* NUMBER_OF_PROCESSORS
* OS
* PROCESSOR_ARCHITECTURE
* PROCESSOR_IDENTIFIER
* PROCESSOR_LEVEL
* PROCESSOR_REVISION
* ProgramData
* ProgramFiles
* PUBLIC
* SystemDrive
* SystemRoot
* USERPROFILE
* windir

The following are only available to interactive applications.

* HOMEDRIVE
* HOMEPATH
* LOGONSERVER
* USERDOMAIN
* USERNAME

The environment variables that correspond to file system folders can be mapped to an equivalent [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) or [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) value can be obtained through [SHGetFolderLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderlocation) or [SHGetKnownFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath). CSIDLs and KNOWNFOLDERIDs are more reliable than environment variable names and should be used whenever possible.

#### Examples

The following console application demonstrates the use of **DoEnvironmentSubstW**.

```cpp

#include "stdafx.h"
#include "windows.h"
#include "windef.h"
#include "shellapi.h"

int _tmain(int argc, _TCHAR* argv[])
{
	WCHAR szSrc[MAX_PATH] = L"%OS%;%HOMEPATH%";

	DWORD result = DoEnvironmentSubstW(szSrc, MAX_PATH);

	WORD success = HIWORD(result);
	WORD string_length = LOWORD(result);

	return 0;
}
```

> [!NOTE]
> The shellapi.h header defines DoEnvironmentSubst as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).