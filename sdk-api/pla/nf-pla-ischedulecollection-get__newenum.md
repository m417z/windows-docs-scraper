# IScheduleCollection::get__NewEnum

## Description

Retrieves an interface to the enumeration.

This property is read-only.

## Parameters

## Remarks

 C++ programmers use this property.

The enumeration is a snapshot of the collection at the time of the call.

The items of the enumeration are variants whose type is VT_UNKNOWN. To query for the [ISchedule](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ischedule) interface, use the **punkVal** member of the variant.

## See also

[IScheduleCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ischedulecollection)