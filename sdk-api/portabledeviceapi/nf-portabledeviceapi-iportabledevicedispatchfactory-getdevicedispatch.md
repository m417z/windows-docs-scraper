# IPortableDeviceDispatchFactory::GetDeviceDispatch

## Description

Instantiates a WPD Automation [Device](https://learn.microsoft.com/previous-versions/windows/desktop/wiaaut/-wiaaut-device) object for a given WPD device identifier.

## Parameters

### `pszPnPDeviceID` [in]

A pointer to a **String** that is used by Plug-and-play to identify a currently connected WPD device. The Plug and Play (PnP) identifier for a particular device can be obtained from the [IPortableDeviceManager::GetDevices](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicemanager-getdevices) method in the WPD C++/COM API.

### `ppDeviceDispatch` [out]

Contains a pointer to the **IDispatch** implementation for the WPD Automation [Device](https://learn.microsoft.com/previous-versions/windows/desktop/wiaaut/-wiaaut-device) object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

 For an example of how to use **GetDeviceDispatch** method to instantiate a WPD Automation **Device** object, see
[Instantiating the WPD Automation Factory Interface](https://learn.microsoft.com/previous-versions/windows/desktop/wpdauto/instantiating-the-wpd-automation-factory-interface).

## See also

[Device Object](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd389207(v=vs.85))

[IPortableDeviceDispatchFactory Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicedispatchfactory)

[Instantiating the WPD Automation Factory Interface](https://learn.microsoft.com/previous-versions/windows/desktop/wpdauto/instantiating-the-wpd-automation-factory-interface)