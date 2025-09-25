# IOleUIObjInfoW::SetViewInfo

## Description

Sets the view information associated with the object.

## Parameters

### `dwObject` [in]

Unique identifier for the object.

### `hMetaPict` [in]

The new icon.

### `dvAspect` [in]

The new display aspect or view.

### `nCurrentScale` [in]

The new scale.

### `bRelativeToOrig` [in]

The new scale of the object, relative to the origin. This value is **TRUE** if the scale should be relative to the original scale of the object. If **FALSE**, *nCurrentScale* applies to the object's current size.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Insufficient access permissions. |
| **E_FAIL** | The operation failed. |
| **E_INVALIDARG** | The specified identifier is invalid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

### Notes to Implementers

You should apply the new attributes (icon, aspect, and scale) to the object. If *bRelativeToOrig* is set to **TRUE**, *nCurrentScale* (in percentage units) applies to the original size of the object before it was scaled. If *bRelativeToOrig* is **FALSE**, *nCurrentScale* applies to the object's current size.

## See also

[DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)

[IOleUIObjInfo](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuiobjinfoa)