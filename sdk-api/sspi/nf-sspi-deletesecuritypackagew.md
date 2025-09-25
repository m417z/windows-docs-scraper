# DeleteSecurityPackageW function

## Description

Deletes a [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) from the list of providers supported by [Microsoft Negotiate](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-negotiate).

## Parameters

### `pszPackageName` [in]

The name of the security provider to delete.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.

## See also

[AddSecurityPackage](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-addsecuritypackagea)

## Remarks

> [!NOTE]
> The sspi.h header defines DeleteSecurityPackage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).