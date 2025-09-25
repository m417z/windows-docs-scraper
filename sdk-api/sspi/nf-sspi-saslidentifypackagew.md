# SaslIdentifyPackageW function

## Description

The **SaslIdentifyPackage** function returns the negotiate prefix that matches the specified SASL negotiation buffer.

## Parameters

### `pInput` [in]

Pointer to a [SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc) structure that specifies the SASL negotiation buffer for which to find the negotiate prefix.

### `PackageInfo` [out]

Pointer to a pointer to a [SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa) structure that returns the negotiate prefix for the negotiation buffer specified by the *pInput* parameter.

## Return value

If the call is completed successfully, this function returns SEC_E_OK.

If the function fails, the return value is a nonzero error code.

## Remarks

> [!NOTE]
> The sspi.h header defines SaslIdentifyPackage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).