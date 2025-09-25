# IFaxDevice::get_PoweredOff

## Description

The **IFaxDevice::get_PoweredOff** property is a Boolean value that indicates whether the fax device is currently available for sending and receiving faxes.

This property is read-only.

## Parameters

## Remarks

If this property is equal to **TRUE**, the fax device is currently offline and unavailable for sending and receiving faxes. If this property is equal to **FALSE**, the fax device is online and available.

**Note** The value of this property is set at the time that the [FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice) object is created and is refreshed when you call the [IFaxDevice::Refresh](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice-refresh-vb) method.

## See also

[FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice)

[IFaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdevice)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-fax-device-collection)