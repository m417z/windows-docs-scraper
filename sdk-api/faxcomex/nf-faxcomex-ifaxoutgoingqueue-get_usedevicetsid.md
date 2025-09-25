# IFaxOutgoingQueue::get_UseDeviceTSID

## Description

The **IFaxOutgoingQueue::get_UseDeviceTSID** property is a Boolean value that indicates whether the fax service uses the device transmitting station identifier (TSID) instead of a sender TSID.

This property is read/write.

## Parameters

## Remarks

If this property is equal to **TRUE**, the fax service uses the device TSID rather than a user-specified TSID. If this property is equal to **FALSE**, the fax service uses a user-specified TSID.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingqueue)

[IFaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingqueue)

[Setting the Outgoing Queue Properties](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-setting-the-outgoing-queue-properties)