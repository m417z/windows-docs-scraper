# FreeADsStr function

## Description

The **FreeADsStr** function frees the memory of a
string allocated by [AllocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsstr) or
[ReallocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsstr).

## Parameters

### `pStr` [in]

Type: **LPWSTR**

Pointer to the string to be freed. This string must have been allocated with the
[AllocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsstr) or
[ReallocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsstr) function.

## Return value

Type: **BOOL**

The function returns **TRUE** if the memory is freed. Otherwise, it returns
**FALSE**.

## Remarks

Do not use this function to free memory allocated with the
[AllocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsmem) or
[ReallocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsmem) function. Use the
[FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem) function to free memory allocated with these
functions.

For more information and a code example that shows how to use the
**FreeADsStr** function, see
[ReallocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsstr).

## See also

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[AllocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsmem)

[AllocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsstr)

[FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem)

[ReallocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsmem)

[ReallocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsstr)