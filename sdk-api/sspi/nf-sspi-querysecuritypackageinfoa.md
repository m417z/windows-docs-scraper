# QuerySecurityPackageInfoA function

## Description

Retrieves information about a specified [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This information includes the bounds on sizes of authentication information, [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), and contexts.

## Parameters

### `pszPackageName` [in]

Pointer to a null-terminated string that specifies the name of the security package.

### `ppPackageInfo` [out]

Pointer to a variable that receives a pointer to a
[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa) structure containing information about the specified security package.

## Return value

If the function succeeds, the return value is SEC_E_OK.

If the function fails, the return value is a nonzero error code.

## Remarks

The caller must call the
[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function to free the buffer returned in *ppPackageInfo*.

> [!NOTE]
> The sspi.h header defines QuerySecurityPackageInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa)