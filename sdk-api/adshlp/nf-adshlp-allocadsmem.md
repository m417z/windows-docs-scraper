# AllocADsMem function

## Description

The **AllocADsMem** function allocates a block of memory of the specified size.

## Parameters

### `cb` [in]

Type: **DWORD**

Contains the size, in bytes, to be allocated.

## Return value

Type: **LPVOID**

When successful, the function returns a non-**NULL** pointer to the allocated memory. The caller must free this memory when it is no longer required by passing the returned pointer to [FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem).

Returns **NULL** if not successful. Call [ADsGetLastError](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetlasterror) to obtain extended error status. For more information about error code values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The memory block returned by **AllocADsMem** is initialized to zero.

For more information and a code example that shows how to use the **AllocADsMem** function, see [ReallocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsmem).

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADsGetLastError](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetlasterror)

[FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem)

[ReallocADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-reallocadsmem)