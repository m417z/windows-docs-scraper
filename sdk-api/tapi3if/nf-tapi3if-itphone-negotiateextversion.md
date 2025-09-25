# ITPhone::NegotiateExtVersion

## Description

The
**NegotiateExtVersion** method allows an application to negotiate an extension version to use with the specified phone device. This operation need not be called if the application does not support provider specific extensions.

## Parameters

### `lLowVersion` [in]

Least recent extension version of the extension identifier returned by
**NegotiateExtVersion** that the application is compliant with. The high-order word is the major version number; the low-order word is the minor version number.

### `lHighVersion` [in]

Most recent extension version of the extension identifier returned by
**NegotiateExtVersion** that the application is compliant with. The high-order word is the major version number; the low-order word is the minor version number.

### `plExtVersion` [out]

Pointer to a **long** that contains the extension version number that was negotiated. If negotiation succeeds, this number is in the range between *lLowVersion* and *lHighVersion*.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The version in *lHighVersion* or *lLowVersion* is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *plExtVersion* parameter is not a valid pointer. |

## See also

[DeviceSpecific](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-devicespecific)

[DeviceSpecificVariant](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-devicespecificvariant)

[lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateextversion)