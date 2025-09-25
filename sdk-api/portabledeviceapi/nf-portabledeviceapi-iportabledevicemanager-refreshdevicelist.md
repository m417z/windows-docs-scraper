# IPortableDeviceManager::RefreshDeviceList

## Description

The **RefreshDeviceList** method refreshes the list of devices that are connected to the computer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When the **IPortableDeviceManager** interface is instantiated the first time, it generates a list of the devices that are connected. However, devices can connect and disconnect from the computer, making the original list obsolete. This method enables an application to refresh the list of connected devices.

This method is less resource-intensive than instantiating a new device manager to generate a new device list. However, it does require some resources; therefore, we recommend that you do not call this method arbitrarily. The best solution is to have the application register to get device arrival and removal notifications, and when a notification is received, have the application call this function.

## See also

[IPortableDeviceManager Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicemanager)