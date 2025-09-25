# IEnumWorkItems::Reset

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

 Resets the enumeration sequence to the beginning.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The enumeration sequence is reset to the beginning of the list. |
| **E_OUTOFMEMORY** | There is not enough available memory. |

## Remarks

A call to this method does not guarantee that the same set of tasks will be enumerated after the enumeration sequence is reset. Tasks may have been added to or deleted from the collection while you were enumerating the list.

The
[IEnumWorkItems](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ienumworkitems) interface also provides methods for retrieving sets of tasks, skipping sets of tasks, and making a copy of the current state of the enumeration.

## See also

[IEnumWorkItems](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ienumworkitems)

[IEnumWorkItems::Clone](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-clone)

[IEnumWorkItems::Next](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-next)

[IEnumWorkItems::Skip](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-skip)