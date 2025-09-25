# SNodeID structure

## Description

The
**SNodeID** structure is introduced in MMC 1.1, and is replaced by the
[SNodeID2](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-snodeid2) structure in MMC 1.2.

The
**SNodeID** structure defines the format of the data for the
[CCF_NODEID](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-nodeid) clipboard format.

The
**SNodeID** structure contains an array of bytes that represent the node ID.

## Members

### `cBytes`

The count of bytes in the **id** array.

The snap-in can also specify that a scope item should not be re-expanded when the console is reopened. To do this, set the **cBytes** member to 0 (zero) and return **S_OK** in the [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) method. Be aware that this setting not only keeps the selected item from being persisted but also prevents its parent item from automatically expanding when the console file is reopened.

### `id`

The bytes that contains the node ID of the scope item.

## Remarks

Your snap-in should support the **CCF_NODEID** clipboard format in its [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) method if any of its enumerated items has a volatile display name (such as the current computer name) or if any enumerated items should not be restored when the console file is reopened.

For details on using the
**SNodeID** structure and **CCF_NODEID** clipboard format, see
[CCF_NODEID](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-nodeid).

## See also

[CCF_NODEID](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-nodeid)