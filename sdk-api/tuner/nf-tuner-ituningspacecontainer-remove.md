# ITuningSpaceContainer::Remove

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Remove** method permanently removes a tuning space from the system.

## Parameters

### `Index` [in]

Variable of type **VARIANT** that specifies the ID of the tuning space to remove.

## Return value

Returns S_OK if successful. If the specified tuning space was invalid or corrupted in the Registry, this method will delete whatever information is there and return S_FALSE.

## See also

[ITuningSpaceContainer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspacecontainer)