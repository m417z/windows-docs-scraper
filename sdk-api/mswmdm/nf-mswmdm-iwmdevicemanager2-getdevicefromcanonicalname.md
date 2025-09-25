# IWMDeviceManager2::GetDeviceFromCanonicalName

## Description

The **GetDeviceFromCanonicalName** method retrieves an **IWMDMDevice** interface for a device with a specified canonical name. You can retrieve a device's canonical name by calling [IWMDMDevice2::GetCanonicalName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice2-getcanonicalname).

## Parameters

### `pwszCanonicalName`

A wide-character, **null**-terminated string specifying the canonical name of the device.

### `ppDevice`

Pointer to a pointer to the [IWMDMDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice) interface of the device object with the specified canonical name. The caller must release this interface when done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *pwszCanonicalName* or *ppDeviceArray* parameter is an invalid or **NULL** pointer. |
| **S_FALSE** | There is no connected device found with canonical name *pwszCanonicalName*. |

## Remarks

This method can be useful if an application implements [IWMDMNotification](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmnotification), which sends a canonical name notification when a device connects or disconnects from the computer.

## See also

[IWMDMDevice2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice2)

[IWMDeviceManager2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdevicemanager2)