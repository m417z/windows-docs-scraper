# IEnhancedStorageSilo::GetPortableDevice

## Description

Obtains an [IPortableDevice](https://learn.microsoft.com/windows/win32/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice) pointer used to issue commands to the corresponding Enhanced Storage silo driver.

## Parameters

### `ppIPortableDevice` [out]

Pointer to a pointer to an [IPortableDevice](https://learn.microsoft.com/windows/win32/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice) object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Pointer to [IPortableDevice](https://learn.microsoft.com/windows/win32/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice) was obtained successfully. |
| **E_INVALIDARG** | *ppIPortableDevice* is **NULL**. |

## See also

[IEnhancedStorageSilo](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesilo)