# EnumerateSecurityPackagesW function

## Description

The **EnumerateSecurityPackages** function returns an array of
[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa) structures that provide information about the [security packages](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) available to the client.

## Parameters

### `pcPackages` [in]

A pointer to a **ULONG** variable that receives the number of packages available on the system. This includes packages that are already loaded and packages available on demand.

### `ppPackageInfo` [in]

A pointer to a variable that receives a pointer to an array of
[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa) structures. Each structure contains information from the [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP) that describes the capabilities of the security package available within that SSP.

When you have finished using the array, free the memory by calling the [FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function.

## Return value

If the function succeeds, the function returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **SEC_E_INSUFFICIENT_MEMORY**<br><br>0x80090300L | There was not sufficient memory to allocate one or more of the buffers. |
| **SEC_E_INVALID_HANDLE**<br><br>0x80090301L | An invalid handle was specified. |
| **SEC_E_SECPKG_NOT_FOUND**<br><br>0x80090305L | The specified package was not found. |

## Remarks

The caller can use the **Name** member of a [SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa) structure to specify a security package in a call to the
[AcquireCredentialsHandle (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) function.

> [!NOTE]
> The sspi.h header defines EnumerateSecurityPackages as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AcquireCredentialsHandle (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea)

[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa)