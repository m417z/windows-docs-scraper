# FAX_SCHEDULE_TYPE_ENUM enumeration

## Description

The **FAX_SCHEDULE_TYPE_ENUM** enumeration defines the types of scheduling for outbound faxes.

## Constants

### `fstNOW:0`

Send the fax as soon as a device is available.

### `fstSPECIFIC_TIME`

Send the fax no sooner than the specified time. The actual time that the fax will be sent depends on device availability and fax priority.

### `fstDISCOUNT_PERIOD`

Send the fax during the discount rate period.

## See also

[IFaxDocument::get_ScheduleTime](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-scheduletime-vb)

[IFaxDocument::get_ScheduleType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-scheduletype-vb)

[IFaxOutgoingQueue::get_DiscountRateEnd](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingqueue-discountrateend-vb)

[IFaxOutgoingQueue::get_DiscountRateStart](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingqueue-discountratestart-vb)