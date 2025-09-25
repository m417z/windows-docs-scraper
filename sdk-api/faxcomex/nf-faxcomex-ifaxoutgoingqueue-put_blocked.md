# IFaxOutgoingQueue::put_Blocked

## Description

The **IFaxOutgoingQueue::get_Blocked** property is a Boolean value that indicates whether the job queue for outgoing faxes is blocked.

This property is read/write.

## Parameters

## Remarks

If this property is equal to **TRUE**, the outbound job queue is blocked and the fax service is not accepting outbound fax submissions. If this property is equal to **FALSE**, the queue is not blocked.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingqueue)

[IFaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingqueue)

[Setting the Outgoing Queue Properties](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-setting-the-outgoing-queue-properties)