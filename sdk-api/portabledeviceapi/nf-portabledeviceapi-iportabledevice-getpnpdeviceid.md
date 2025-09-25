# IPortableDevice::GetPnPDeviceID

## Description

The **GetPnPDeviceID** method retrieves the Plug and Play (PnP) device identifier that the application used to open the device.

## Parameters

### `ppszPnPDeviceID` [out]

Pointer to a null-terminated string that contains the Plug and Play ID string for the device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_WPD_DEVICE_NOT_OPEN** | The [IPortableDevice::Open](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevice-open) method has not been called yet for this device. |

## Remarks

After the application is through using the string returned by this method, it must call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the string.

The *ppszPnPDeviceID* argument must not be set to **NULL**.

## See also

[IPortableDevice Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice)

[IPortableDevice::Open](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevice-open)