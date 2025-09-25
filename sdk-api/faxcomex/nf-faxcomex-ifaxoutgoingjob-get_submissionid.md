# IFaxOutgoingJob::get_SubmissionId

## Description

The **IFaxOutgoingJob::get_SubmissionId** property is a null-terminated string that contains the unique identifier assigned to the fax job during the submission process.

This property is read-only.

## Parameters

## Remarks

All fax jobs created by the same submission process share the same unique submission ID. When you submit a fax to be sent to more than one recipient, separate fax jobs will be created, but as part of the same fax broadcast, they will share the same **SubmissionID**.

## See also

[FaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob)

[IFaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outgoing-jobs)