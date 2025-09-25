# ITLegacyAddressMediaControl::SetDevConfig

## Description

The
**SetDevConfig** function allows the application to restore the configuration of a media stream device on a line device to a setup previously obtained using
[GetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol-getdevconfig).

## Parameters

### `pDeviceClass` [in]

Pointer to **BSTR** containing
[TAPI device class](https://learn.microsoft.com/windows/desktop/Tapi/tapi-device-classes) for which configuration information is needed.

### `dwSize` [in]

Size of configuration array.

### `pDeviceConfig` [in]

Pointer to the array of bytes containing device configuration information obtained by a call to
[GetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol-getdevconfig).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDeviceClass*, *pdwSize*, or *ppDeviceConfig* parameter is not a valid pointer. |
| **E_INVALIDARG** | The *pdwSize* parameter is zero. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

This method is a COM wrapper for the
[lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetdevconfig) TAPI 2.1 function.

The
[GetID](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol-getid) must be performed prior to calling this method.

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pDeviceClass* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

**TAPI 2.1 Cross-References:** [lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig), [lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetdevconfig)

## See also

[GetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol-getdevconfig)

[ITLegacyAddressMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacyaddressmediacontrol)

[ITLegacyCallMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol)