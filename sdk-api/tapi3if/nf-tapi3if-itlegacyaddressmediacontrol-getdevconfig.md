# ITLegacyAddressMediaControl::GetDevConfig

## Description

The
**GetDevConfig** method returns an opaque data structure. The exact contents are specific to the service provider and device class. The data structure specifies the configuration of a device associated with a particular line device. For example, the contents of this structure could specify data rate, character format, modulation schemes, and error control protocol settings for a datamodem device associated with the line.

## Parameters

### `pDeviceClass` [in]

Pointer to **BSTR** containing
[TAPI device class](https://learn.microsoft.com/windows/desktop/Tapi/tapi-device-classes) for which configuration information is needed.

### `pdwSize` [out]

Pointer to size of configuration array.

### `ppDeviceConfig` [out]

Pointer to array of bytes containing device configuration information.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDeviceClass*, *pdwSize*, or *ppDeviceConfig* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

This method is a COM wrapper for the
[LineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig) TAPI 2.1 function.

The
[GetID](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol-getid) must be performed prior to calling this method.

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pDeviceClass* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

The application must call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory allocated for the *ppDeviceConfig* parameter.

**TAPI 2.1 Cross-References:** [lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig), [lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetdevconfig)

## See also

[ITLegacyAddressMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacyaddressmediacontrol)

[ITLegacyCallMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol)

[SetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacyaddressmediacontrol-setdevconfig)