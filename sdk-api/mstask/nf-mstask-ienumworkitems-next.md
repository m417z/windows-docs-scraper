# IEnumWorkItems::Next

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the next specified number of tasks in the enumeration sequence.

If there are fewer than the requested number of tasks left in the sequence, all the remaining elements are retrieved.

## Parameters

### `celt` [in]

The number of tasks to retrieve.

### `rgpwszNames` [out]

A pointer to an array of pointers (**LPWSTR**) to **null**-terminated character strings containing the file names of the tasks returned from the enumeration sequence. These file names are taken from the [Scheduled Tasks folder](https://learn.microsoft.com/windows/desktop/TaskSchd/s) and have the ".job" extension.

After processing the names returned in *rgpwszNames*, you must first free each character string in the array and then the array itself using **CoTaskMemFree**.

### `pceltFetched` [out]

A pointer to the number of tasks returned in *rgpwszNames*. If the *celt* parameter is 1, this parameter may be **NULL**.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The number of tasks retrieved equals the number requested. |
| **S_FALSE** | The number returned is less than the number requested. (Thus, there are no more tasks to enumerate.) |
| **E_INVALIDARG** | A parameter is invalid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |

## Remarks

The
[IEnumWorkItems](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ienumworkitems) interface also provides methods for resetting the enumeration, skipping tasks, and making a copy of the current state of the enumeration.

#### Examples

For an example of how to use **Next** to enumerate the tasks in the Scheduled Tasks folder, see [Enumerating Tasks Example](https://learn.microsoft.com/windows/desktop/TaskSchd/enumerating-tasks-example).

## See also

[IEnumWorkItems](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ienumworkitems)

[IEnumWorkItems::Clone](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-clone)

[IEnumWorkItems::Reset](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-reset)

[IEnumWorkItems::Skip](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-skip)