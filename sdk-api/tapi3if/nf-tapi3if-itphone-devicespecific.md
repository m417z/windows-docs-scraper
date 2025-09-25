# ITPhone::DeviceSpecific

## Description

The
**DeviceSpecific** method enables service providers to provide access to device specific features not offered by other TAPI functions. The meaning of the extensions are device specific, and taking advantage of these extensions requires the application to be fully aware of them.

This method is provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[DeviceSpecificVariant](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-devicespecificvariant) method.

## Parameters

### `pParams` [in]

Pointer to a memory area used to hold a parameter block. The format of this parameter block is device specific; TAPI passes its contents between the application and the service provider.

### `dwSize` [in]

The size, in bytes, of the parameter block area.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pParams* parameter is not a valid pointer. |

## Remarks

> [!CAUTION]
> TAPI will write the returned data to the buffer referenced by *pParams* when the [LINE_REPLY](https://learn.microsoft.com/windows/win32/tapi/line-reply) message is returned. This means that the buffer must remain valid until the LINE_REPLY message is returned; otherwise, data corruption and exceptions may occur.

## See also

[DeviceSpecificVariant](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-devicespecificvariant)

[NegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress2-negotiateextversion)

[lineDevSpecific](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedevspecific)