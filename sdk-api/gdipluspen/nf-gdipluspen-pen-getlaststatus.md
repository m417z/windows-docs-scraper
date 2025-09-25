# Pen::GetLastStatus

## Description

The **Pen::GetLastStatus** method returns a value that indicates the nature of this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **Pen::GetLastStatus** method returns an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object have failed since the previous call to **Pen::GetLastStatus**, then **Pen::GetLastStatus** returns **Ok**.

If at least one method invoked on this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object has failed since the previous call to **Pen::GetLastStatus**, then **Pen::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **Pen::GetLastStatus** immediately after constructing a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object to determine whether the constructor succeeded.

The first time you call the **Pen::GetLastStatus** method of a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object, it returns **Ok** if the constructor succeeded and all methods invoked so far on the
**Pen** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.

#### Examples

The following example creates a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object, sets the dash style, and draws a dashed line. The code then checks the status of the method that sets the dash style for the pen.

```cpp
VOID Example_GetLastStatus(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a pen.
   Pen pen(Color(255, 255, 0, 0), 5);

   // Set the dash style, and draw a dashed line.
   pen.SetDashStyle(DashStyleDash);
   graphics.DrawLine(&pen, 0, 0, 200, 100);

   // Check the status of the method that sets the dash style for the pen.
   Status status = pen.GetLastStatus();

   if(status == Ok)
   {
      // The call to SetDashStyle was successful.
   }
   else
   {
      // There was a problem with the call to SetDashStyle.
   }
}
```

## See also

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)