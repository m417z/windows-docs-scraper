# IWMDMEnumDevice::Next

## Description

The **Next** method returns a pointer to the next device, represented by an [IWMDMDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice) interface.

## Parameters

### `celt` [in]

Number of devices requested.

### `ppDevice` [out]

Pointer to caller-allocated array of [IWMDMDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice) interface pointers. The size of this array must be **IWMDMDevice** *[celt]. The caller must release these interfaces when done with them. To avoid allocating a whole array, simply pass in the address of a pointer to an **IWMDMDevice** interface, as shown in Remarks.

### `pceltFetched` [out]

Pointer to a variable that receives the number of devices (interfaces) returned.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The returned device interface(s) are based on a cached list of devices. If a Plug and Play device is attached or removed, the current enumerator will not reflect that, and therefore, **Next** will return devices based on the cached list. Applications should obtain a new enumerator object by calling [IWMDeviceManager::EnumDevices](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdevicemanager-enumdevices) to get a refreshed list of devices.

If you only want to retrieve a single interface at a time, you do not need to allocate an array for this method, as shown in the following code:

```cpp

// Get a device enumerator to examine each device.
CComPtr<IWMDeviceManager2> pIWMDevMgr2;
hr = m_IWMDeviceMgr->QueryInterface (__uuidof(IWMDeviceManager2), (void**) &pIWMDevMgr2);
if (hr == S_OK)
{
    // TODO: Display a message that the application retrieved IWMDeviceManager2.
}
else
{
    // TODO: Display a message that the application was not able to
    // retrieve IWMDeviceManager2 in EnumDevices.
    return hr;
}

// Enumerate through the devices using the faster EnumDevices2 plug-and-play method.
CComPtr<IWMDMEnumDevice> pEnumDevice;
hr = pIWMDevMgr2->EnumDevices2(&pEnumDevice);
if (hr != S_OK)
{
    //.TODO: Display a message that an error occurred in calling EnumDevices2.
    return hr;
}

// Enumerate through devices.
IWMDMDevice *pIWMDMDevice;
ULONG ulFetched = 0;
while(pEnumDevice->Next(1, &pIWMDMDevice, &ulFetched) == S_OK)
{
    if (ulFetched != 1)
    {
        return E_FAIL;
    }
    // Do some stuff here....
}

```

## See also

[Enumerating Devices](https://learn.microsoft.com/windows/desktop/WMDM/enumerating-devices)

[IWMDMEnumDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumdevice)

[IWMDeviceManager::EnumDevices](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdevicemanager-enumdevices)