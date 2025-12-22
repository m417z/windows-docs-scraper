# IPropertySystem::FormatForDisplay

## Description

Gets a formatted, Unicode string representation of a property value.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A reference to the requested [property key](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey).

### `propvar` [in]

Type: **REFPROPVARIANT**

A reference to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure containing the type and value of the property.

### `pdff` [in]

Type: **[PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags)**

The format of the property string. See [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags) for possible values.

### `pszText` [out]

Type: **LPWSTR**

Receives the formatted value as a null-terminated, Unicode string. The calling application must allocate memory for the buffer.

### `cchText` [in]

Type: **DWORD**

The length of the buffer at *pszText* in **WCHAR****s**, including the terminating **NULL**. The maximum size is 0x8000 (32K).

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Formatted string is created. |
| **S_FALSE** | Formatted string is not created. S_FALSE indicates that the empty string resulted from a VT_EMPTY. |
| **E_OUTOFMEMORY** | Memory allocation failed. |

## Remarks

You must initialize Component Object Model (COM) with [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) before calling [IPropertySystem::FormatForDisplay](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertysystem-formatfordisplay).

When it succeeds, this method gets a formatted Unicode string representation of a property value for a specified [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey), and one or more [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags). If the **PROPERTYKEY** is not recognized by the schema subsystem, [IPropertySystem::FormatForDisplay](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertysystem-formatfordisplay) attempts to format the value according to its [VARTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms221127(v=vs.85)).

The purpose of this method is to convert data into a string suitable for display to the user. The value is formatted according to the current locale, the language of the user, the [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags), and the property description specified by the property key. For information about how the property description schema influences the formatting of the value, see [displayInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-displayinfo), [stringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat), [booleanFormat](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-booleanformat), [numberFormat](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-numberformat), [NMDATETIMEFORMAT](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-nmdatetimeformata), and [enumeratedList](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-enumeratedlist). Typically, the **PROPDESC_FORMAT_FLAGS** are used to modify the format prescribed by the property description.

The output string may contain Unicode directional characters. These nonspacing characters influence the Unicode bidirectional algorithm so that the values appear correctly when a left-to-right (LTR) language is drawn on a right-to-left (RTL) window, and vice versa. These characters include the following: `"\x200e", "\x200f", "\x202a", "\x202b", "\x202c", "\x202d", "\x202e".`

The properties in the following table use special formats and are unaffected by the [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags) (examples cited are for strings with a current locale set to English; typically, output is localized except where noted).

| Property | Format |
| --- | --- |
| System.FileAttributes | The following file attributes are converted to letters and appended to create a string (for example, a value of 0x1801 (FILE_ATTRIBUTE_READONLY \| FILE_ATTRIBUTE_COMPRESSED \| FILE_ATTRIBUTE_OFFLINE) is converted to "RCO"):<br><br>* FILE_ATTRIBUTE_READONLY (0x00000001) - 'R'<br>* FILE_ATTRIBUTE_SYSTEM (0x00000004) - 'S'<br>* FILE_ATTRIBUTE_ARCHIVE (0x00000020) -'A'<br>* FILE_ATTRIBUTE_COMPRESSED (0x00000800) - 'C'<br>* FILE_ATTRIBUTE_ENCRYPTED (0x00004000) - 'E'<br>* FILE_ATTRIBUTE_OFFLINE (0x00001000) - 'O'<br>* FILE_ATTRIBUTE_NOT_CONTENT_INDEXED (0x00002000) - 'I' |
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

If the property key does not correspond to a property description in any of the registered property schemas, this method chooses a format based on the type of the value, as described in the following table.

| **Type of the value** | **Format** |
| --- | --- |
| VT_BOOLEAN | Not supported. |
| VT_FILETIME | Date/time string as specified by [PROPDESC_FORMAT_FLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-propdesc_format_flags) and the current locale. PDFF_SHORTTIME and PDFF_SHORTDATE are the default. For example, "11/13/2006 3:22 PM". |
| Numeric VARTYPE | Decimal string in the current locale. For example, "42". |
| VT_LPWSTR or other | String. Sequences of "\r", "\t", or "\n" are replaced with a single space. |
| VT_VECTOR \| anything | Semicolon separated values—a semicolon is used regardless of locale. |