# ID2D1PathGeometry::Open

## Description

Retrieves the geometry sink that is used to populate the path geometry with figures and segments.

## Parameters

### `geometrySink` [out]

Type: **[ID2D1GeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometrysink)****

When this method returns, *geometrySink* contains the address of a pointer to the geometry sink that is used to populate the path geometry with figures and segments. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

Because path geometries are immutable and can only be populated once, it is an error to call **Open** on a path geometry more than once.

Note that the fill mode defaults to [D2D1_FILL_MODE_ALTERNATE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_fill_mode). To set the fill mode, call [SetFillMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-setfillmode) before the first call to [BeginFigure](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-beginfigure). Failure to do so will put the geometry sink in an error state.

## Examples

The following example creates an [ID2D1PathGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1pathgeometry), retrieves a sink, and uses the sink to define an hourglass shape. For the complete example, see [How to Draw and Fill a Complex Shape](https://learn.microsoft.com/windows/win32/Direct2D/how-to-draw-and-fill-a-complex-shape).

```cpp
ID2D1GeometrySink *pSink = NULL;

```

```cpp
// Create a path geometry.
if (SUCCEEDED(hr))
{
    hr = m_pD2DFactory->CreatePathGeometry(&m_pPathGeometry);

    if (SUCCEEDED(hr))
    {
        // Write to the path geometry using the geometry sink.
        hr = m_pPathGeometry->Open(&pSink);

        if (SUCCEEDED(hr))
        {
            pSink->BeginFigure(
                D2D1::Point2F(0, 0),
                D2D1_FIGURE_BEGIN_FILLED
                );

            pSink->AddLine(D2D1::Point2F(200, 0));

            pSink->AddBezier(
                D2D1::BezierSegment(
                    D2D1::Point2F(150, 50),
                    D2D1::Point2F(150, 150),
                    D2D1::Point2F(200, 200))
                );

            pSink->AddLine(D2D1::Point2F(0, 200));

            pSink->AddBezier(
                D2D1::BezierSegment(
                    D2D1::Point2F(50, 150),
                    D2D1::Point2F(50, 50),
                    D2D1::Point2F(0, 0))
                );

            pSink->EndFigure(D2D1_FIGURE_END_CLOSED);

            hr = pSink->Close();
        }
        SafeRelease(&pSink);
    }
}

```

## See also

[ID2D1PathGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1pathgeometry)