# IOleUIObjInfoW::GetViewInfo

## Description

Gets the view information associated with the object.

## Parameters

### `dwObject` [in]

Unique identifier for the object.

### `phMetaPict` [in, optional]

Pointer to the object's current icon. This parameter can be **NULL**, indicating that the caller is not interested in the object's current presentation.

### `pdvAspect` [in, optional]

Pointer to the object's current aspect. This parameter can be **NULL**, indicating that the caller is not interested in the object's current aspect, for example, DVASPECT_ICONIC or DVASPECT_CONTENT.

### `pnCurrentScale` [in, optional]

Pointer to the object's current scale. This parameter can be **NULL**, indicating that the caller is not interested in the current scaling factor applied to the object in the container's view.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Insufficient access permissions. |
| **E_FAIL** | The operation failed. |
| **E_INVALIDARG** | The specified identifier is not valid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

### Notes to Implementers

You must fill in the object's current icon, aspect, and scale.

## See also

[IOleUIObjInfo](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuiobjinfoa)

[OLEUIVIEWPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiviewpropsa)