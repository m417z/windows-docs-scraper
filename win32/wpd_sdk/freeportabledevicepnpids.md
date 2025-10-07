# FreePortableDevicePnPIDs function

The **FreePortableDevicePnPIDs** helper function frees the Plug and Play (PnP) identifiers that are retrieved by the [**IPortableDeviceManager::GetDevices**](https://learn.microsoft.com/windows/desktop/api/PortableDeviceApi/nf-portabledeviceapi-iportabledevicemanager-getdevices) or [**IPortableDeviceServiceManager::GetDeviceServices**](https://learn.microsoft.com/windows/desktop/api/PortableDeviceAPI/nf-portabledeviceapi-iportabledeviceservicemanager-getdeviceservices) methods.

## Parameters

*pPnPIDs*

The array of Plug and Play (PnP) identifiers to be freed.

*cPnPIDs*

The number of identifiers in the array specified by the *pPnPIDs* parameter.

## Return value

This function does not return a value.

## Remarks

The application is responsible for freeing the array of pointers that it allocates.

## Examples

```C++
// Allocate an array of LPWSTR pointers.
    LPWSTR* pPnpDeviceIDs = new LPWSTR[cPnpDeviceIDs];
if (pPnpDeviceIDs != NULL)
{
    hr = pPortableDeviceManager->;GetDevices(pPnpDeviceIDs, &cPnpDeviceIDs);
    if (SUCCEEDED(hr))
    {
        // Free all returned PnPDeviceID strings allocated by IPortableDeviceManager::GetDevices.
     FreePortableDevicePnPIDs(pPnpDeviceIDs, cPnpDeviceIDs);
     // Application is responsible for deleting the array of LPWSTR pointers.
     delete [] pPnpDeviceIDs;
     pPnpDeviceIDs = NULL;
 }
}
```

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps \| UWP apps\]<br> |
| Minimum supported server<br> | None supported<br> |
| Header<br> | PortableDevice.h |

