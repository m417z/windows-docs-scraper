# IPortableDeviceCapabilities::GetEventOptions

## Description

The **GetEventOptions** method retrieves all the supported options for the specified event on the device.

## Parameters

### `Event` [in]

A **REFGUID** that specifies a event to query for supported options. For a list of the events that are defined by Windows Portable Devices, see [Events](https://learn.microsoft.com/windows/desktop/wpd_sdk/commands).

### `ppOptions` [out]

Address of a variable that receives a pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that contains the supported options. If no options are supported, this will not contain any values. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the arguments was a **NULL** pointer. |

## See also

[IPortableDeviceCapabilities](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecapabilities-geteventoptions)

[IPortableDeviceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities)