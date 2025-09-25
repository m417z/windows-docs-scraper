# XFORMOBJ_iGetXform function

## Description

The **XFORMOBJ_iGetXform** function downloads a transform to the driver.

## Parameters

### `pxo`

Pointer to the [XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85)) structure that defines the transform to be downloaded to the driver.

### `pxform`

Pointer to the buffer that is to receive the [XFORML](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570616(v=vs.85)) structure. This parameter can be **NULL**.

## Return value

If an error occurs, the return value is DDI_ERROR. Otherwise, the return value is a complexity hint about the transform object. The value of this transform characterization can be one of the following:

| Return code | Description |
| --- | --- |
| **GX_GENERAL** | Arbitrary 2 x 2 matrix and offset. |
| **GX_IDENTITY** | Identity matrix; no translation offset. |
| **GX_OFFSET** | Identity matrix; there is a translation offset. |
| **GX_SCALE** | Off-diagonal matrix elements are zero. |

## See also

[XFORML](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570616(v=vs.85))

[XFORMOBJ](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570618(v=vs.85))

[XFORMOBJ_bApplyXform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xformobj_bapplyxform)