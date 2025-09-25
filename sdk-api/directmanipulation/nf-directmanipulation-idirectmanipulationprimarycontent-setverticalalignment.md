# IDirectManipulationPrimaryContent::SetVerticalAlignment

## Description

Specifies the vertical alignment of the primary content in the viewport.

## Parameters

### `alignment` [in]

One or more values from [DIRECTMANIPULATION_VERTICALALIGNMENT](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_verticalalignment).

**Note** You cannot combine **DIRECTMANIPULATION_VERTICALALIGNMENT_TOP**, **DIRECTMANIPULATION_VERTICALALIGNMENT_CENTER**, or **DIRECTMANIPULATION_VERTICALALIGNMENT_BOTTOM**. **DIRECTMANIPULATION_VERTICALALIGNMENT_UNLOCKCENTER** can be combined with any option but cannot be configured by itself.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you have activated a configuration consisting only of zoom or zoom inertia, specify **DIRECTMANIPULATION_VERTICALALIGNMENT_UNLOCKCENTER** to respect the zoom center point.

#### Examples

The following example shows how to use this method.

```
HRESULT hr = pContent->SetVerticalAlignment(
    DIRECTMANIPULATION_VERTICALALIGNMENT_CENTER| DIRECTMANIPULATION_VERTICALALIGNMENT_UNLOCKCENTER);
```

## See also

[IDirectManipulationPrimaryContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationprimarycontent)