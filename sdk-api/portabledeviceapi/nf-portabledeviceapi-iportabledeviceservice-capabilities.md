# IPortableDeviceService::Capabilities

## Description

The **Capabilities** method retrieves the service capabilities.

## Parameters

### `ppCapabilities` [out]

The [IPortableDeviceServiceCapabilities](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities) interface specifying the capabilities of the service.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** parameter was specified. |

## See also

[IPortableDeviceService Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice)

[Retrieving Supported Service Events](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-events)

[Retrieving Supported Service Formats](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-formats)

[Retrieving Supported Service Methods](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-methods)