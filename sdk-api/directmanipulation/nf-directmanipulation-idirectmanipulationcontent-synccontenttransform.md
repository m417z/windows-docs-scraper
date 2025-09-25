# IDirectManipulationContent::SyncContentTransform

## Description

Modifies the content transform while maintaining the output transform.

## Parameters

### `matrix` [in]

The transform matrix.

### `pointCount` [in]

The size of the transform matrix. This value is always 6, because a 3x2 matrix is used for all direct manipulation transforms.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method will fail if the viewport state is [DIRECTMANIPULATION_RUNNING](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_status), **DIRECTMANIPULATION_INERTIA** or **DIRECTMANIPULATION_SUSPENDED**.

This method is useful when the application wants to apply transforms on top of the content transforms at the end of a manipulation, while preserving the visual output transform of the content.

## See also

[IDirectManipulationContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcontent)