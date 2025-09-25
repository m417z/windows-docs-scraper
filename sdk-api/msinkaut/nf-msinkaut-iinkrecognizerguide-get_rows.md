# IInkRecognizerGuide::get_Rows

## Description

Gets or sets the number of rows in the recognition guide.

This property is read/write.

## Parameters

## Remarks

Row height is determined by the size of the drawn box. To get or set the drawn box, use the [DrawnBox](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_drawnbox) property.

Use the values of the [Columns](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_columns) and **Rows** properties to control the kind of recognition input that you use. When the **Columns** and **Rows** properties are both greater than zero, boxed input is used. The following table lists potential input modes and which values to set the **Columns** and **Rows** properties for each mode.

| For this type of input | Set Rows equal to | Set Columns equal to |
| --- | --- | --- |
| Free input | 0 | 0 |
| Vertical Lined input with 1 line | 0 | 1 |
| Vertical Lined input with n lines | 0 | n |
| Horizontal Lined input with 1 line | 1 | 0 |
| Horizontal Lined input with n lines | n | 0 |
| Boxed input with 1 box | 1 | 1 |
| Boxed input in a horizontal line with n boxes | n | 1 |
| Boxed input in a grid of boxes x rows by y columns | x | z |

## See also

[Columns Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_columns)

[IInkRecognizerGuide](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizerguide)

[InkRecognizerGuide Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizerguide-class)