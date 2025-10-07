# MXDC\_S0\_PAGE\_ENUMS enumeration

The **MXDC\_S0\_PAGE\_ENUMS** enumeration is used to specify types of resources that can be associated with pages in XPS documents and that can be processed, or passed unprocessed, by Microsoft XPS Document Converter (MXDC) to its output.

## Constants

**MXDC\_RESOURCE\_TTF**

TrueType or OpenType font.

**MXDC\_RESOURCE\_JPEG**

JPEG image

**MXDC\_RESOURCE\_PNG**

PNG image.

**MXDC\_RESOURCE\_TIFF**

TIFF image.

**MXDC\_RESOURCE\_WDP**

Windows Media Photo image.

**MXDC\_RESOURCE\_DICTIONARY**

Remote resource dictionary that should be passed to MXDC's output unprocessed.

**MXDC\_RESOURCE\_ICC\_PROFILE**

ICC profile that should be passed to MXDC's output unprocessed.

**MXDC\_RESOURCE\_JPEG\_THUMBNAIL**

JPEG thumbnail that should be passed to MXDC's output unprocessed.

**MXDC\_RESOURCE\_PNG\_THUMBNAIL**

PNG thumbnail that should be passed to MXDC's output unprocessed.

**MXDC\_RESOURCE\_MAX**

The maximum resource count for validation.

## Remarks

This enumeration is primarily used as the **dwResourceType** member of the [**MXDC\_XPS\_S0PAGE\_RESOURCE\_T**](https://learn.microsoft.com/windows/win32/printdocs/mxdcxpss0pageresource) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

