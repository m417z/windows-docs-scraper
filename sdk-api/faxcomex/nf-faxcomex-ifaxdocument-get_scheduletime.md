# IFaxDocument::get_ScheduleTime

## Description

The **IFaxDocument::get_ScheduleTime** property indicates the time to submit the fax for processing to the fax service.

This property is read/write.

## Parameters

## Remarks

If the time specified has passed, the fax service sends the fax as soon as a device is available. By default, **IFaxDocument::get_ScheduleTime** is set to zero, meaning that no time is specified.

Note that the fax service ignores this parameter unless you set the [IFaxDocument::get_ScheduleType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-scheduletype-vb) property to [fstSpecific_TIME](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_schedule_type_enum).

**Note** The value of the **IFaxDocument::get_ScheduleTime** property must include the date and time for submitting the fax.

## See also

[FaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument)

[IFaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-sending-a-fax)