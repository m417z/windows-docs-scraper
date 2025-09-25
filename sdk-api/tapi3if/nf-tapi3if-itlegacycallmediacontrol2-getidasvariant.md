# ITLegacyCallMediaControl2::GetIDAsVariant

## Description

The
**GetIDAsVariant** method gets the identifier for the device associated with the current call.

This method is intended for Visual Basic and scripting applications. C/C++ applications should use the
[ITLegacyCallMediaControl::GetID](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol-getid) method.

## Parameters

### `bstrDeviceClass` [in]

**BSTR** representing the
[TAPI device class](https://learn.microsoft.com/windows/desktop/Tapi/tapi-device-classes).

### `pVarDeviceID` [out]

Pointer to a variant array of bytes of type VT_ARRAY | VT_UI1 which contains the identifier for the device specified in *bstrDeviceClass*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pVarDeviceID* parameter is not a valid pointer. |

## See also

[ITLegacyAddressMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacyaddressmediacontrol)

[ITLegacyCallMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol2)

[ITLegacyCallMediaControl::GetID](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol-getid)