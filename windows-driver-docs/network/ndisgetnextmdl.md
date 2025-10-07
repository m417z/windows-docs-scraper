# NdisGetNextMdl macro

The **NdisGetNextMdl** macro retrieves the next MDL in an MDL chain, given a pointer to the current MDL.

## Parameters

*\_CurrentMdl*
A pointer to the specified current MDL.

*\_NextMdl*
A pointer to a caller-supplied variable in which this macro returns a pointer to the next MDL in the MDL chain, if any, that follows the MDL at *\_CurrentMdl* .

## Return value

None

## Remarks

The **NdisGetNextMdl** macro provides an MDL-based version of the [**NdisGetNextBuffer**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff552070(v=vs.85)) function.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Supported in NDIS 6.0 and later. |
| Header | Ndis.h (include Ndis.h) |
| IRQL | Any level |

## See also

[**NdisGetNextBuffer**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff552070(v=vs.85))

