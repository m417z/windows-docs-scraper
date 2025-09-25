# D2D1_DASH_STYLE enumeration

## Description

Describes the sequence of dashes and gaps in a stroke.

## Constants

### `D2D1_DASH_STYLE_SOLID:0`

A solid line with no breaks.

### `D2D1_DASH_STYLE_DASH:1`

A dash followed by a gap of equal length. The dash and the gap are each twice as long as the stroke thickness.

The equivalent dash array for **D2D1_DASH_STYLE_DASH** is {2, 2}.

### `D2D1_DASH_STYLE_DOT:2`

A dot followed by a longer gap.

The equivalent dash array for **D2D1_DASH_STYLE_DOT** is {0, 2}.

### `D2D1_DASH_STYLE_DASH_DOT:3`

A dash, followed by a gap, followed by a dot, followed by another gap.

The equivalent dash array for **D2D1_DASH_STYLE_DASH_DOT** is {2, 2, 0, 2}.

### `D2D1_DASH_STYLE_DASH_DOT_DOT:4`

A dash, followed by a gap, followed by a dot, followed by another gap, followed by another dot, followed by another gap.

The equivalent dash array for **D2D1_DASH_STYLE_DASH_DOT_DOT** is {2, 2, 0, 2, 0, 2}.

### `D2D1_DASH_STYLE_CUSTOM:5`

The dash pattern is specified by an array of floating-point values.

### `D2D1_DASH_STYLE_FORCE_DWORD:0xffffffff`

## Remarks

The following illustration shows several available dash styles.

![Illustration of available dash styles](https://learn.microsoft.com/windows/win32/api/d2d1/images/StrokeStyle_DashStyle.png)

## Examples

The following example creates a stroke that uses a custom dash pattern.

```cpp
// Dash array for dashStyle D2D1_DASH_STYLE_CUSTOM
float dashes[] = {1.0f, 2.0f, 2.0f, 3.0f, 2.0f, 2.0f};

// Stroke Style with Dash Style -- Custom
if (SUCCEEDED(hr))
{
    hr = m_pD2DFactory->CreateStrokeStyle(
        D2D1::StrokeStyleProperties(
            D2D1_CAP_STYLE_FLAT,
            D2D1_CAP_STYLE_FLAT,
            D2D1_CAP_STYLE_ROUND,
            D2D1_LINE_JOIN_MITER,
            10.0f,
            D2D1_DASH_STYLE_CUSTOM,
            0.0f),
        dashes,
        ARRAYSIZE(dashes),
        &m_pStrokeStyleCustomOffsetZero
        );
}

```

The next example uses the stroke style when drawing a line.

```cpp
m_pRenderTarget->DrawLine(
    D2D1::Point2F(0, 310),
    D2D1::Point2F(200, 310),
    m_pCornflowerBlueBrush,
    10.0f,
    m_pStrokeStyleCustomOffsetZero
    );

```