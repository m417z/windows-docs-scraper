# ID2D1DeviceContext1::DrawGeometryRealization

## Description

Renders a given geometry realization to the target with the specified brush.

## Parameters

### `geometryRealization` [in]

Type: **[ID2D1GeometryRealization](https://learn.microsoft.com/windows/desktop/api/d2d1_2/nn-d2d1_2-id2d1geometryrealization)***

The geometry realization to be rendered.

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush to render the realization with.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## Remarks

This method respects all currently set state (transform, DPI, unit mode, target image, clips, layers);
however, artifacts such as faceting may appear when rendering the realizations with a large effective scale (either via the transform or the DPI).
Callers should create their realizations with an appropriate flattening tolerance using either [D2D1_DEFAULT_FLATTENING_TOLERANCE](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-constants)
or [ComputeFlatteningTolerance](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn280327(v=vs.85)) to compensate for this.

Additionally, callers should be aware of the safe render bounds when creating geometry realizations.
If a geometry extends outside of [-524,287, 524,287] DIPs in either the X- or the Y- direction in its original (pre-transform) coordinate space,
then it may be clipped to those bounds when it is realized. This clipping will be visible even if the realization is subsequently transformed to fit within the safe render bounds.

## See also

[ID2D1DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d2d1_2/nn-d2d1_2-id2d1devicecontext1)