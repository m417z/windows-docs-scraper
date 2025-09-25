# ITPhone::DeviceSpecificVariant

## Description

The
**DeviceSpecificVariant** method enables service providers to provide access to features not offered by other TAPI functions. The meaning of the extensions are device specific, and taking advantage of these extensions requires the application to be fully aware of them.

This method is provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[DeviceSpecific](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-devicespecific) method.

## Parameters

### `varDevSpecificByteArray` [in]

VARIANT containing the parameter block. The format of this parameter block is device specific; TAPI passes its contents between the application and the service provider.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[DeviceSpecific](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-devicespecific)

[NegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-negotiateextversion)

[lineDevSpecific](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedevspecific)