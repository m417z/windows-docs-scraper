# DsGetSiteNameW function

## Description

The **DsGetSiteName** function returns the name of the site where a computer resides. For a domain controller (DC), the name of the site is the location of the configured DC. For a member workstation or member server, the name specifies the workstation site as configured in the domain of the computer.

## Parameters

### `ComputerName` [in]

Pointer to a null-terminated string that specifies the name of the server to send this function. A **NULL** implies the local computer.

### `SiteName` [out]

Pointer to a variable that receives a pointer to a null-terminated string specifying the site location of this computer. This string is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

## Return value

If the function returns account information, the return value is **NO_ERROR**.

If the function fails, the return value can be one of the following error codes.

## Remarks

The **DsGetSiteName** function does not require any particular access to the specified domain. The function is sent to the "NetLogon" service on the computer specified by *ComputerName*.

> [!NOTE]
> The dsgetdc.h header defines DsGetSiteName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea)

[DsValidateSubnetName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsvalidatesubnetnamea)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)