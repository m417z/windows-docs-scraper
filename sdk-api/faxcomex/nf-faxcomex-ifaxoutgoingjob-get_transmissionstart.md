# IFaxOutgoingJob::get_TransmissionStart

## Description

The **IFaxOutgoingJob::get_TransmissionStart** property indicates the time that the fax outbound job began transmitting. This property will have a value only after the transmission has started.

This property is read-only.

## Parameters

## Remarks

In the case of a failed fax, this property will be assigned a value of zero. If you try to retrieve the property for a failed fax, you will receive an error.

## See also

[FaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob)

[IFaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outgoing-jobs)