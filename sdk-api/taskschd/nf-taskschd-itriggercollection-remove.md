# ITriggerCollection::Remove

## Description

Removes the specified trigger from the collection of triggers used by the task.

## Parameters

### `index` [in]

The index of the trigger to be removed. Use a LONG value for the index number.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When removing items, note that the index for the first item in the collection is 1 and the index for the last item is the value of the [Count](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itriggercollection-get_count) property.

This method will return **E_INVALIDARG** when the value passed to the *index* parameter is not valid.

## See also

[ITriggerCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itriggercollection)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)