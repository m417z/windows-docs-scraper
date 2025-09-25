# ICoreFragmentInspector::NextCoreFragments

## Description

Returns the next **ICoreFragment** objects in the knowledge, if they are available.

## Parameters

### `requestedCount` [in]

The number of **ICoreFragment** objects to retrieve.

### `ppiCoreFragments` [out]

Receives a pointer to the next *pFetchedCount* **ICoreFragment** objects. The size of the array is the value specified in the *requestedCount* parameter. The length is `*(pFetchedCount)`. The caller must release the interface pointer.

### `pFetchedCount` [in, out]

Receives the number of **ICoreFragment** objects that were retrieved in the *ppiCoreFragments* parameter. This value can be **NULL** only if  *requestedCount* is 1.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | There are no more **ICoreFragment** objects to retrieve, or the number of **ICoreFragment** objects retrieved is less than *requestedCount*. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_INVALID_OPERATION** | The knowledge object contained in this object has changed since this object was created. |

## See also

[ICoreFragmentInspector Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-icorefragmentinspector)