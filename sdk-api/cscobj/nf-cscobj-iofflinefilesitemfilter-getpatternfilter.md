# IOfflineFilesItemFilter::GetPatternFilter

## Description

Provides a filter pattern string to limit enumerated items based on item name patterns. Note that pattern filtering is available only for inclusion filters. If you provide a pattern filter as an exclusion filter, it is ignored.

## Parameters

### `pszPattern` [out]

Receives the filter pattern string. Pattern strings can contain the * and ? wildcard characters.

Examples:

* *.DOC
* ABC.*
* AB?.??2

### `cchPattern` [in]

Specifies the maximum length in characters of the buffer receiving the pattern string. This value is currently **MAX_PATH**.

## Return value

Returns **S_OK** if the filter supports pattern filtering and the filter string is successfully copied to the pszPattern buffer.

Returns **E_NOTIMPL** if pattern filtering is not supported.

Any other error value causes the creation of the enumerator to fail.

## Remarks

While this method can be implemented in any filter type (inclusion, exclusion) or filter target (file, container), it is called only for inclusion filters and file targets. This method will never be called for any other filter type/target combination.

## See also

[IOfflineFilesItemFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitemfilter)