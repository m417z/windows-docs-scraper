## Description

The **DdMoCompGetGuids** callback function retrieves the number of GUIDs the driver supports.

## Parameters

### `unnamedParam1`

Points to a [DD_GETMOCOMPGUIDSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getmocompguidsdata) structure that contains the GUID information.

## Return value

**DdMoCompGetGuids** returns one of the following callback codes:

## Remarks

DirectDraw drivers that support motion compensation must implement **DdMoCompGetGuids**.

## See also

[DD_GETMOCOMPGUIDSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getmocompguidsdata)