# StringFormat::SetDigitSubstitution

## Description

The **StringFormat::SetDigitSubstitution** method sets the digit substitution method and the language that corresponds to the digit substitutes.

## Parameters

### `language` [in]

Type: **LANGID**

Sixteen-bit value that forms a NLS language identifier. The identifier specifies the language associated with the substitute digits. For example, if this
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object uses Arabic substitution digits, then this method will return a value that indicates an Arabic language. An NLS language identifier is constructed by the MAKELANGID macro, declared in Winnt.h.

### `substitute` [in]

Type: **[StringDigitSubstitute](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringdigitsubstitute)**

Element of the
[StringDigitSubstitute](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringdigitsubstitute) enumeration that specifies the digit substitution method to be used.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The digit substitution method, specified by an element of the
[StringDigitSubstitute](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringdigitsubstitute) enumeration, replaces, in a string, Western European digits with digits that correspond to a user's locale or language.

When specifying LANG_NEUTRAL as the language ID, it is common practice to pass just LANG_NEUTRAL as in the following example:

`stat = FontFamily.GetFamilyName(name, LANG_NEUTRAL);`

If you are specifying a language other than LANG_NEUTRAL, use MAKELANGID to create the language and sublanguage combination as in the following example:

`LANGID language = MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_TRADITIONAL);`

For a list of the available languages and sublanguages, see Winnt.h.