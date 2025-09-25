# FreeADsMem function

## Description

The **FreeADsMem** function frees the memory allocated by [AllocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsmem) or [ReallocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsmem).

## Parameters

### `pMem` [in]

Type: **LPVOID**

Pointer to the memory to be freed. This memory must have been allocated with the [AllocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsmem) or [ReallocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsmem) function.

## Return value

Type: **BOOL**

The function returns **TRUE** if successful, otherwise it returns **FALSE**.

## Remarks

Do not use this function to free memory allocated with the [AllocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsstr) or [ReallocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsstr) function. Use the [FreeADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsstr) function to free memory allocated with these functions.

For more information and a code example that shows how to use the **FreeADsMem** function, see [ReallocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsmem).

## See also

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[AllocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsmem)

[AllocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-allocadsstr)

[FreeADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsstr)

[ReallocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsmem)

[ReallocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsstr)