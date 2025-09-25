# PointF::operator-sub

## Description

The **PointF::operator-** method subtracts the **X** and **Y** data members of two [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) objects.

## Parameters

### `point` [in, ref]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)**

Reference to a [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) object whose **X** and **Y** data members are subtracted from the **X** and **Y** data members of this **PointF** object.

## Return value

Type: **[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)**

This method returns a [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) object that is the difference of two **PointF** objects.

## Remarks

This method overloads the subtraction operator for [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) objects. If A, B, and C are **PointF** objects, the statement **C = A - B** is equivalent to **C = A.operator-(B)**.

#### Examples

The following example creates two [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) objects, then subtracts the second **PointF** object from the first **PointF** object and stores the result in a third **PointF** object.

```cpp
PointF point1(40.0f, 10.0f);
PointF point2(-20.0f, -30.0f);

// Point3 now contains the coordinates (60.0f, 40.0f).
PointF point3 = point1 - point2;
```

## See also

[Equals](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nf-gdiplustypes-point-equals)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)

[operator+](https://learn.microsoft.com/previous-versions/ms535008(v=vs.85))