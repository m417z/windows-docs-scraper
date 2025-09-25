# IPortableDeviceCapabilities::GetSupportedEvents

## Description

The **GetSupportedEvents** method retrieves the supported events for this device.

## Parameters

### `ppEvents` [out]

Address of a variable that receives a pointer to an [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that lists the supported events. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the arguments was a **NULL** pointer. |

## See also

[IPortableDeviceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities)