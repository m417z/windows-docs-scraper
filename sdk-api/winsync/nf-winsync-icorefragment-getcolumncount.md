# ICoreFragment::GetColumnCount

## Description

Gets the number of columns that are contained in this knowledge fragment.

## Parameters

### `pColumnCount` [out]

Returns the number of columns that are contained in this knowledge fragment.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

An **ISyncKnowledge2** object contains one or more **ICoreFragment** objects. Each object contains knowledge that applies to a specific set of columns. A column is represented as a change unit. Typically, one of the **ICoreFragment** objects contains no columns. When an **ICoreFragment** object contains no columns, its knowledge applies to all of the change units that are not specified in any other fragment.

## See also

[ICoreFragment Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-icorefragment)