# ID2D1SolidColorBrush::SetColor(const D2D1_COLOR_F &)

## Description

Specifies the color of this solid-color brush.

## Parameters

### `color` [ref]

Type: **const [D2D1_COLOR_F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-color-f)**

The color of this solid-color brush.

## Remarks

To help create colors, Direct2D provides the [ColorF](https://learn.microsoft.com/windows/win32/api/d2d1helper/nl-d2d1helper-colorf) class. It offers several helper methods for creating colors and provides a set or predefined colors.

## Examples

The following code shows how to use this method.

```cpp
        m_pSolidColorBrush->SetColor(
            D2D1::ColorF(
                0.0f,
                intensity,
                1.0f - intensity
                ));

        hr = m_pRealization->Fill(
                m_pRT,
                m_pSolidColorBrush,
                m_useRealizations ?
                    REALIZATION_RENDER_MODE_DEFAULT :
                    REALIZATION_RENDER_MODE_FORCE_UNREALIZED
                );

```

## See also

[ID2D1SolidColorBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1solidcolorbrush)