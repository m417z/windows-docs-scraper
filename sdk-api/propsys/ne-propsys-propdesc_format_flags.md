# PROPDESC_FORMAT_FLAGS enumeration

## Description

Used by property description helper functions, such as [PSFormatForDisplay](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psformatfordisplay), to indicate the format of a property string.

## Constants

### `PDFF_DEFAULT:0`

Use the format settings specified in the property's .propdesc file.

### `PDFF_PREFIXNAME:0x1`

Precede the value with the property's display name. If the *hideLabelPrefix* attribute of the [labelInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-labelinfo) element in the property's .propinfo file is set to **true**, then this flag is ignored.

### `PDFF_FILENAME:0x2`

Treat the string as a file name.

### `PDFF_ALWAYSKB:0x4`

Byte sizes are always displayed in KB, regardless of size. This enables clean alignment of the values in the column. This flag applies only to properties that have been declared as type **Integer** in the *displayType* attribute of the [displayInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-displayinfo) element in the property's .propinfo file. This flag overrides the [numberFormat](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-numberformat) setting.

### `PDFF_RESERVED_RIGHTTOLEFT:0x8`

Reserved.

### `PDFF_SHORTTIME:0x10`

Display time as "hh:mm am/pm".

### `PDFF_LONGTIME:0x20`

Display time as "hh:mm:ss am/pm".

### `PDFF_HIDETIME:0x40`

Hide the time portion of `datetime`.

### `PDFF_SHORTDATE:0x80`

Display date as "MM/DD/YY". For example, "03/21/04".

### `PDFF_LONGDATE:0x100`

Display date as "DayOfWeek, Month day, year". For example, "Monday, March 21, 2009".

### `PDFF_HIDEDATE:0x200`

Hide the date portion of `datetime`.

### `PDFF_RELATIVEDATE:0x400`

Use friendly date descriptions. For example, "Yesterday".

### `PDFF_USEEDITINVITATION:0x800`

Return the invitation text if formatting failed or the value was empty. Invitation text is text displayed in a text box as a cue for the user, such as "Enter your name". Formatting can fail if the data entered is not of an expected type, such as when alpha characters have been entered in a phone-number field.

### `PDFF_READONLY:0x1000`

If this flag is used, the **PDFF_USEEDITINVITATION** flag must also be specified. When the formatting flags are **PDFF_READONLY** | **PDFF_USEEDITINVITATION** and the algorithm would have shown invitation text, a string is returned that indicates the value is "Unknown" instead of returning the invitation text.

### `PDFF_NOAUTOREADINGORDER:0x2000`

Do not detect reading order automatically. Useful when converting to ANSI to omit the Unicode reading order characters. However, reading order characters for some values are still returned.

## Remarks

These values are defined in propsys.h and propsys.idl.

Typically use one, or a bitwise combination of these flags to specify format. Some flags are mutually exclusive, for example PDFF_SHORTTIME | PDFF_LONGTIME | PDFF_HIDETIME, is not allowed.