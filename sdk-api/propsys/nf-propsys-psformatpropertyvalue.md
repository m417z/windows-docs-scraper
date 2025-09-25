# PSFormatPropertyValue function

## Description

Gets a formatted, Unicode string representation of a property value stored in a property store. This function allocates memory for the output string.

## Parameters

### `pps` [in]

Type: **[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)***

Pointer to an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore), which represents the property store from which the property value is taken.

### `ppd` [in]

Type: **[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)***

Pointer to an [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription), which represents the property whose value is being retrieved.

### `pdff` [in]

Type: **[PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags)**

One or more [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags) that specify the format to apply to the property string. See **PROPDESC_FORMAT_FLAGS** for possible values.

### `ppszDisplay` [out]

Type: **LPWSTR***

When the function returns, contains a pointer to the formatted value as a null-terminated, Unicode string.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function uses the *ppd* parameter to call [IPropertyDescription::FormatForDisplay](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescription-formatfordisplay). That call provides a Unicode string representation of a property value, with additional formatting based on one or more [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags).

You must initialize Component Object Model (COM) with [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) before you call [PSFormatPropertyValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psformatpropertyvalue).

The function allocates memory and returns a pointer to that memory in *ppszDisplay*. The calling application must use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the string specified by *ppszDisplay* when it is no longer needed.

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

The following example, to be included as part of a larger program, demonstrates how to use [PSFormatPropertyValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psformatpropertyvalue) to format a rating value.

```cpp
// IPropertyStore *pStore;
// Assume the variable pps is initialized and valid.
IPropertyDescription *pPropDesc;

HRESULT hr = PSGetPropertyDescription(PKEY_Rating, IID_PPV_ARGS(&pPropDesc));

if (SUCCEEDED(hr))
{
    PWSTR pszValue;

    hr = PSFormatPropertyValue(pStore, pPropDesc, PDFF_DEFAULT, &pszValue);

    if (SUCCEEDED(hr))
    {
        // pszValue contains a formatted string similar to "3 stars".
        CoTaskMemFree(pszValue);
    }
    pPropDesc->Release();
}
```

## See also

[PSFormatForDisplay](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psformatfordisplay)

[PSFormatForDisplayAlloc](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psformatfordisplayalloc)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)