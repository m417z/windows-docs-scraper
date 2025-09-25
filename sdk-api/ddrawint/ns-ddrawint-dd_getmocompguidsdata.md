# DD_GETMOCOMPGUIDSDATA structure

## Description

The DD_GETMOCOMPGUIDSDATA structure contains the motion compensation GUID information.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `dwNumGuids`

Indicates the number of motion compensation GUIDs in **lpGuids**.

### `lpGuids`

Points to a list of GUIDs that describe the motion compensation processes being used. If **lpGuids** is **NULL**, the driver should set **dwNumGuids** to the number of GUIDs that it supports. Otherwise, it should fill **lpGuids** with the GUIDs that it supports and set the number in **dwNumGuids**.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdMoCompGetGuids](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getguids) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdMoCompGetGuids](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_getguids)