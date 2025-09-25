# DsIsMangledDnA function

## Description

The **DsIsMangledDn** function determines if the first relative distinguished name (RDN) in a distinguished name (DN) is a mangled name of a given type.

## Parameters

### `pszDn` [in]

Pointer to a null-terminated string that contains the distinguished name to retrieve the relative distinguished name from. This can also be a quoted distinguished name as returned by other directory service functions.

### `eDsMangleFor` [in]

Contains one of the [DS_MANGLE_FOR](https://learn.microsoft.com/windows/desktop/api/dsparse/ne-dsparse-ds_mangle_for) values that specifies the type of name mangling to look for.

## Return value

Returns **TRUE** if the first relative distinguished name in *pszDn* is mangled in the manner specified by *eDsMangleFor* or **FALSE** otherwise.

## See also

[DS_MANGLE_FOR](https://learn.microsoft.com/windows/desktop/api/dsparse/ne-dsparse-ds_mangle_for)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsIsMangledRdnValue](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsismangledrdnvaluea)

## Remarks

> [!NOTE]
> The dsparse.h header defines DsIsMangledDn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).