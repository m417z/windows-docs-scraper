# IRunningTaskCollection::get_Item

## Description

Gets the specified task from the collection.

This property is read-only.

## Parameters

## Remarks

IRunningTaskCollection::get_Item returns E_INVALIDARG and E_TYPE_MISMATCH instead of E_INVALID_VARIANT when an invalid argument is specified.

Collections are 1-based. That is, the index for the first item in the collection is 1.

## See also

[IRunningTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-irunningtask)

[IRunningTaskCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-irunningtaskcollection)