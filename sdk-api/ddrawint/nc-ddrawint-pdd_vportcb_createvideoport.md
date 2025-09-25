## Description

The **DdVideoPortCreate** callback function notifies the driver that DirectDraw has created a VPE object.

## Parameters

### `unnamedParam1`

Points to a [DD_CREATEVPORTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_createvportdata) structure that describes the created VPE object.

## Return value

**DdVideoPortCreate** returns one of the following values:

## Remarks

**DdVideoPortCreate** can be optionally implemented in DirectDraw drivers that support VPE.

**DdVideoPortCreate** can allocate memory for and initialize any private, VPE object-specific data. The driver can use the **dwReserved1** and **dwReserved2** members of the [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure to store this data. This DD_VIDEOPORT_LOCAL structure is at the **lpVideoPort** member of the DD_CREATEVPORTDATA structure at *lpCreateVideoPort*. The driver cannot use or change any other members of the DD_VIDEOPORT_LOCAL structure.

If the hardware video port is implemented to use the feature connector, the driver might need to initialize the feature connector for hardware video port use.

**DdVideoPortCreate** should not turn the hardware video port on. This is accomplished in [DdVideoPortUpdate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_update).

## See also

[DD_CREATEVPORTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_createvportdata)

[DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local)

[DdVideoPortUpdate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_update)