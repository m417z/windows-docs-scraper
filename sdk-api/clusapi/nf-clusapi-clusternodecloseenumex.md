# ClusterNodeCloseEnumEx function

## Description

Closes a
node enumeration handle.

## Parameters

### `hNodeEnum` [in]

The handle to the node enumeration to close. This handle is returned by the [ClusterNodeOpenEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeopenenumex) function.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.
If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)