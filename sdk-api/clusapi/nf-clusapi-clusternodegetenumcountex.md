# ClusterNodeGetEnumCountEx function

## Description

Returns the number of
cluster objects that are associated with a
node enumeration handle.

## Parameters

### `hNodeEnum` [in]

The handle to a node enumeration that was retrieved by the [ClusterNodeOpenEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeopenenumex) function. A valid handle is required. This parameter cannot be **NULL**.

## Return value

The number of objects that are associated with the enumeration handle.

## See also

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)