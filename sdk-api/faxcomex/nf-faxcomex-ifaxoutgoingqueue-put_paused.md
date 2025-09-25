# IFaxOutgoingQueue::put_Paused

## Description

The **IFaxOutgoingQueue::get_Paused** property is a Boolean value that indicates whether the job queue for outgoing faxes is paused.

This property is read/write.

## Parameters

## Remarks

If this property is equal to **TRUE**, the job queue is paused and the fax service is not processing jobs in the queue. If this property is equal to **FALSE**, the outgoing queue is not paused.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingqueue)

[IFaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingqueue)

[Setting the Outgoing Queue Properties](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-setting-the-outgoing-queue-properties)