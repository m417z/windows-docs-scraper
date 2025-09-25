# IFaxOutgoingJob::get_TransmissionEnd

## Description

The **IFaxOutgoingJob::get_TransmissionEnd** property indicates the time that the outbound fax job completed transmission.

This property is read-only.

## Parameters

## Remarks

The property is not valid as long as the fax is still being sent by the fax device. It will have a value only after the transmission has ended. In the case of an individual fax, once the transmission has ended, the fax will be moved to the outgoing archive, and you will not be able to retrieve this value. You can instead retrieve the value of the [TransmissionEnd](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob-transmissionend-vb) property. In the case of a broadcast, each fax of the broadcast remains in the outgoing queue until the entire broadcast has been completed, and you can retrieve the value for the **IFaxOutgoingJob::get_TransmissionEnd** property.

In the case of a failed fax, this property will be assigned a value of zero. If you try to retrieve the property for a failed fax, you will receive an error.

## See also

[FaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob)

[IFaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outgoing-jobs)