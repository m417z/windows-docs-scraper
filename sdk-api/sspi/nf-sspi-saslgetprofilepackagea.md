# SaslGetProfilePackageA function

## Description

The **SaslGetProfilePackage** function returns the package information for the specified package.

## Parameters

### `ProfileName` [in]

Unicode or ANSI string that contains the name of the SASL package.

### `PackageInfo` [out]

Pointer to a pointer to a [SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa) structure that returns the package information for the package specified by the *ProfileName* parameter.

## Return value

If the call is completed successfully, this function returns SEC_E_OK. The following table shows some possible failure return values.

| Return code | Description |
| --- | --- |
| **SEC_E_SECPKG_NOT_FOUND** | The SASL profile specified by the *ProfileName* parameter could not be found. |
| **SEC_E_INSUFFICIENT_MEMORY** | Memory could not be allocated for the [SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa) structure. |

## Remarks

> [!NOTE]
> The sspi.h header defines SaslGetProfilePackage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).