# RtlFindUnicodePrefix function

## Description

The **RtlFindUnicodePrefix** routine searches for the best match for a given Unicode file name in a prefix table.

## Parameters

### `PrefixTable` [in]

Pointer to the prefix table. The table must have been initialized by calling [RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix).

### `FullName` [in]

Pointer to a Unicode string containing the full pathname for a file.

### `CaseInsensitiveIndex` [in]

Position in the file name and prefix strings at which the comparison is to become case-insensitive. The string comparison is case-sensitive for the first *CaseInsensitiveIndex* characters in each string, case-insensitive for the remainder of the string.

| Value | Meaning |
| --- | --- |
| 0 | String comparison is case-insensitive. |
| 1..*FullName.Length*-1 | String comparison is case-sensitive for characters at positions 0 through *CaseInsensitiveIndex*-1, case-insensitive for characters from position *CaseInsensitiveIndex* to the end of the string. |
| *FullName.Length* | String comparison is case-sensitive. |

## Return value

**RtlFindUnicodePrefix** returns a pointer to the longest proper prefix found for the given string at *FullName*. If no matching prefix is found, **RtlFindUnicodePrefix** returns **NULL**.

## Remarks

Each prefix entry in the table is a pathname relative to the root directory of a file system volume. To be well-formed, the prefix must begin with a single backslash (\).

When it finds a matching prefix, **RtlFindUnicodePrefix** rebalances the prefix table's splay tree.

File systems must call [RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix) to initialize the prefix table before using any other **Rtl..UnicodePrefix** routines on it. The initialized prefix table structure should be considered opaque.

Callers of the **Rtl..UnicodePrefix** routines are responsible for synchronizing access to the prefix table. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlInitializeUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinitializeunicodeprefix)

[RtlInsertUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlinsertunicodeprefix)

[RtlNextUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlnextunicodeprefix)

[RtlRemoveUnicodePrefix](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlremoveunicodeprefix)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)