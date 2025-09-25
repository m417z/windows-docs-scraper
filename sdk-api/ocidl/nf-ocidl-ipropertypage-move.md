# IPropertyPage::Move

## Description

Positions and resizes the property page dialog box within the frame.

## Parameters

### `pRect` [in]

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the positioning information for the property page dialog box.

## Return value

This method can return the standard return value E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | The address in *prc* is not valid. For example, it may be **NULL**. |

## Remarks

The rectangle specified by *prc* is treated identically to that passed to [IPropertyPage::Activate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-activate).

### Notes to Callers

Calls to this method must occur after a call to [IPropertyPage::Activate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-activate) and before a corresponding call to [IPropertyPage::Deactivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-deactivate).

### Notes to Implementers

The page must create its dialog box with the placement and dimensions described by this structure.

## See also

[IPropertyPage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage)