# Size::operator-add

## Description

The **Size::operator+** method adds the **Width** and **Height** data members of two [Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size) objects.

## Parameters

### `sz` [in, ref]

Type: **const [Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size)**

Reference to a [Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size) object whose **Width** and **Height** data members are added to the **Width** and **Height** data members of this **Size** object.

## Return value

Type: **[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size)**

This method returns the sum of this [Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size) object and another **Size** object.

## Remarks

This method overloads the addition operator for [Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size) objects. If A, B, and C are **Size** objects, the statement **C = A + B** is equivalent to **C = A.operator+(B)**.

#### Examples

```cpp
VOID Example_OperatorPlus(HDC hdc)
{
   Graphics graphics(hdc);
   Pen pen(Color(255, 0, 0, 0));

   Size size1(80, 30);
   Size size2(50, 20);

   Size size3 = size1 + size2;

   graphics.DrawRectangle(&pen, 50, 50, size1.Width, size1.Height);
   graphics.DrawRectangle(&pen, 50, 50, size2.Width, size2.Height);
   graphics.DrawRectangle(&pen, 50, 50, size3.Width, size3.Height);
}
```

## See also

[Size](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-size)

[Size::operator-](https://learn.microsoft.com/previous-versions/ms534752(v=vs.85))

[SizeF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-sizef)