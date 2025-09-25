# IPortableDeviceService::Methods

## Description

The **Methods** method retrieves the [IPortableDeviceServiceMethods](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemethods) interface that is used to invoke custom functionality on the service.

## Parameters

### `ppMethods` [out]

The [IPortableDeviceServiceMethods](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemethods) interface used for invoking methods on the given service.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** parameter was specified. |

## See also

[IPortableDeviceService Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice)

[Invoking Service Methods](https://learn.microsoft.com/windows/desktop/wpd_sdk/invoking-methods-synchronously)

[Invoking Service Methods Asynchronously](https://learn.microsoft.com/windows/desktop/wpd_sdk/invoking-methods-asynchronously)