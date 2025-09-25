# AdjustableArrowCap::GetMiddleInset

## Description

The **AdjustableArrowCap::GetMiddleInset** method gets the value of the inset. The middle inset is the number of units that the midpoint of the base shifts towards the vertex.

## Return value

Type: **REAL**

This method returns the inset value.

## Remarks

The middle inset is the number of units that the midpoint of the base shifts towards the vertex. A middle inset of zero results in no shift — the base is a straight line, giving the arrow a triangular shape. A positive (greater than zero) middle inset results in a shift the specified number of units toward the vertex — the base is an arrow shape that points toward the vertex, giving the arrow cap a V-shape. A negative (less than zero) middle inset results in a shift the specified number of units away from the vertex — the base becomes an arrow shape that points away from the vertex, giving the arrow either a diamond shape (if the absolute value of the middle inset is equal to the height) or distorted diamond shape. If the middle inset is equal to or greater than the height of the arrow cap, the cap does not appear at all. The value of the middle inset affects the arrow cap only if the arrow cap is filled. The middle inset defaults to zero when an
**AdjustableArrowCap** object is constructed.

#### Examples

The following example creates an
**AdjustableArrowCap** object,
*myArrow*, with middle inset set to zero (default value). The code then creates a
**Pen** object, assigns
*myArrow* as the ending line cap for this
**Pen** object, and draws a capped line. Next, the code gets the middle inset, increments it, and draws another capped line.

```cpp
VOID Example_GetMiddleInset(HDC hdc)
{
   Graphics graphics(hdc);

   // Create an AdjustableArrowCap with width and height set to 10.
   // Middle inset defaults to 0 pixels.
   AdjustableArrowCap myArrow(10, 10, true);

   // Create a Pen, and assign myArrow as the end cap.
   Pen arrowPen(Color(255, 0, 0, 0));
   arrowPen.SetCustomEndCap(&myArrow);

   // Draw a line using arrowPen.
   graphics.DrawLine(&arrowPen, Point(0, 10), Point(100, 10));

   // Get the inset of the arrow.
   REAL inset = myArrow.GetMiddleInset();

   // Increase inset by 5 pixels and draw another line.
   myArrow.SetMiddleInset(inset + 5);
   arrowPen.SetCustomEndCap(&myArrow);
   graphics.DrawLine(&arrowPen, Point(0, 40), Point(100, 40));
}
```