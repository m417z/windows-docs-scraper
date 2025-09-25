# StringFormat::StringFormat(IN INT,IN LANGID)

## Description

Creates a [StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object based on string format flags and a language.

## Parameters

### `formatFlags` [in]

Type: **INT**

Optional. Value that specifies the format flags that control most of the characteristics of the [StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object. The flags are set by applying a bitwise
**OR** to elements of the [StringFormatFlags](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringformatflags) enumeration. The default value is 0 (no flags set).

### `language` [in]

Type: **LANGID**

Optional. Sixteen-bit value that specifies the language to use. The default value is LANG_NEUTRAL, which is the user's default language.

## Remarks

When specifying LANG_NEUTRAL as the language ID, it is common practice to pass just LANG_NEUTRAL as in the following example:

`stat = FontFamily.GetFamilyName(name, LANG_NEUTRAL);`

If you are specifying a language other than LANG_NEUTRAL, use [MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid) to create the language and sublanguage combination as in the following example:

`LANGID language = MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_TRADITIONAL);`

For a list of the available languages and sublanguages, see Winnt.h.

## See also

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)

[StringFormatFlags](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringformatflags)