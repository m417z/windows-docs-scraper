# ID2D1SimplifiedGeometrySink::EndFigure

## Description

Ends the current figure; optionally, closes it.

## Parameters

### `figureEnd`

Type: **[D2D1_FIGURE_END](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_figure_end)**

A value that indicates whether the current figure is closed. If the figure is closed, a line is drawn between the current point and the start point specified by [BeginFigure](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-beginfigure).

## Remarks

Calling this method without a matching call to [BeginFigure](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-beginfigure) places the geometry sink in an error state; subsequent calls are ignored, and the overall failure will be returned when the [Close](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-close) method is called.

## Examples

The following example creates an [ID2D1PathGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1pathgeometry), retrieves a sink, uses it to define an hourglass shape, and then calls **EndFigure** with the D2D1_FIGURE_END_CLOSED value to end the creation of the hourglass. For the complete example, see [How to Draw and Fill a Complex Shape](https://learn.microsoft.com/windows/win32/Direct2D/how-to-draw-and-fill-a-complex-shape).

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