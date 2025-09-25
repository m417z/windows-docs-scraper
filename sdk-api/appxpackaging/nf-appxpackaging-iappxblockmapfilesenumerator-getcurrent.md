# IAppxBlockMapFilesEnumerator::GetCurrent

## Description

Gets the file at the current position of the enumerator.

## Parameters

### `file` [out, retval]

Type: **[IAppxBlockMapFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapfile)****

The current file.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_BOUNDS** | The enumerator has passed the last item in the collection. |

## Remarks

The enumerator returned can be empty. In this case, a call to [GetHasCurrent](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxblockmapfilesenumerator-gethascurrent) returns **false**. If the enumerator is not empty, it points to the first element, and this method returns the first item. Subsequently, the user should use [MoveNext](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxblockmapfilesenumerator-movenext) to move through the items, and call **GetHasCurrent** before using **GetCurrent** to access the item.

## See also

[IAppxBlockMapFilesEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapfilesenumerator)