# IFaxIncomingJob::get_ExtendedStatus

## Description

The **ExtendedStatus** property is a null-terminated string that describes the job's extended status.

This property is read-only.

## Parameters

## Remarks

The **ExtendedStatus** property can have a value only if the fax service provider (FSP) returns a proprietary status code in the [ExtendedStatusCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob-extendedstatuscode) property. Otherwise, the **ExtendedStatus** property will contain an empty string.

## See also

[FaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob)

[IFaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjob)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-incoming-queue)