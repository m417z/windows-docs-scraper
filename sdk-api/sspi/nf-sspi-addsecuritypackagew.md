# AddSecurityPackageW function

## Description

Adds a [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to the list of providers supported by [Microsoft Negotiate](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-negotiate).

## Parameters

### `pszPackageName` [in]

The name of the package to add.

### `pOptions` [in]

A pointer to a [SECURITY_PACKAGE_OPTIONS](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-security_package_options) structure that specifies additional information about the security package.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.

## See also

[DeleteSecurityPackage](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-deletesecuritypackagea)

## Remarks

> [!NOTE]
> The sspi.h header defines AddSecurityPackage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).