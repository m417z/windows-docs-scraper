# AdjustableArrowCap::SetMiddleInset

## Description

The **AdjustableArrowCap::SetMiddleInset** method sets the number of units that the midpoint of the base shifts towards the vertex.

## Parameters

### `middleInset` [in]

Type: **REAL**

Real number that specifies the number of units that the midpoint of the base shifts towards the vertex.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
**Status** enumeration.

## Remarks

The middle inset is the number of units that the midpoint of the base shifts towards the vertex. A middle inset of zero results in no shift — the base is a straight line, giving the arrow a triangular shape. A positive (greater than zero) middle inset results in a shift the specified number of units toward the vertex — the base is an arrow shape that points toward the vertex, giving the arrow cap a V-shape. A negative (less than zero) middle inset results in a shift the specified number of units away from the vertex — the base becomes an arrow shape that points away from the vertex, giving the arrow either a diamond shape (if the absolute value of the middle inset is equal to the height) or distorted diamond shape. If the middle inset is equal to or greater than the height of the arrow cap, the cap does not appear at all. The value of the middle inset affects the arrow cap only if the arrow cap is filled. The middle inset defaults to zero when an
**AdjustableArrowCap** object is constructed.

#### Examples

The following example creates an
**AdjustableArrowCap** object,
*myArrow*, and sets the middle inset of the cap to 5 pixels. The code then creates a
**Pen** object and assigns
*myArrow* as the ending line cap for this
**Pen** object. Next, the code draws a capped line.

```cpp
VOID Example_SetMiddleInset(HDC hdc)
{
   Graphics graphics(hdc);

   // Create an AdjustableArrowCap, and set the middle inset to 5.
   AdjustableArrowCap myArrow(10, 10, true);
   myArrow.SetMiddleInset(5.0f);

   // Create a Pen, and assign myArrow as the end cap.
   Pen arrowPen(Color(255, 0, 0, 0));
   arrowPen.SetCustomEndCap(&myArrow);

   // Draw a line using arrowPen.
   graphics.DrawLine(&arrowPen, Point(0, 0), Point(100, 100));
}
```