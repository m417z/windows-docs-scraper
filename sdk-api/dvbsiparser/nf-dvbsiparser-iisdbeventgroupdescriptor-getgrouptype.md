# IIsdbEventGroupDescriptor::GetGroupType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets a code that describes the event group type from an Integrated Services Digital Broadcasting (ISDB) event group descriptor.

## Parameters

### `pbVal` [out]

Receives the event group type. This can be any of the following values.

| Value | Meaning |
| --- | --- |
| 0x1 | Event common. |
| 0x2 | Event relay. |
| 0x3 | Event movement. |
| 0x4 | Event relay to other networks. |
| 0x5 | Event movement from other networks. |
| 0x0, 0x6-0xF | Undefined. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbEventGroupDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbeventgroupdescriptor)