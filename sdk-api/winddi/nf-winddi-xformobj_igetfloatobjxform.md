# XFORMOBJ_iGetFloatObjXform function

## Description

The **XFORMOBJ_iGetFloatObjXform** function downloads a FLOATOBJ transform to the driver.

## Parameters

### `pxo`

Pointer to the [XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85)) structure that defines the transform to be downloaded.

### `pfxo`

Pointer to the buffer that is to receive the [FLOATOBJ_XFORM](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj_xform) structure. This parameter can be **NULL**.

## Return value

If an error occurs, the return value is DDI_ERROR. Otherwise, the return value is a complexity hint about the transform object. The value of this transform characterization can be one of the following:

| Return code | Description |
| --- | --- |
| **GX_GENERAL** | Arbitrary 2 x 2 matrix and offset. |
| **GX_IDENTITY** | Identity matrix; no translation offset. |
| **GX_OFFSET** | Identity matrix; there is a translation offset. |
| **GX_SCALE** | Off-diagonal matrix elements are zero. |

## Remarks

If *pxfo* is not **NULL**, **XFORMOBJ_iGetFloatObjXform** loads a FLOATOBJ_XFORM into the memory location *pxfo* points to. This function allows graphics drivers to emulate floating-point arithmetic. NT-based operating systems do not support kernel-mode floating-point operations on some systems.

## See also

[FLOATOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj)

[FLOATOBJ_XFORM](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-floatobj_xform)

[XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85))