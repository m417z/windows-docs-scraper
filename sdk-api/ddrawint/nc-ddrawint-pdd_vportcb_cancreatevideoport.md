## Description

The *DdVideoPortCanCreate* callback function determines whether the driver can support a DirectDraw VPE object of the specified description.

## Parameters

### `unnamedParam1`

Points to a [DD_CANCREATEVPORTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_cancreatevportdata) structure that contains the information necessary for the driver to determine whether the specified DirectDraw VPE object can be supported.

## Return value

*DdVideoPortCanCreate* returns one of the following callback codes:

## Remarks

*DdVideoPortCanCreate* must be implemented in drivers that support VPE.

The driver should check the members of the [DDVIDEOPORTDESC](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportdesc) structure to which the **lpDDVideoPortDesc** member of the DD_CANCREATEVPORTDATA structure at *lpCanCreateVideoPort* points to determine whether the hardware supports the specified type of VPE object.

## See also

[DDVIDEOPORTDESC](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportdesc)

[DD_CANCREATEVPORTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_cancreatevportdata)

[DdVideoPortCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_createvideoport)