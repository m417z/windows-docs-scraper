# DsGetDcSiteCoverageW function

## Description

The **DsGetDcSiteCoverage** function returns the site names of all sites covered by a domain controller.

## Parameters

### `ServerName` [in, optional]

The null-terminated string value that specifies the name of the remote domain controller.

### `EntryCount` [out]

Pointer to a **ULONG** value that receives the number of sites covered by the domain controller.

### `SiteNames` [out]

Pointer to an array of pointers to null-terminated strings that receives the site names. To free the returned buffer, call the [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

## Return value

This function returns DSGETDCAPI DWORD.

## See also

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[DsGetSiteName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetsitenamea)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)

## Remarks

> [!NOTE]
> The dsgetdc.h header defines DsGetDcSiteCoverage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).