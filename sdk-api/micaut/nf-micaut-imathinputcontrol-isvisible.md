# IMathInputControl::IsVisible

## Description

Determines whether the control is visible.

## Parameters

### `pvbShown` [out]

**VARIANT_TRUE** to show the control; **VARIANT_FALSE** to hide the control.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | The *pvbShown* parameter is **NULL**. |

## See also

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)