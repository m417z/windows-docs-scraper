# SizeF::Empty

## Description

The **SizeF::Empty** method determines whether a
[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef) object is empty.

## Return value

Type: **BOOL**

If the
**Width** and
**Height** data members are both equal to zero, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

A
[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef) object is defined as empty if the
**Width** and
**Height** data members are both equal to zero.

#### Examples

```cpp
RectF rect(50.0f, 50.0f, 100.0f, 200.0f);
SizeF size;

rect.Inflate(-50.0f, -100.0f);
rect.GetSize(&size);

if(size.Empty())
{

   // The width and height are both 0.
}
```

## See also

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size)

[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef)