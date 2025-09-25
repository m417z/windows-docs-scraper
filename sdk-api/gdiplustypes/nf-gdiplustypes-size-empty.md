# Size::Empty

## Description

The **Size::Empty** method determines whether a
[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size) object is empty.

## Return value

Type: **BOOL**

If the
**Width** and
**Height** data members are both equal to zero, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

A
[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size) object is defined as empty if the
**Width** and
**Height** data members are both equal to zero.

#### Examples

```cpp
Rect rect(50, 50, 100, 200);
Size size;

rect.Inflate(-50, -100);
rect.GetSize(&size);

if(size.Empty())
{
   // The width and height are both 0.
}
```

## See also

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size)

[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef)