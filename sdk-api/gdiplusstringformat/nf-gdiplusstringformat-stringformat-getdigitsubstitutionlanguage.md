# StringFormat::GetDigitSubstitutionLanguage

## Description

The **StringFormat::GetDigitSubstitutionLanguage** method gets the language that corresponds with the digits that are to be substituted for Western European digits.

## Return value

Type: **LANGID**

This method returns a 16-bit value that forms a National Language Support (NLS) language identifier. This identifier indicates the language that corresponds with the substitution digits. For example, if this
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object uses Arabic substitution digits, then this method will return a value that indicates an Arabic language. An NLS language identifier is constructed by the MAKELANGID macro declared in Winnt.h.