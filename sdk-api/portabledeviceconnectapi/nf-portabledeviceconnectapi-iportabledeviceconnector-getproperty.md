# IPortableDeviceConnector::GetProperty

## Description

The **GetProperty** method retrieves a property for the given MTP/Bluetooth Bus Enumerator device.

## Parameters

### `pPropertyKey` [in]

A pointer to a property key for the requested property.

### `pPropertyType` [out]

A pointer to a property type.

### `ppData` [out]

The address of a pointer to the property data.

### `pcbData` [out]

A pointer to the size (in bytes) of the property data.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The specified property key is not supported. |

## Remarks

The properties retrieved by this method are set on the device node. An example property key is **DEVPKEY_MTPBTH_IsConnected**, which indicates whether the device is currently connected.

Valid values for the *pPropertyType* parameter are system-defined base data types of the unified device property model. The data-type names start with the prefix **DEVPROP_TYPE_**.

Once the application no longer needs the property data specified by the *ppData* parameter, it must call **CoTaskMemAlloc** to free this data.

#### Examples

The following example shows how to read the DEVPKEY_MTPBTH_IsConnected property for a paired MTP/Bluetooth device.

```cpp
#include <devpkey.h>
#include <PortableDeviceConnectAPI.h>
HRESULT IsDeviceConnected(
__in  IPortableDeviceConnector* pDevice,
__out BOOL* pIsConnected)
{
    DEVPROPTYPE     typeGet;
    BYTE*           pDataGet;
    UINT32          cbDataGet;
    *pbIsConnected = FALSE;
    HRESULT hr = pDevice ->GetProperty(&DEVPKEY_MTPBTH_IsConnected,
                                       &typeGet,
                                       &pDataGet,
                                       &cbDataGet);
    if (SUCCEEDED(hr))
    {
        DEVPROP_BOOLEAN bIsConnected = *((DEVPROP_BOOLEAN*)pDataGet);
        if (bIsConnected == DEVPROP_TRUE)
        {
            * pIsConnected = TRUE;
        }
        // Release memory allocated by GetProperty
        CoTaskMemFree(pDataGet);
    }
    return hr;
}
```

## See also

[IPortableDeviceConnector](https://learn.microsoft.com/windows/desktop/api/portabledeviceconnectapi/nn-portabledeviceconnectapi-iportabledeviceconnector)