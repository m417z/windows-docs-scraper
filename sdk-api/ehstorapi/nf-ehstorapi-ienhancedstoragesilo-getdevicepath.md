# IEnhancedStorageSilo::GetDevicePath

## Description

Retrieves the path to the silo device node. The returned string is suitable for passing to **Windows System** APIs such as [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) or [SetupDiOpenDeviceInterface](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendeviceinterfacea).

## Parameters

### `ppwszSiloDevicePath` [out]

A pointer to a string that represents the path to the Silo device node.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Device path string was retrieved successfully. |
| **E_INVALIDARG** | *ppwszSiloDevicePath* is **NULL**. |

## Remarks

The memory to contain the device path string is allocated by the Enhanced Storage API and must be freed by passing the returned pointer to [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[IEnhancedStorageSilo](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesilo)