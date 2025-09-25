# IDirectManipulationPrimaryContent::SetHorizontalAlignment

## Description

Sets the horizontal alignment of the primary content relative to the viewport.

## Parameters

### `alignment` [in]

One or more values from [DIRECTMANIPULATION_HORIZONTALALIGNMENT](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_horizontalalignment). The default is **DIRECTMANIPULATION_HORIZONTALALIGNMENT_NONE**.

**Note** You cannot combine the following options: DIRECTMANIPULATION_HORIZONTALALIGNMENT_LEFT, DIRECTMANIPULATION-HORIZONTALALIGNMENT_CENTER, DIRECTMANIPULATION_HORIZONTALALIGNMENT_RIGHT. DIRECTMANIPULATION_HORIZONTALALIGNMENT_UNLOCKCENTER can be combined with any option but cannot be configured by itself.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you have activated a configuration consisting only of zoom or zoom inertia, specify DIRECTMANIPULATION_HORIZONTALALIGNMENT_UNLOCKCENTER to respect the zoom center point.

#### Examples

The following example shows one way to this method.

```
HRESULT hr = pViewport->SetHorizontalAlignment(
    DIRECTMANIPULATION_HORIZONTALALIGNMENT_CENTER | DIRECTMANIPULATION_HORIZONTALALIGNMENT_UNLOCKCENTER);
```

## See also

[IDirectManipulationPrimaryContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationprimarycontent)