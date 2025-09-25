# ITuner::EnumTuningSpaces

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **EnumTuningSpaces** method creates a collection of tuning spaces preferred by this implementation.

## Parameters

### `ppEnum` [out]

Address of a [IEnumTuningSpaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ienumtuningspaces) interface pointer that will be set to the returned collection.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This list is a subset of the compatible tuning spaces for this implementation.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ITuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituner)