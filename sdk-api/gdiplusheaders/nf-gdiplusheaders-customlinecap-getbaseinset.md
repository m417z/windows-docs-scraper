# CustomLineCap::GetBaseInset

## Description

The **CustomLineCap::GetBaseInset** method gets the distance between the base cap to the start of the line.

## Return value

Type: **REAL**

This method returns the base inset value.

## Remarks

The base inset is used to separate the base cap from the start of the line. A value of 0 makes the base cap and the line touch. A value greater than 0 inserts a space (in units) between the line cap and the start of the line.

#### Examples

The following example creates a [CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap) object, gets the base inset of the cap, and then creates a second **CustomLineCap** object that uses the same base inset.

```cpp
VOID Example_GetBaseInset(HDC hdc)
{
   Graphics graphics(hdc);

   //Create a Path object.
   GraphicsPath capPath;

   //Create a CustomLineCap object, and set its base cap to LineCapRound.
   CustomLineCap custCap(NULL, &capPath, LineCapRound, 5);

   // Get the base inset of custCap.
   REAL baseInset = custCap.GetBaseInset();

   // Create a second CustomLineCap object with the same base inset as the
   // first.
   CustomLineCap insetCap(NULL, &capPath, LineCapRound, baseInset);

   // Create a Pen object and assign insetCap as the custom end cap.
   // Then draw a line.
   Pen pen(Color(255, 0, 0, 255), 5);
   pen.SetCustomEndCap(&insetCap);
   graphics.DrawLine(&pen, Point(0, 0), Point(100, 100));
}
```

## See also

[CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap)

[LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap)