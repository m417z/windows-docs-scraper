# IFaxIncomingJob::get_TransmissionEnd

## Description

The **TransmissionEnd** property indicates the time at which the inbound fax job completed transmission.

This property is read-only.

## Parameters

## Remarks

The **TransmissionEnd** property is not valid as long as the fax is still being received by the fax device. In the case of a fax that is still in progress, this property will be assigned a value of zero. If you try to retrieve the property for a fax that is still in progress you will receive an error.

## See also

[FaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob)

[IFaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjob)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-incoming-queue)