# IFaxDevice::get_ReceiveMode

## Description

The [ReceiveMode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice-receivemode) property is a value from the [FAX_DEVICE_RECEIVE_MODE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_device_receive_mode_enum) enumeration that defines the way a device answers an incoming call. The value assigned to this property indicates whether the device does not answer the call, the device can answer the call manually, or the device answers the call automatically.

This property is read/write.

## Parameters

## Remarks

You can set only one device to receive faxes manually at any given time. If you set a device to answer manually and another device is already set to the manual mode, the device that had been previously set will automatically change to the no-answer mode. You should call the [IFaxDevice::Refresh](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice-refresh-vb) method on that device to see the change.

Some devices, such as virtual devices, do not support the manual-answer receive mode. For those devices, the [ReceiveMode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice-receivemode) will fail if you set the receive mode to [fdrmMANUAL_ANSWER](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_device_receive_mode_enum). In C++, the method will return an ERROR_NOT_SUPPORTED error code in an **HRESULT** format.

## See also

[FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice)

[IFaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdevice)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-configuring-a-fax-device)