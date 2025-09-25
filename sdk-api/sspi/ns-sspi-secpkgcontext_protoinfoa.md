# SecPkgContext_ProtoInfoA structure

## Description

[The **SecPkgContext_ProtoInfo** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [SecPkgContext_ConnectionInfo](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_connectioninfo) structure.]

The **SecPkgContext_ProtoInfo** structure holds information about the protocol in use.

This attribute is supported only by the Schannel [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP).

## Members

### `sProtocolName`

Pointer to a string containing the name of the protocol.

### `majorVersion`

Major version number.

### `minorVersion`

Minor version number.

## Remarks

> [!NOTE]
> The sspi.h header defines SecPkgContext_ProtoInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).