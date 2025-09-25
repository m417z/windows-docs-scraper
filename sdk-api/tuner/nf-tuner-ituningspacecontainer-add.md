# ITuningSpaceContainer::Add

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Add** method adds a new persistent tuning space to the system.

## Parameters

### `TuningSpace` [in]

Pointer to the [ITuningSpace](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace) interface of the new tuning space

### `NewIndex` [out]

Pointer to a variable of type **VARIANT** that receives the ID of the new tuning space within the current collection.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This method adds a new tuning space to the collection. The collection object automatically persists the tuning space information.

The tuning space must have a unique name that does not clash with any of the tuning spaces already in the collection. To overwrite an existing tuning space, use the [ITuningSpaceContainer::put_Item](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspacecontainer-put_item) method.

## See also

[ITuningSpaceContainer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspacecontainer)