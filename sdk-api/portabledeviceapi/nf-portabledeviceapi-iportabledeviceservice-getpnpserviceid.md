# IPortableDeviceService::GetPnPServiceID

## Description

The **GetPnPServiceID** method retrieves a Plug and Play (PnP) identifier for the service.

## Parameters

### `ppszPnPServiceID` [out]

The retrieved PnP identifier, which is the same identifier that was passed to the [Open](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservice-open) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** parameter was specified. |
| **E_WPD_SERVICE_NOT_OPEN** | The [Open](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservice-open) method has not yet been called for the service. |

## Remarks

The [Open](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservice-open) method must be called on the service before a PnP identifier can be retrieved.

When an application no longer needs the PnP identifier, it should call the **CoTaskMemFree** function to free the identifier memory.

## See also

[IPortableDeviceService Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice)