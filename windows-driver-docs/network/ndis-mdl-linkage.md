# NDIS\_MDL\_LINKAGE macro

The **NDIS\_MDL\_LINKAGE** macro retrieves a pointer to the next MDL that is associated with the specified MDL.

## Parameters

*\_Mdl*
A pointer to an MDL.

## Return value

**NDIS\_MDL\_LINKAGE** returns a pointer to an MDL or **NULL** if there is no next MDL.

## Remarks

The **NDIS\_MDL\_LINKAGE** macro provides an MDL-based version of the [**NDIS\_BUFFER\_LINKAGE**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff556919(v=vs.85)) function.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Supported in NDIS 6.0 and later. |
| Header | Ndis.h (include Ndis.h) |
| IRQL | Any level |

## See also

[**NDIS\_BUFFER\_LINKAGE**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff556919(v=vs.85))

