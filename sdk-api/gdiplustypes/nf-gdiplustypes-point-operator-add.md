# Point::operator-add

## Description

The **Point::operator+** method adds the **X** and **Y** data members of two [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) objects.

## Parameters

### `point` [in, ref]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)**

Reference to a [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) object whose **X** and **Y** data members are added to the **X** and **Y** data members of this **Point** object.

## Return value

Type: **[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)**

This method returns a [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) object that is the sum of two **Point** objects.

## Remarks

This method overloads the addition operator for [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) objects. If A, B, and C are **Point** objects, the statement **C = A + B** is equivalent to **C = A.operator+(B)**.

#### Examples

The following example creates two [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) objects, then adds the two **Point** objects and stores the result in a third **Point** object.

```cpp
Point point1(40, 10);
Point point2(20, 30);

// Point 3 now contains the coordinates (60, 40).
Point point3 = point1 + point2;
```

## See also

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Point::Equals](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nf-gdiplustypes-point-equals)

[Point::operator-](https://learn.microsoft.com/previous-versions/ms535009(v=vs.85))

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)