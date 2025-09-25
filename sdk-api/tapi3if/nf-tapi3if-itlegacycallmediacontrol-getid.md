# ITLegacyCallMediaControl::GetID

## Description

The
**GetID** method gets the identifier for the device associated with the current call.

This method is intended for C/C++ applications. Visual Basic and scripting applications should use the
[ITLegacyCallMediaControl2::GetIDAsVariant](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-getidasvariant) method.

## Parameters

### `pDeviceClass` [in]

Pointer to **BSTR** representing the
[TAPI device class](https://learn.microsoft.com/windows/desktop/Tapi/tapi-device-classes).

### `pdwSize` [out]

Size in bytes of device identifier.

### `ppDeviceID` [out]

Device identifier.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pdwSize* or *ppDeviceID* parameter is not a valid pointer. |

## Remarks

The application must call
[ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications) prior to calling this method.

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pDeviceClass* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

The application must call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory allocated for the *ppDeviceID* parameter.

## See also

[ITLegacyAddressMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacyaddressmediacontrol)

[ITLegacyCallMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol)

[ITLegacyCallMediaControl2::GetIDAsVariant](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-getidasvariant)