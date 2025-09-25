# IDARG_IN_GETSRMLISTVERSION structure

## Description

**IDARG_IN_GETSRMLISTVERSION** is an input structure for [**IddCxMonitorGetSrmListVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorgetsrmlistversion).

## Members

### `SrmListVersionBufferInputCount` [in]

Size in bytes of the buffer being passed by the driver to the OS through **pSrmListVersion**. A value of zero indicates that the driver is simply querying the size of the SRM list version buffer that should be provided by the driver. In this case, the OS will set the buffer size in the output structure.

Either **SrmListVersionBufferInputCount** needs to be zero and **pSrmListVersion** set to null, or **SrmListVersionBufferInputCount** needs to be non-zero and **pSrmListVerion** needs to be non-null.

### `pSrmListVerion`

Pointer to a buffer in which the OS should copy the SRM list version if the value is non-NULL. In this case, the format of the version is defined by the PlayReady Porting Kit 4.0.

If **pSrmListVerion** is NULL then the OS will not copy any data and will set the value **[IDARG_OUT_GETSRMLISTVERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_getsrmlistversion).SrmListVersionBufferOutputCount** to indicate the size of buffer required to store the SRM list version.

## Remarks

## See also

[**IDARG_OUT_GETSRMLISTVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_getsrmlistversion)

[**IddCxMonitorGetSrmListVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorgetsrmlistversion)