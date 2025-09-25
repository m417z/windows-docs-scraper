# IDirectManipulationPrimaryContent::GetInertiaEndTransform

## Description

Gets the final transform, including inertia, of the primary content.

## Parameters

### `matrix` [out]

The transformed matrix that represents the inertia ending position.

### `pointCount` [in]

The size of the matrix.

 This value is always 6, because a 3x2 matrix is used for all direct manipulation transforms.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Warning** Calling this method can cause a race condition if inertia has ended or been interrupted. This can also occur during the [OnViewportStatusChanged](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewporteventhandler-onviewportstatuschanged) callback.

## See also

[IDirectManipulationPrimaryContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationprimarycontent)