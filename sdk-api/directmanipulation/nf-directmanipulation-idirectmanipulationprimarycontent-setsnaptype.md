# IDirectManipulationPrimaryContent::SetSnapType

## Description

Specifies the type of snap point.

## Parameters

### `motion` [in]

One or more of the [DIRECTMANIPULATION_MOTION_TYPES](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_motion_types) enumeration values.

### `type` [in]

One of the [DIRECTMANIPULATION_SNAPPOINT_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_snappoint_type) enumeration values.

If set to **DIRECTMANIPULATION_SNAPPOINT_TYPE_NONE**, snap points specified through [SetSnapPoints](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnappoints) or [SetSnapInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnapinterval) are cleared.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDirectManipulationPrimaryContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationprimarycontent)