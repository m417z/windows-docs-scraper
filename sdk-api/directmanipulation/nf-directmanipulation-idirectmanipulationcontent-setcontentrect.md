# IDirectManipulationContent::SetContentRect

## Description

Specifies the bounding rectangle of the content, relative to its viewport.

## Parameters

### `contentSize` [in]

The bounding rectangle of the content.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default bounding rectangle is (-[FLT_MAX](https://learn.microsoft.com/previous-versions/ms858507(v=msdn.10)), -[FLT_MAX](https://learn.microsoft.com/previous-versions/ms858507(v=msdn.10)), [FLT_MAX](https://learn.microsoft.com/previous-versions/ms858507(v=msdn.10)), [FLT_MAX](https://learn.microsoft.com/previous-versions/ms858507(v=msdn.10))).

## See also

[IDirectManipulationContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcontent)