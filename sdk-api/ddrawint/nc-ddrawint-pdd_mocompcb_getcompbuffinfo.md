## Description

The **DDMoCompGetBuffInfo** callback function allows the driver to specify how many interim surfaces are required to support the specified GUID, and the size, location, and format of each of these surfaces.

## Parameters

### `unnamedParam1`

Points to a [DD_GETMOCOMPCOMPBUFFDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getmocompcompbuffdata) structure that contains the compressed buffer information.

## Return value

**DDMoCompGetBuffInfo** returns one of the following callback codes:

## Remarks

**DDMoCompGetBuffInfo** can be optionally implemented in DirectDraw drivers. This function is required for motion compensation support.

## See also

[DD_GETMOCOMPCOMPBUFFDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getmocompcompbuffdata)