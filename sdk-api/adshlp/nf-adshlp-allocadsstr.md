# AllocADsStr function

## Description

The **AllocADsStr** function allocates memory for and copies a specified string.

## Parameters

### `pStr` [in]

Type: **LPWSTR**

Pointer to a null-terminated Unicode string to be copied.

## Return value

Type: **LPWSTR**

When successful, the function returns a non-**NULL** pointer to the allocated memory. The string in *pStr* is copied to this buffer and null-terminated. The caller must free this memory when it is no longer required by passing the returned pointer to [FreeADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsstr).

Returns **NULL** if not successful. Call [ADsGetLastError](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetlasterror) to obtain the extended error status. For more information about error code values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

For more information and a code example that shows how to use the **AllocADsStr** function, see [ReallocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsstr).

## See also

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADsGetLastError](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetlasterror)

[FreeADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsstr)

[ReallocADsStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsstr)