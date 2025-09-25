# ID2D1SimplifiedGeometrySink::Close

## Description

Closes the geometry sink, indicates whether it is in an error state, and resets the sink's error state.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

Do not close the geometry sink while a figure is still in progress; doing so puts the geometry sink in an error state. For the close operation to be successful, there must be one [EndFigure](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-endfigure) call for each call to [BeginFigure](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-beginfigure).

After calling this method, the geometry sink might not be usable. Direct2D implementations of this interface do not allow the geometry sink to be modified after it is closed, but other implementations might not impose this restriction.

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