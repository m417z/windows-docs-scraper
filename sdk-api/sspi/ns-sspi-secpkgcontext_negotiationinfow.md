# SecPkgContext_NegotiationInfoW structure

## Description

The **SecPkgContext_NegotiationInfo** structure contains information on the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) that is being set up or has been set up, and also gives the status on the negotiation to set up the security package.

## Members

### `PackageInfo`

Pointer to a
[SecPkgInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkginfoa) structure that provides general information about the security package chosen in the negotiate process, such as the name and capabilities of the package.

### `NegotiationState`

Indicator of the state of the negotiation for the security package identified in the **PackageInfo** member. This attribute can be queried from the context handle before the setup is complete, such as when ISC returns SEC_I_CONTINUE_NEEDED.

The following table shows values returned in this member.

| Value | Meaning |
| --- | --- |
| **SECPKG_NEGOTIATION_COMPLETE** | Negotiation has been completed. |
| **SECPKG_NEGOTIATION_OPTIMISTIC** | Negotiations not yet completed. |
| **SECPKG_NEGOTIATION_IN_PROGRESS** | Negotiations in progress. |

## Remarks

> [!NOTE]
> The sspi.h header defines SecPkgContext_NegotiationInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).