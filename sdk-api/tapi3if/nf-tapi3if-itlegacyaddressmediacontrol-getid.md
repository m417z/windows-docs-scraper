# ITLegacyAddressMediaControl::GetID

## Description

The
**GetID** method returns a device identifier for the specified device class associated with the current address.

This method is intended for C/C++ applications only. There is no corresponding method available for Visual Basic and scripting applications.

## Parameters

### `pDeviceClass` [in]

Pointer to **BSTR** containing
[TAPI device class](https://learn.microsoft.com/windows/desktop/Tapi/tapi-device-classes) for which configuration information is needed.

### `pdwSize` [out]

Length of device identifier returned.

### `ppDeviceID` [out]

Device identifier.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_FAIL** | Method failed. This may mean there is no device of a specified class associated with the current address. |
| **E_POINTER** | The *pdwSize* or *ppDeviceID* parameter is not a valid pointer. |

## Remarks

The application must call
[ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications) prior to calling this method.

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pDeviceClass* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

The application must call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory allocated for the *ppDeviceID* parameter.

**TAPI 2.1 Cross-References:** [lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig), [lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetdevconfig), [lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid)

## See also

[GetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol-getdevconfig)

[ITLegacyAddressMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacyaddressmediacontrol)

[ITLegacyCallMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol)

[SetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol-setdevconfig)