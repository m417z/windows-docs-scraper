# IPortableDevice::Close

## Description

The **Close** method closes the connection with the device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You should not usually need to call this method yourself. When the last reference to the [IPortableDevice](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice) interface is released, Windows Portable Devices calls **Close** for you. Calling this method manually forces the connection to the device to close, and any Windows Portable Devices objects hosted on this device will cease to function. You can call [Open](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevice-open) to reopen the connection.

## See also

[IPortableDevice Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice)

[IPortableDevice::Open](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevice-open)