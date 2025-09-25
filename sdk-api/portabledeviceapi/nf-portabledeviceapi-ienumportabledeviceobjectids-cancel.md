# IEnumPortableDeviceObjectIDs::Cancel

## Description

The **Cancel** method cancels a pending operation.

## Return value

The method returns an
**HRESULT**
. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was canceled successfully. |
| **E_WPD_DEVICE_NOT_OPEN** | The device is not opened. |

## Remarks

This method cancels all pending operations on the current device handle, which corresponds to a session associated with an [IPortableDevice](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice) interface. The Windows Portable Devices (WPD) API does not support targeted cancellation of specific operations.

## See also

[IEnumPortableDeviceObjectIDs Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-ienumportabledeviceobjectids)