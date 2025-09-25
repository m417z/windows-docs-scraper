# RtlGenerate8dot3Name function

## Description

The **RtlGenerate8dot3Name** routine generates a short (8.3) name for the specified long file name.

## Parameters

### `Name` [in]

Pointer to a Unicode string containing the long name for the file. Any leading periods in this file name are skipped during generation of a corresponding short name.

### `AllowExtendedCharacters` [in]

Set to TRUE if the generated short file name can contain extended characters. Set to FALSE if the generated short file name must contain only characters within the current code page's ANSI or OEM range from 0x20 (space) through 0x7f (DEL).

### `Context` [in, out]

Pointer to a caller-allocated buffer for use by **RtlGenerate8dot3Name**. Before calling **RtlGenerate8dot3Name** for the first time to translate the given long file name, the caller is responsible for filling the buffer with zeros.

### `Name8dot3` [in, out]

Pointer to a caller-allocated buffer to receive the generated short file name. The size of this buffer must be at least 24 bytes (12 Unicode characters).

## Return value

This routine returns STATUS_SUCCESS if a short name is successfully generated. It returns STATUS_FILE_SYSTEM_LIMITATION if the system can't generate a unique short name for a given file. It returns this error after 1 million retry attempts for a single given long name.

## Remarks

**RtlGenerate8dot3Name** returns a generated short name with at most eight characters, followed immediately by a period and up to three more characters.

**RtlGenerate8dot3Name** can be called repeatedly. For example, if the initially generated short name is a duplicate of an existing file name, the caller can pass the same parameters to **RtlGenerate8dot3Name** again. In this case, the buffer at **Context** should not be reinitialized with zeros. This buffer should be zeroed only for the initial call to translate a given long name. On repeated calls for the same long name, **RtlGenerate8dot3Name** stores private context information in this buffer to prevent name collisions.

Two calls to **RtlGenerate8dot3Name** with the same **Name** and **Context** are not guaranteed to return the same result. Callers should assume that the mapping of long name to short name is nondeterministic.

**RtlGenerate8dot3Name** translates the given long name using the current system code page, discarding any invalid or superfluous characters in the input long name. When **AllowExtendedCharacters** is set to TRUE, ANSI or double-byte character set (DBCS) characters that map to uppercase OEM characters can become part of a returned short name.

**RtlGenerate8dot3Name** returns a short file name with uppercase alphabetic characters. It returns underscores in the generated short name for any of the following characters that it encounters in the given long name:

* Colons and semicolons
* Commas
* Plus and equal signs
* Square brackets

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[**RtlIsNameLegalDOS8Dot3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlisnamelegaldos8dot3)

[**RtlIsValidOemCharacter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlisvalidoemcharacter)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)