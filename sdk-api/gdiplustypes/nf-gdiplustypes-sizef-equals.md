# SizeF::Equals

## Description

The **SizeF::Equals** method determines whether two
[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef) objects are equal.

## Parameters

### `sz` [in, ref]

Type: **const [SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef)**

Reference to a
[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef) object that is compared to this
**SizeF** object.

## Return value

Type: **BOOL**

If the
**Width** and
**Height** data members of the two
[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef) objects are equal, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

Two
[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef) objects are defined as equal if the
**Width** and
**Height** data members are equal.

#### Examples

```cpp
RectF rect(50.0f, 30.0f, 200.0f, 100.0f);
SizeF desiredSizeF(200.0f, 100.0f);
SizeF rectSizeF;

// Get the size of the rectangle.
rect.GetSize(&rectSizeF);

if(rectSizeF.Equals(desiredSizeF))
{
   // The rectangle has the wanted size.
}
```

## See also

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Size Constructors](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-class-size-constructors)

[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef)