# IPropertyDescription::FormatForDisplay

## Description

Gets a formatted, Unicode string representation of a property value.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

A reference to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the type and value of the property.

### `pdfFlags` [in]

Type: **[PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags)**

One or more of the [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags) flags, which are either bitwise or multiple values, that indicate the property string format.

### `ppszDisplay` [out]

Type: **LPWSTR***

The address of a pointer to a null-terminated Unicode string that contains the display text.

#### - cchText [out]

Type: **DWORD**

The length of the buffer at *pszText* in WCHARS, including the terminating **NULL**. The maximum size is 0x8000 (32K).

#### - key [in]

Type: **REFPROPERTYKEY**

A reference to the requested property key, which identifies a property. See [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey).

#### - pszText [out]

Type: **LPWSTR***

When this method returns, contains the formatted value as a **null**-terminated, Unicode string. The calling application must allocate memory for the buffer, and use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the string specified by *pszText* when it is no longer needed.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The string was copied and **null**-terminated without truncation. This string may be returned empty due to an empty input string or from a non-empty value that was formatted as an empty string. |
| **S_FALSE** | The empty string resulted from a VT_EMPTY. |
| **E_INVALIDARG** | The *pszText* parameter is **NULL**. |
| **ERROR_INSUFFICIENT_BUFFER** | The copy operation failed due to insufficient space. The destination buffer is modified to contain a truncated version of the ideal result and is **null**-terminated. |

## Remarks

You must initialize Component Object Model (COM) with [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) before calling [IPropertyDescription::FormatForDisplay](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescription-formatfordisplay).

On success, this method gets a formatted Unicode string representation of a property value for a specified [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey), and one or more [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags).

The purpose of this method is to convert data into a string suitable for display to the user. The value is formatted according to the current locale, the language of the user, the [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags), and the property description specified by the property key. For information about how the property description schema influences the formatting of the value, see [displayInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-displayinfo), [stringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat), [booleanFormat](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-booleanformat), [numberFormat](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-numberformat), [NMDATETIMEFORMAT](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-nmdatetimeformata), and [enumeratedList](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-enumeratedlist). Typically, the **PROPDESC_FORMAT_FLAGS** are used to modify the format prescribed by the property description.

The output string can contain Unicode directional characters. These nonspacing characters influence the Unicode bidirectional algorithm so that the values appear correctly when a left-to-right (LTR) language is drawn onto a right-to-left (RTL) window, and vice versa. These characters include the following: `"\x200e", "\x200f", "\x202a", "\x202b", "\x202c", "\x202d", "\x202e".`

The following properties use special formats and are unaffected by the [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags) (examples cited are for strings with a current locale set to English; typically, output is localized except where noted).

| Property | Format |
| --- | --- |
| [System.FileAttributes](https://learn.microsoft.com/windows/desktop/properties/props-system-fileattributes) | The following file attributes are converted to letters and appended to create a string (for example, a value of 0x1801 (FILE_ATTRIBUTE_READONLY \| FILE_ATTRIBUTE_COMPRESSED \| FILE_ATTRIBUTE_OFFLINE) is converted to "RCO"):<br><br>* FILE_ATTRIBUTE_READONLY (0x00000001) - 'R'<br>* FILE_ATTRIBUTE_SYSTEM (0x00000004) - 'S'<br>* FILE_ATTRIBUTE_ARCHIVE (0x00000020) -'A'<br>* FILE_ATTRIBUTE_COMPRESSED (0x00000800) - 'C'<br>* FILE_ATTRIBUTE_ENCRYPTED (0x00004000) - 'E'<br>* FILE_ATTRIBUTE_OFFLINE (0x00001000) - 'O'<br>* FILE_ATTRIBUTE_NOT_CONTENT_INDEXED (0x00002000) - 'I' |
| [System.Photo.ISOSpeed](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-isospeed) | For example, "ISO-400". |
| [System.Photo.ShutterSpeed](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-shutterspeed) | The APEX value is converted to an exposure time using this formula:<br><br>`Exposure_time = 2^(-APEX_value)`<br><br>For example, "2 sec."or "1/125 sec.". |
| [System.Photo.ExposureTime](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-exposuretime) | For example, "2 sec."or "1/125 sec." |
| [System.Photo.Aperture](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-aperture) | The APEX value is converted to an F number using this formula:<br><br>`F_Number = 2^(APEX_Value / 2)`<br><br>For example, "f/5.6". |
| [System.Photo.FNumber](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-fnumber) | For example, "f/5.6". |
| [System.Photo.SubjectDistance](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-subjectdistance) | For example, "15 m"or "250 mm". |
| [System.Photo.FocalLength](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-focallength) | For example, "50 mm". |
| [System.Photo.FlashEnergy](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-flashenergy) | For example, "500 bpcs". |
| [System.Photo.ExposureBias](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-exposurebias) | For example, "-2 step", " 0 step", or "+3 step". |
| [System.Computer.DecoratedFreeSpace](https://learn.microsoft.com/windows/desktop/properties/props-system-computer-decoratedfreespace) | For example, "105 MB free of 13.2 GB". |
| [System.ItemType](https://learn.microsoft.com/windows/desktop/properties/props-system-itemtype) | For example, "Application" or "JPEG Image". |
| [System.ComputerName](https://learn.microsoft.com/windows/desktop/properties/props-system-computername) | For example, "LITWARE05 (this computer)" or "testbox07". |

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)