# SizeF::operator-add

## Description

The **SizeF::operator+** method adds the **Width** and **Height** data members of two [SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef) objects.

## Parameters

### `sz` [in, ref]

Type: **const [SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef)**

Reference to a [SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef) object whose **Width** and **Height** data members are added to the **Width** and **Height** data members of this **SizeF** object.

## Return value

Type: **[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef)**

This method returns the sum of this [SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef) object and another **SizeF** object.

## Remarks

This method overloads the addition operator for
[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef) objects. If A, B, and C are
**SizeF** objects, the statement **C = A + B** is equivalent to **C = A.operator+(B)**.

#### Examples

```cpp
VOID Example_OperatorPlus(HDC hdc)
{

   Graphics graphics(hdc);
   Pen pen(Color(255, 0, 0, 0));

   SizeF size1(80.0f, 30.0f);
   SizeF size2(50.0f, 20.0f);

   SizeF size3 = size1 + size2;

   graphics.DrawRectangle(&pen, 50.0f, 50.0f, size1.Width, size1.Height);
   graphics.DrawRectangle(&pen, 50.0f, 50.0f, size2.Width, size2.Height);
   graphics.DrawRectangle(&pen, 50.0f, 50.0f, size3.Width, size3.Height);

}
```

## See also

[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size)

[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef)

[SizeF::operator-](https://learn.microsoft.com/previous-versions/ms534743(v=vs.85))