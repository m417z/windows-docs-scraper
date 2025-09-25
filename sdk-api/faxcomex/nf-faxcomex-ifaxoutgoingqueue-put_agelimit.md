# IFaxOutgoingQueue::put_AgeLimit

## Description

The **IFaxOutgoingQueue::get_AgeLimit** property is a value that indicates the number of days that the fax service retains an unsent job in the fax job queue.

This property is read/write.

## Parameters

## Remarks

If the fax job remains in the outbound job queue longer than the value specified, the fax service deletes the job. If the value of this property is zero, the fax service does not enforce an age limit.

To read or to write to this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingqueue)

[IFaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingqueue)

[Setting the Outgoing Queue Properties](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-setting-the-outgoing-queue-properties)