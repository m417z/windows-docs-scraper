# IDirectManipulationCompositor::RemoveContent

## Description

Removes content from the compositor.

## Parameters

### `content` [in]

The content to remove from the composition tree.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method removes content added with [AddContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationcompositor-addcontent) and restores the original relationships between parent visuals and child visuals in the composition tree. In other words, **RemoveContent** undoes **AddContent**.

## See also

[IDirectManipulationCompositor](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcompositor)