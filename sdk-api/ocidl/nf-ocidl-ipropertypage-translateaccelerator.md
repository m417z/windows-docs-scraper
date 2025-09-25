# IPropertyPage::TranslateAccelerator

## Description

Passes a keystroke to the property page for processing.

## Parameters

### `pMsg` [in]

A pointer to the [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure describing the keystroke to be processed.

## Return value

This method can return the standard return value E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The property page handles the accelerator. |
| **S_FALSE** | The property page handles accelerators, but this one was not useful to it. |
| **E_NOTIMPL** | The property page does not handle accelerators. |
| **E_POINTER** | The address in *pMsg* is not valid. For example, it may be **NULL**. |

## Remarks

### Notes to Callers

Calls to this method must occur after a call to [IPropertyPage::Activate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-activate) and before the corresponding call to [IPropertyPage::Deactivate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-deactivate).

## See also

[IPropertyPage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage)