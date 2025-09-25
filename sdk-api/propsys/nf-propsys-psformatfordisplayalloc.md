# PSFormatForDisplayAlloc function

## Description

Gets a formatted, Unicode string representation of a property value stored in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. This function allocates memory for the output string.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

Reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) that names the property whose value is being retrieved.

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the type and value of the property.

### `pdff` [in]

Type: **[PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags)**

One or more flags that specify the format to apply to the property string. See [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags) for possible values.

### `ppszDisplay` [out]

Type: **PWSTR***

When the function returns, contains a pointer to a null-terminated, Unicode string representation of the requested property value.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The formatted string was successfully created. **S_OK** together with an empty return string indicates that there was an empty input string or a non-empty value that was formatted as an empty string. |
| **S_FALSE** | The formatted string was not created. S_FALSE together with an empty return string indicates that the empty string resulted from a VT_EMPTY. |
| **E_OUTOFMEMORY** | Indicates allocation failed. |

## Remarks

This function calls the schema subsystem's implementation of [IPropertySystem::FormatForDisplayAlloc](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertysystem-formatfordisplayalloc). That call provides a Unicode string representation of a property value, with additional formatting based on one or more [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags). If the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) is not recognized by the schema subsystem, **IPropertySystem::FormatForDisplayAlloc** attempts to format the value according to the value's [VARTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms221127(v=vs.85)).

You must initialize Component Object Model (COM) with [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) before you call [PSFormatForDisplayAlloc](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psformatfordisplayalloc).

The function allocates memory through [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and returns a pointer to that memory through the *ppszDisplay* parameter. The calling application must use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release that resource when it is no longer needed.

The purpose of this function is to convert data into a string suitable for display to the user. The value is formatted according to the current locale, the language of the user, the [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags), and the property description specified by the property key. For information on how the property description schema influences the formatting of the value, see the following topics:

* [displayInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-displayinfo)
* [stringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)
* [booleanFormat](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-booleanformat)
* [numberFormat](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-numberformat)
* [NMDATETIMEFORMAT](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-nmdatetimeformata)
* [enumeratedList](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-enumeratedlist)

Typically, the **PROPDESC_FORMAT_FLAGS** are used to modify the format prescribed by the property description.

The output string can contain Unicode directional characters. These nonspacing characters influence the Unicode bidirectional algorithm so that the values appear correctly when a left-to-right (LTR) language is drawn on a right-to-left (RTL) window, or an RTL is drawn on a LTR window. These characters include the following: `"\x200e", "\x200f", "\x202a", "\x202b", "\x202c", "\x202d", "\x202e".`

The following properties use special formats and are unaffected by the [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags). Note that examples cited are for strings with a current locale set to English; typically, output is localized except where noted.

| Property | Format |
| --- | --- |
| System.FileAttributes | The following file attributes are converted to letters and appended to create a string (for example, a value of 0x1801 (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_COMPRESSED | FILE_ATTRIBUTE_OFFLINE) is converted to "RCO"):<br><br>* FILE_ATTRIBUTE_READONLY (0x00000001) - 'R'<br>* FILE_ATTRIBUTE_SYSTEM (0x00000004) - 'S'<br>* FILE_ATTRIBUTE_ARCHIVE (0x00000020) -'A'<br>* FILE_ATTRIBUTE_COMPRESSED (0x00000800) - 'C'<br>* FILE_ATTRIBUTE_ENCRYPTED (0x00004000) - 'E'<br>* FILE_ATTRIBUTE_OFFLINE (0x00001000) - 'O'<br>* FILE_ATTRIBUTE_NOT_CONTENT_INDEXED (0x00002000) - 'I' |
| System.Photo.ISOSpeed | For example, "ISO-400". |
| System.Photo.ShutterSpeed | The APEX value is converted to an exposure time using this formula:<br><br>`Exposure_time = 2^(-APEX_value)`<br><br>For example, "2 sec."or "1/125 sec.". |
| System.Photo.ExposureTime | For example, "2 sec."or "1/125 sec." |
| System.Photo.Aperture | The APEX value is converted to an F number using this formula:<br><br>`F_Number = 2^(APEX_Value / 2)`<br><br>For example, "f/5.6". |
| System.Photo.FNumber | For example, "f/5.6". |
| System.Photo.SubjectDistance | For example, "15 m"or "250 mm". |
| System.Photo.FocalLength | For example, "50 mm". |
| System.Photo.FlashEnergy | For example, "500 bpcs". |
| System.Photo.ExposureBias | For example, "-2 step", " 0 step", or "+3 step". |
| System.Computer.DecoratedFreeSpace | For example, "105 MB free of 13.2 GB". |
| System.ItemType | For example, "Application" or "JPEG Image". |
| System.ControlPanel.Category | For example, "Appearance and Personalization". |
| System.ComputerName | For example, "LITWARE05 (this computer)" or "testbox07". |

If the property key does not correspond to a property description in any of the registered property schemas, then this function chooses a format based on the type of the value.

| Type of the value | Format |
| --- | --- |
| VT_BOOLEAN | Not supported. |
| VT_FILETIME | Date/time string as specified by [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags) and the current locale. PDFF_SHORTTIME and PDFF_SHORTDATE are the default. For example, "11/13/2006 3:22 PM". |
| Numeric VARTYPE | Decimal string in the current locale. For example, "42". |
| VT_LPWSTR or other | Converted to a string. Sequences of "\r", "\t", or "\n" are replaced with a single space. |
| VT_VECTOR | anything | Semicolon separated values. A semicolon is used regardless of locale. |

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSFormatForDisplayAlloc](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psformatfordisplayalloc) to format a rating value.

```cpp
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromUInt32(RATING_THREE_STARS_SET, &propvar);

if (SUCCEEDED(hr))
{
    PWSTR pszValue;

    hr = PSFormatForDisplayAlloc(PKEY_Rating, propvar, PDFF_DEFAULT, &pszValue);

    if (SUCCEEDED(hr))
    {
        // pszValue contains a formatted string similar to "3 stars".
         CoTaskMemFree(pszValue);
    }
    PropVariantClear(&propvar);
}
```

## See also

[PSFormatForDisplay](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psformatfordisplay)

[PSFormatPropertyValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psformatpropertyvalue)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)