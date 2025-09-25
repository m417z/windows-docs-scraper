# SNodeID2 structure

## Description

The
**SNodeID2** structure is introduced in MMC 1.2, and replaces the
[SNodeID](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-snodeid) structure.

The
**SNodeID2** structure is used by the
[CCF_NODEID2](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-nodeid2) clipboard format.

The
**SNodeID2** structure contains an array of bytes that represent the node ID.

## Members

### `dwFlags`

Currently, only the MMC_NODEID_SLOW_RETRIEVAL flag is defined for **dwFlags**. If this flag is set, MMC will not persist the specified scope item except where absolutely necessary, as for example for console taskpads. Console taskpads always persist the target items and task target items.

### `cBytes`

The count of bytes in the **id** array.

### `id`

The bytes that contains the node ID of the scope item.

## Remarks

For details on using the
**SNodeID2** structure with the CCF_NODEID2 clipboard format, see
[CCF_NODEID2](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-nodeid2).

## See also

[CCF_NODEID2](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-nodeid2)