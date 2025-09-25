# IDirectManipulationContent::GetOutputTransform

## Description

Gets the final transform applied to the content.

## Parameters

### `matrix` [out]

The transform matrix.

### `pointCount` [in]

The size of the transform matrix. This value is always 6, because a 3x2 matrix is used for all direct manipulation transforms.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This transform might contain the other custom curves applied during manipulation and inertia.

This transform contains both the content transform and the sync transform set with [SyncContentTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationcontent-synccontenttransform).

## See also

[IDirectManipulationContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcontent)