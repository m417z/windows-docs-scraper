# IPortableDeviceService::Content

## Description

The **Content** method retrieves access to the service content.

## Parameters

### `ppContent` [out]

The [IPortableDeviceContent2](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecontent2) interface that accesses the service content.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** parameter was specified. |

## See also

[Enumerating Service Content](https://learn.microsoft.com/windows/desktop/wpd_sdk/enumerating-service-content)

[IPortableDeviceService Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice)

[Retrieving Content-Object Properties](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-content-object-properties)

[Writing Content-Object Properties](https://learn.microsoft.com/windows/desktop/wpd_sdk/writing-content-object-properties)