# ISchedule::put_EndDate

## Description

Retrieves or sets the last date that the schedule is valid.

This property is read/write.

## Parameters

## Remarks

The end date must be greater than or equal to the start date.

The set cannot be started after the end date, but if the set is running when the end date is reached, it continues to run.

## See also

[ISchedule](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ischedule)

[ISchedule::StartDate](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ischedule-get_startdate)