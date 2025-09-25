# ICoreFragment::NextColumn

## Description

Returns the next change unit ID in the set of change unit IDs that this knowledge fragment applies to.

## Parameters

### `pChangeUnitId` [in, out]

Returns the next change unit ID in the set.

### `pChangeUnitIdSize` [in, out]

Specifies the number of bytes in *pChangeUnitId*. Returns the number of bytes written, or the number of bytes that are required to retrieve the ID when *pChangeUnitId* is too small.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | There are no more change unit IDs to enumerate. |
| **E_POINTER** | The change unit ID is a variable-length ID and *pChangeUnitIdSize* is **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)** | *pChangeUnitId* is too small. In this situation, the required number of bytes is returned in *pChangeUnitIdSize*. |
| **SYNC_E_INVALID_OPERATION** | The knowledge object contained within this object has changed since this object was created. |

## Remarks

An **ISyncKnowledge2** object contains one or more **ICoreFragment** objects, each of which contains knowledge that applies to a specific set of columns. Typically, one of the **ICoreFragment** objects contains no columns, and its knowledge applies to all of the change units that are not specified in any other fragment. In this situation, **NextColumn** always returns **S_FALSE**.

## See also

[ICoreFragment Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-icorefragment)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)