# IAppxContentGroupFilesEnumerator::MoveNext

## Description

Advances the position of the enumerator to the next file.

## Parameters

### `hasNext` [out, retval]

**TRUE** if the enumerator successfully advances

**FALSE** if the enumerator has passed the end of the collection.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code.

**Note** When the enumerator passes the end of the collection for the first time, *hasNext* = **FALSE**, but the method succeeds and returns **S_OK**. However, the method returns **E_BOUNDS** if you subsequently call another MoveNext after you have already passed the end of the collection, and you have previously received *hasNext* = **FALSE**.

## See also

[IAppxContentGroupFilesEnumerator](https://learn.microsoft.com/windows/win32/api/appxpackaging/nn-appxpackaging-iappxcontentgroupfilesenumerator)