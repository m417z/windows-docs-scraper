# ClusterNodeGetEnumCount function

## Description

Returns the number of [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) associated with a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) enumeration handle.

## Parameters

### `hNodeEnum` [in]

Handle to a node enumeration. This handle is obtained from [ClusterNodeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeopenenum). A valid handle is required. This parameter cannot be **NULL**.

## Return value

**ClusterNodeGetEnumCount** returns the number of objects associated with the enumeration handle.