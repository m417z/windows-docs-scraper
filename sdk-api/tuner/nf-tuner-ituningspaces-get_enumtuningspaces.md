# ITuningSpaces::get_EnumTuningSpaces

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_EnumTuningSpaces** method returns an enumerator for the collection.

## Parameters

### `NewEnum` [out]

Pointer to a variable that receives an [IEnumTuningSpaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ienumtuningspaces) interface pointer. Use this interface to iterate through the collection. The caller must release the interface.

## Return value

Returns S_OK if successful.

## See also

[ITuningSpaces Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspaces)