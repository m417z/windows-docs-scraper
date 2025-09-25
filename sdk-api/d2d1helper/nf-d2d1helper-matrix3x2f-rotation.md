# Matrix3x2F::Rotation

## Description

Creates a rotation transformation that has the specified angle and center point.

## Parameters

### `angle`

Type: **FLOAT**

The rotation angle in degrees. A positive angle creates a clockwise rotation, and a negative angle creates a counterclockwise rotation.

### `center`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-point-2f)**

The point about which the rotation is performed.

## Return value

Type: **[Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f)**

The new rotation transformation.

## Remarks

When calling this method, specify a *centerPoint* to rotate the object about, and the rotation *angle* in degrees. The following illustration shows a square rotated 45 degrees about its center point.

![Illustration a square rotated clockwise 45 degrees about the center of the original square](https://learn.microsoft.com/windows/win32/api/d2d1helper/images/rotate_ovw.PNG)

#### Examples

The following example uses the **D2D1::Matrix3x2F::Rotation** method to create a rotation matrix that rotates a square clockwise 45 degrees about the center of the square and passes the matrix to the [SetTransform](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-settransform(constd2d1_matrix_3x2_f_)) method of the render target (*m_pRenderTarget*).

The following illustration shows the effect of applying the preceding rotation transformation to the square. The original square is a dotted outline, and the rotated square is a solid outline.

![Illustration a square rotated 45 degrees about the center of the original square](https://learn.microsoft.com/windows/win32/api/d2d1helper/images/rotate_ovw.png)

```cpp
    // Create a rectangle.
    D2D1_RECT_F rectangle = D2D1::Rect(438.0f, 301.5f, 498.0f, 361.5f);

    // Draw the rectangle.
    m_pRenderTarget->DrawRectangle(
        rectangle,
        m_pOriginalShapeBrush,
        1.0f,
        m_pStrokeStyleDash
        );

    // Apply the rotation transform to the render target.
    m_pRenderTarget->SetTransform(
        D2D1::Matrix3x2F::Rotation(
            45.0f,
            D2D1::Point2F(468.0f, 331.5f))
        );

    // Fill the rectangle.
    m_pRenderTarget->FillRectangle(rectangle, m_pFillBrush);

    // Draw the transformed rectangle.
    m_pRenderTarget->DrawRectangle(rectangle, m_pTransformedShapeBrush);

```

Code has been omitted from this example. For more information about transforms, see the [Transforms Overview](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-transforms-overview).

## See also

[Matrix3x2F](https://learn.microsoft.com/windows/desktop/api/d2d1helper/nl-d2d1helper-matrix3x2f)