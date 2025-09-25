# IAppxManifestResourcesEnumerator::GetHasCurrent

## Description

Determines whether there is a resource at the current position of the enumerator.

## Parameters

### `hasCurrent` [out, retval]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

**TRUE** if the enumerator's current position references an item; **FALSE** if the enumerator has passed the last item in the collection.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxManifestResourcesEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestresourcesenumerator)