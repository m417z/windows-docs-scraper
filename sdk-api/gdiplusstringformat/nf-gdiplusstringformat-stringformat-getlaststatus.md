# StringFormat::GetLastStatus

## Description

The **StringFormat::GetLastStatus** method returns a value that indicates the nature of this
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **StringFormat::GetLastStatus** method returns an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object have failed since the previous call to **StringFormat::GetLastStatus**, then **StringFormat::GetLastStatus** returns Ok.

If at least one method invoked on this
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object has failed since the previous call to **StringFormat::GetLastStatus**, then **StringFormat::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **StringFormat::GetLastStatus** immediately after constructing a
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object to determine whether the constructor succeeded.

The first time you call the **StringFormat::GetLastStatus** method of a
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object, it returns Ok if the constructor succeeded and all methods invoked so far on the
**StringFormat** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.

#### Examples

The following example creates a
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object, calls two
**StringFormat** methods, and then checks the status to see if an error occurred during the construction or either of the method calls.

```cpp
StringFormat stringFormat;
stringFormat.SetAlignment(StringAlignmentCenter);
HotkeyPrefix hotkeyPrefix = stringFormat.GetHotkeyPrefix();

if (stringFormat.GetLastStatus() == Ok)
{
   // There have been no errors since the previous call to GetLastStatus.
}
else
{
   // An error occurred since the previous call to GetLastStatus.
}
```

## See also

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)

[StringFormatFlags](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringformatflags)