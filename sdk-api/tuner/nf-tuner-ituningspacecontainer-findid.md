# ITuningSpaceContainer::FindID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **FindID** method retrieves the ID of a specified tuning space within the collection.

## Parameters

### `TuningSpace` [in]

Pointer to the **ITuningSpace** interface of the tuning space.

### `ID` [out]

Pointer to a variable that receives the ID of the tuning space. The returned value is specific to this collection object (which represents the local system).

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The specified tuning space is not a member of this collection. |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | Success. |

## See also

[ITuningSpaceContainer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspacecontainer)