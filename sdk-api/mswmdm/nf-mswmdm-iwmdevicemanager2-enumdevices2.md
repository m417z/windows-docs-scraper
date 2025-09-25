# IWMDeviceManager2::EnumDevices2

## Description

The **EnumDevices2** method retrieves an enumeration interface that is used to enumerate portable devices connected to the computer.

Microsoft strongly recommends that applications use the **EnumDevices2** method instead of [IWMDeviceManager::EnumDevices](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdevicemanager-enumdevices).

## Parameters

### `ppEnumDevice` [out]

Pointer to a pointer to an [IWMDMEnumDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumdevice) interface. The caller is responsible for calling **Release** on the retrieved interface.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method returns an enumerator that takes advantage of the Plug and Play (PnP) system for a faster enumeration and lower memory use. For PnP-complaint service providers, it loads in memory only those service providers that have a device currently connected to the computer, and requests only those service providers to create device objects.

This method returns a snapshot of the devices connected when the underlying object was first created. To ensure that the device list is up to date, call [Reinitialize](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdevicemanager2-reinitialize) before calling this method.

#### Examples

The following C++ code loops through all the devices and retrieves the display name of each.

```cpp

// Enumerate through the devices using the faster EnumDevices2 Plug-and-Play method.
// IWMDevMgr2 is a global IWMDeviceManager2 pointer.
CComPtr<IWMDMEnumDevice> pEnumDevice;
hr = pIWMDevMgr2->EnumDevices2(&pEnumDevice);
if (hr == S_OK)
{
    // Length of all the strings we'll send in.
    const UINT MAX_CHARS = 100;
    WCHAR name[MAX_CHARS];

    // Enumerate through devices using a dummy loop.
    while(TRUE)
    {
        // Get a device handle.
        IWMDMDevice* pDevice;
        ULONG ulFetched = 0;
        hr = pEnumDevice->Next(1, &pDevice, &ulFetched);
        CComQIPtr<IWMDMDevice2> pDevice2(pDevice);

        if (hr != S_OK || ulFetched != 1)
        {
            break;
        }
        ZeroMemory(name, MAX_CHARS);
        hr = pDevice2->GetName(name, MAX_CHARS);
    }
}

```

## See also

[Enumerating Devices](https://learn.microsoft.com/windows/desktop/WMDM/enumerating-devices)

[IWMDMEnumDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumdevice)

[IWMDeviceManager2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdevicemanager2)