# ReallocADsStr function

## Description

The **ReallocADsStr** function creates a copy of a Unicode string.

## Parameters

### `ppStr` [out]

Type: **LPWSTR***

Pointer to null-terminated Unicode string pointer that receives the allocated string. **ReallocADsStr** will attempt to free this memory with [FreeADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsstr) before reallocating the string, so this parameter should be initialized to **NULL** if the memory should not be freed or was not allocated with the [AllocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsmem), [AllocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsstr), [ReallocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsmem) or **ReallocADsStr** function.

The caller must free this memory when it is no longer required by passing this pointer to [FreeADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsstr).

### `pStr` [in]

Type: **LPWSTR**

Pointer to a null-terminated Unicode string that contains the string to copy.

## Return value

Type: **BOOL**

The function returns **TRUE** if successful, otherwise **FALSE** is returned.

## See also

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[AllocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsmem)

[AllocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsstr)

[FreeADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsstr)

[ReallocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsmem)