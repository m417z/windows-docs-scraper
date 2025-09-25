# IFaxOutgoingQueue::get_AllowPersonalCoverPages

## Description

The AllowPersonalCoverPages property is a Boolean value that indicates whether fax client applications can include a user-designed cover page with fax transmissions.

This property is read/write.

## Parameters

## Remarks

If this property is equal to **TRUE**, clients can include personal cover page files with fax transmissions. If this property is equal to **FALSE**, clients must use a common cover page file stored on the fax server.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingqueue)

[IFaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingqueue)

[Setting the Outgoing Queue Properties](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-setting-the-outgoing-queue-properties)