# IAppxFilesEnumerator::GetHasCurrent

## Description

Determines whether there is a payload file at the current position of the enumerator.

## Parameters

### `hasCurrent` [out, retval]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

**TRUE** if the current position references a payload file; **FALSE** if the enumerator has passed the end of the collection.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxFilesEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfilesenumerator)