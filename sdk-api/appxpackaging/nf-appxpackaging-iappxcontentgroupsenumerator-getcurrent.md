# IAppxContentGroupsEnumerator::GetCurrent

## Description

Gets the content group at the current position of the enumerator.

## Parameters

### `stream` [out, retval]

The current content group.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_BOUNDS** | The enumerator has passed the last item in the collection. |

## See also

[IAppxContentGroupsEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxcontentgroupsenumerator)