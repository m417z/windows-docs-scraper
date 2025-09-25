# LINEEXTENSIONID structure

## Description

The
**LINEEXTENSIONID** structure describes an extension identifier. Extension identifiers are used to identify service provider-specific extensions for line devices. Multiple functions use this structure, including the
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion) function and the
[TSPI_lineGetExtensionID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetextensionid) function.

## Members

### `dwExtensionID0`

First part of the extension identifier.

### `dwExtensionID1`

Second part of the extension identifier.

### `dwExtensionID2`

Third part of the extension identifier.

### `dwExtensionID3`

Fourth part of the extension identifier.

## Remarks

These four members together specify a universally unique extension identifier that identifies a line device class extension. This structure may not be extended.

Extension identifiers are generated using an SDK-provided generation utility.

## See also

[TSPI_lineGetExtensionID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetextensionid)

[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion)