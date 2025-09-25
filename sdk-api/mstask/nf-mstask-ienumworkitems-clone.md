# IEnumWorkItems::Clone

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

 Creates a new enumeration object that contains the same enumeration state as the current enumeration.

Because the new object points to the same place in the enumeration sequence, a client can use the
**Clone** method to record a particular point in the enumeration sequence and return to that point later.

## Parameters

### `ppEnumWorkItems` [out]

A pointer to a pointer to a new
[IEnumWorkItems](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ienumworkitems) interface. This pointer will point to the newly created enumeration. If the method fails, this parameter is undefined.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The argument is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory available. |
| **E_UNEXPECTED** | An error occurred. |

## Remarks

The
[IEnumWorkItems](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ienumworkitems) interface also provides methods for retrieving sets of tasks, skipping sets of tasks, and resetting the enumeration sequence.

## See also

[IEnumWorkItems](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ienumworkitems)

[IEnumWorkItems::Next](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-next)

[IEnumWorkItems::Reset](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-reset)

[IEnumWorkItems::Skip](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ienumworkitems-skip)