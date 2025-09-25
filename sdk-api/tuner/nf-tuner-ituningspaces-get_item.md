# ITuningSpaces::get_Item

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Item** method returns the specified item in the collection.

## Parameters

### `varIndex` [in]

**VARIANT** type that specifies the ID of the tuning space. The ID uniquely identifies the tuning space within the **SystemTuningSpaces** object.

### `TuningSpace` [out]

Address of a variable that receives a pointer to the tuning space's [ITuningSpace](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace) interface. The caller must release the interface.

## Return value

Returns S_OK if successful.

## See also

[ITuningSpaces Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspaces)