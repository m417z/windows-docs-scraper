# ITuningSpaceContainer::get_EnumTuningSpaces

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_EnumTuningSpaces** method retrieves a collection of all tuning spaces available on the local system.

## Parameters

### `ppEnum` [out]

Pointer to a variable that receives an [IEnumTuningSpaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ienumtuningspaces) interface pointer. Use this interface to enumerate the collection. The caller must release the interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

C++ applications use this method to get the initial list of tuning spaces defined on the local system.

## See also

[ITuningSpaceContainer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspacecontainer)