# NDIS\_MDL\_TO\_SPAN\_PAGES macro

The **NDIS\_MDL\_TO\_SPAN\_PAGES** macro retrieves the number of physical pages of memory that are being used to back a given MDL.

## Parameters

*\_Mdl*
A pointer to an MDL.

## Return value

**NDIS\_MDL\_TO\_SPAN\_PAGES** returns the number of pages that are backing the virtual range for the MDL.

## Remarks

The **NDIS\_MDL\_TO\_SPAN\_PAGES** macro provides an MDL-based version of the [**NDIS\_BUFFER\_TO\_SPAN\_PAGES**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff556922(v=vs.85)) function.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Supported in NDIS 6.0 and later. |
| Header | Ndis.h (include Ndis.h) |
| IRQL | Any level |

## See also

[**NDIS\_BUFFER\_TO\_SPAN\_PAGES**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff556922(v=vs.85))

