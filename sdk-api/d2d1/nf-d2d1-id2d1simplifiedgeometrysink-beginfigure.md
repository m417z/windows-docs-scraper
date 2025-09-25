# ID2D1SimplifiedGeometrySink::BeginFigure

## Description

Starts a new figure at the specified point.

## Parameters

### `startPoint`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The point at which to begin the new figure.

### `figureBegin`

Type: **[D2D1_FIGURE_BEGIN](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_figure_begin)**

Whether the new figure should be hollow or filled.

## Remarks

If this method is called while a figure is currently in progress, the interface is invalidated and all future methods will fail.

## Examples

The following example creates an [ID2D1PathGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1pathgeometry), retrieves a sink, and uses it to define an hourglass shape.

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

[ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink)

[Path Geometries Overview](https://learn.microsoft.com/windows/win32/Direct2D/path-geometries-overview)