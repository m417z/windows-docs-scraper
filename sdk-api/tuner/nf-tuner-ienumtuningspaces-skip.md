# IEnumTuningSpaces::Skip

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Skip** method skips the specified element in the collection.

## Parameters

### `celt` [in]

The index of the element to skip.

## Return value

Returns S_OK if successful. This method will succeed even if *celt* is zero. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IEnumTuningSpaces Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ienumtuningspaces)