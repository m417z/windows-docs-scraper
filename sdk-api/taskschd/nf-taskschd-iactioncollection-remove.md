# IActionCollection::Remove

## Description

Removes the specified action from the collection.

## Parameters

### `index` [in]

The index of the action to be removed. Use a LONG value for the index number.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IActionCollection::Remove** returns E_INVALIDARG and E_TYPE_MISMATCH instead of E_INVALID_VARIANT when an invalid argument is specified.

When removing items, note that the index for the first item in the collection is 1 and the index for the last item is the value of the [Count](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iactioncollection-get_count) property of IActionCollection.

## See also

[IActionCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iactioncollection)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)