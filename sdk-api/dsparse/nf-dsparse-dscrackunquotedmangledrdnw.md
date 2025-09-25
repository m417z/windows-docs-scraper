# DsCrackUnquotedMangledRdnW function

## Description

The **DsCrackUnquotedMangledRdn** function unmangles (unencodes) a given relative distinguished name and returns both the decoded GUID and the mangling type used.

## Parameters

### `pszRDN` [in]

Pointer to a string that contains the relative distinguished name (RDN) to translate. This string length is specified by the *cchRDN* parameter, so this string is not required to be null-terminated. This string must be in unquoted form. For more information about unquoted relative distinguished names, see
[DsUnquoteRdnValue](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsunquoterdnvaluea).

### `cchRDN` [in]

Contains the length, in characters, of the *pszRDN* string.

### `pGuid` [out, optional]

Pointer to **GUID** value that receives the GUID of the unmangled relative distinguished name. This parameter can be **NULL**.

### `peDsMangleFor` [out, optional]

Pointer
to a [DS_MANGLE_FOR](https://learn.microsoft.com/windows/desktop/api/dsparse/ne-dsparse-ds_mangle_for) value that receives the type of mangling used in the mangled relative distinguished name. This parameter can be **NULL**.

## Return value

This function returns **TRUE** if the relative distinguished name is mangled or **FALSE** otherwise. If this function returns **FALSE**, neither *pGuid* or *peDsMangleFor* receive any data.

## Remarks

This function attempts to
decode (unmangle) an RDN that has been previously mangled due to a deletion or a naming conflict. If the relative distinguished name is mangled, the function returns **TRUE** and retrieves the GUID and mangle type, if requested. If the relative distinguished name is not mangled, the function returns **FALSE**.

> [!NOTE]
> The dsparse.h header defines DsCrackUnquotedMangledRdn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DS_MANGLE_FOR](https://learn.microsoft.com/windows/desktop/api/dsparse/ne-dsparse-ds_mangle_for)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsIsMangledDn](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsismangleddna)

[DsIsMangledRdnValue](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsismangledrdnvaluea)

[DsUnquoteRdnValue](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsunquoterdnvaluea)