# MsiGetPatchInfoA function

## Description

The
**MsiGetPatchInfo** function returns information about a patch.

## Parameters

### `szPatch` [in]

Specifies the patch code for the patch package.

### `szAttribute` [in]

Specifies the attribute to be retrieved.

| Attribute | Meaning |
| --- | --- |
| **INSTALLPROPERTY_LOCALPACKAGE** | Local cached package. |

### `lpValueBuf` [out]

Pointer to a buffer that receives the property value. This parameter can be null.

### `pcchValueBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpValueBuf* parameter. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

If *lpValueBuf* is null, *pcchValueBuf* can be null.

## Return value

The **MsiGetPatchInfo** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_MORE_DATA** | A buffer is too small to hold the requested data. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_PRODUCT** | The patch package is not installed. |
| **ERROR_UNKNOWN_PROPERTY** | The property is unrecognized. |

## Remarks

When the
**MsiGetPatchInfo** function returns, the *pcchValueBuf* parameter contains the length of the class string stored in the buffer. The count returned does not include the terminating null character.

If the buffer is too small to hold the requested data,
**MsiGetPatchInfo** returns ERROR_MORE_DATA, and *pcchValueBuf* contains the number of characters copied to *lpValueBuf*, without counting the null character.

> [!NOTE]
> The msi.h header defines MsiGetPatchInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)