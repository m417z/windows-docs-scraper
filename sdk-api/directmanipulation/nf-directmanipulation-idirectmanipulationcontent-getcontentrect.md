# IDirectManipulationContent::GetContentRect

## Description

Retrieves the bounding rectangle of the content, relative to the bounding rectangle of the viewport (if defined).

## Parameters

### `contentSize` [out]

The bounding rectangle of the content.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the bounding rectangle has not been set using [SetContentRect](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationcontent-setcontentrect), then [UI_E_VALUE_NOT_SET](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) is returned. However, the actual content rectangle is (-[FLT_MAX](https://learn.microsoft.com/previous-versions/ms858507(v=msdn.10)), -[FLT_MAX](https://learn.microsoft.com/previous-versions/ms858507(v=msdn.10)), [FLT_MAX](https://learn.microsoft.com/previous-versions/ms858507(v=msdn.10)), [FLT_MAX](https://learn.microsoft.com/previous-versions/ms858507(v=msdn.10))).

## See also

[IDirectManipulationContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcontent)