# IFaxDevice::get_TSID

## Description

The **IFaxDevice::get_TSID** property is a null-terminated string that contains the transmitting station identifier (TSID) for the device.

This property is read/write.

## Parameters

## Remarks

**Note** The TSID is limited to 20 characters. Also, because most fax machines accept a limited set of characters in the fax transmission called station identifier (CSID) and TSID strings, it is advisable to use only English letters, numeric symbols, and punctuation marks (ASCII range 0x20 to 0x7F) in these strings.

## See also

[FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice)

[IFaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdevice)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-configuring-a-fax-device)