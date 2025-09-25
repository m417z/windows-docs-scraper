# MsiGetProductInfoFromScriptA function

## Description

The
**MsiGetProductInfoFromScript** function returns product information for a Windows Installer script file.

## Parameters

### `szScriptFile` [in]

A null-terminated string specifying the full path to the script file. The script file is the advertise script that was created by calling [MsiAdvertiseProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiadvertiseproducta) or [MsiAdvertiseProductEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiadvertiseproductexa).

### `lpProductBuf39` [out]

Points to a buffer that receives the product code. The buffer must be 39 characters long. The first 38 characters are for the product code
[GUID](https://learn.microsoft.com/windows/desktop/Msi/guid), and the last character is for the terminating null character.

### `plgidLanguage` [out]

Points to a variable that receives the product language.

### `pdwVersion` [out]

Points to a buffer that receives the product version.

### `lpNameBuf` [out]

Points to a buffer that receives the product name. The buffer includes a terminating null character.

### `pcchNameBuf` [in, out]

Points to a variable that specifies the size, in characters, of the buffer pointed to by the *lpNameBuf* parameter. This size should include the terminating null character. When the function returns, this variable contains the length of the string stored in the buffer. The count returned does not include the terminating null character. If the buffer is not large enough, the function returns ERROR_MORE_DATA, and the variable contains the size of the string in characters, without counting the null character.

### `lpPackageBuf` [out]

Points to a buffer that receives the package name. The buffer includes the terminating null character.

### `pcchPackageBuf` [in, out]

Points to a variable that specifies the size, in characters, of the buffer pointed to by the *lpPackageNameBuf* parameter. This size should include the terminating null character. When the function returns, this variable contains the length of the string stored in the buffer. The count returned does not include the terminating null character. If the buffer is not large enough, the function returns ERROR_MORE_DATA, and the variable contains the size of the string in characters, without counting the null character.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_INVALID_PARAMETER** | An invalid argument was passed to the function. |
| **ERROR_MORE_DATA** | A buffer was too small to hold the entire value. |
| **ERROR_INSTALL_FAILURE** | Could not get script information. |
| **ERROR_CALL_NOT_IMPLEMENTED** | This function is only available on Windows 2000 and Windows XP. |

## Remarks

> [!NOTE]
> The msi.h header defines MsiGetProductInfoFromScript as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).