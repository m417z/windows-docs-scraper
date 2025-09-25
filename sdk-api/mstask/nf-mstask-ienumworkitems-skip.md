# IEnumWorkItems::Skip

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Skips the next specified number of tasks in the enumeration sequence.

## Parameters

### `celt` [in]

The number of tasks to be skipped.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The number of elements skipped equals *celt*. |
| **S_FALSE** | The number of elements remaining in the sequence is less than the value specified in *celt*. |
| **E_INVALIDARG** | The value of *celt* is less than or equal to zero. |

## Remarks

The
[IEnumWorkItems](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ienumworkitems) interface also provides methods for retrieving sets of tasks, resetting the enumeration sequence, and making a copy of the current state of the enumeration.

## See also

[IEnumWorkItems](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ienumworkitems)

[IEnumWorkItems::Clone](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-clone)

[IEnumWorkItems::Next](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-next)

[IEnumWorkItems::Reset](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-reset)