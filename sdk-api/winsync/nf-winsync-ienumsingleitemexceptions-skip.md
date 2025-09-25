# IEnumSingleItemExceptions::Skip

## Description

Skips the specified number of single-item exceptions.

## Parameters

### `cExceptions` [in]

The number of single-item exceptions to skip.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The enumerator reaches the end of the list before it can skip *cExceptions* single-item exceptions. In this case, the enumerator skips as many elements as possible. |
| **E_OUTOFMEMORY** |  |

## See also

[IEnumSingleItemExceptions Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ienumsingleitemexceptions)