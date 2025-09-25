# IScheduleCollection::Remove

## Description

Removes a schedule from the collection.

## Parameters

### `vSchedule` [in]

The zero-based index of the schedule to remove from the collection. The variant type can be VT_I4, VT_UI4, or VT_DISPATCH.

## Return value

Returns S_OK if successful.

## Remarks

If the variant type is VT_DISPATCH, pass the **IDispatch** interface of the [ISchedule](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ischedule) interface to be removed.

## See also

[IScheduleCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ischedulecollection)

[IScheduleCollection::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ischedulecollection-add)

[IScheduleCollection::Clear](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ischedulecollection-clear)