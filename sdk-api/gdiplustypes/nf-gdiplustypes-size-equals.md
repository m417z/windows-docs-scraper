# Size::Equals

## Description

The **Size::Equals** method determines whether two
[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size) objects are equal.

## Parameters

### `sz` [in, ref]

Type: **const [Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size)**

Reference to a
[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size) object that is compared to this
**Size** object.

## Return value

Type: **BOOL**

If the
**Width** and
**Height** data members of the two
[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size) objects are equal, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

Two
[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size) objects are defined as equal if the
**Width** and
**Height** data members are equal.

#### Examples

The following example creates a
[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) object, gets the size of the rectangle, and determines whether the rectangles are equal.

```cpp
Rect rect(50, 30, 200, 100);
Size desiredSize(200, 100);
Size rectSize;

// Get the size of the rectangle.
rect.GetSize(&rectSize);

if(rectSize.Equals(desiredSize))
{
   // The rectangle has the desired size.
}
```

## See also

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size)

[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef)