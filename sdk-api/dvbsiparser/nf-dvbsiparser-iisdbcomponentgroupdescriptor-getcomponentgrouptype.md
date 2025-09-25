# IIsdbComponentGroupDescriptor::GetComponentGroupType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the value of the component_group_type field from an Integrated Services Digital Broadcasting (ISDB) component group descriptor. This three-bit field indicates the group type to which the components in the descriptor belong.

## Parameters

### `pbVal` [out]

Receives the group type. This can have any of the following values.

| Value | Meaning |
| --- | --- |
| 000 | Multiview television service. |
| 001-111 | Undefined. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbComponentGroupDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbcomponentgroupdescriptor-getcomponentgrouptype)