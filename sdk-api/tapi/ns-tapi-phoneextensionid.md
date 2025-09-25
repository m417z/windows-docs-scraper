# PHONEEXTENSIONID structure

## Description

The
**PHONEEXTENSIONID** structure describes an extension identifier. Extension identifiers are used to identify service provider-specific extensions for phone device classes. The
[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion) and
[TSPI_phoneGetExtensionID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetextensionid) functions return this structure.

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

These four members together specify a universally unique extension identifier that identifies a phone device class extension. This structure may not be extended.

Extension identifiers are generated using an SDK-provided generation utility.

## See also

[TSPI_phoneGetExtensionID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetextensionid)

[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion)