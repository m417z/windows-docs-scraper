# StringFormat::SetFormatFlags

## Description

The **StringFormat::SetFormatFlags** method sets the format flags for this
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object. The format flags determine most of the characteristics of a
**StringFormat** object.

## Parameters

### `flags` [in]

Type: **INT**

Thirty-two bit value that specifies the format flags that control most of the characteristics of the
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object. The flags are set by applying a bitwise
**OR** to elements of the
[StringFormatFlags](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringformatflags) enumeration.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)