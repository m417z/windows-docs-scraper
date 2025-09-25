# DsIsMangledRdnValueW function

## Description

The **DsIsMangledRdnValue** function determines if a given relative distinguished name value is a mangled name of the given type.

## Parameters

### `pszRdn` [in]

Pointer to a null-terminated string that contains the relative distinguished name to determine if it is mangled. The *cRdn* parameter contains the number of characters in this string.

### `cRdn` [in]

Contains the number of characters in the *pszRdn* string.

### `eDsMangleForDesired` [in]

Contains one of the [DS_MANGLE_FOR](https://learn.microsoft.com/windows/desktop/api/dsparse/ne-dsparse-ds_mangle_for) values that specifies the type of name mangling to search for.

## Return value

Returns **TRUE** if the relative distinguished name is mangled and the mangle type is the same as specified. Returns **FALSE** if the relative distinguished name is not mangled or the mangle type is different than specified.

## Remarks

This function determines if the given relative distinguished name value is mangled and mangled in the given type. The *pszRdn* parameter should only contain the value of the relative distinguished name and not the key. The relative distinguished name value may be quoted or unquoted.

> [!NOTE]
> The dsparse.h header defines DsIsMangledRdnValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DS_MANGLE_FOR](https://learn.microsoft.com/windows/desktop/api/dsparse/ne-dsparse-ds_mangle_for)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsIsMangledDn](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsismangleddna)