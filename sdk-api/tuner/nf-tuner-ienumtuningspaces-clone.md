# IEnumTuningSpaces::Clone

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Clone** method creates a new copy of the collection and all its sub-objects.

## Parameters

### `ppEnum` [out]

Address of an [IEnumTuningSpaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ienumtuningspaces) interface pointer that will receive the returned interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IEnumTuningSpaces Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ienumtuningspaces)