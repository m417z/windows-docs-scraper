# IIsdbSeriesDescriptor::GetProgramPattern

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a code that indicates how often a series is programmed from an Integrated Services Digital Broadcasting (ISDB) series descriptor.

## Parameters

### `pbVal` [out]

Receives the program pattern code. This can be any of the following values.

| Value | Meaning |
| --- | --- |
| 0x0 | Unscheduled. |
| 0x1 | Programmed several times weekly. |
| 0x2 | Programmed once weekly. |
| 0x3 | Programmed once monthly. |
| 0x4 | Programmed several times in a single day. |
| 0x5 | Division of a long program. |
| 0x6 | Program for regular or irregular accumulation. |
| 0x7 | Undefined. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbSeriesDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbseriesdescriptor)