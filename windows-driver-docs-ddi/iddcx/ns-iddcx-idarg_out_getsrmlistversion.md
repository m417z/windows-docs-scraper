# IDARG_OUT_GETSRMLISTVERSION structure

## Description

**IDARG_OUT_GETSRMLISTVERSION** is the output structure for [**IddCxMonitorGetSrmListVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorgetsrmlistversion).

## Members

### `SrmListVersionBufferOutputCount` [out]

If **[IDARG_IN_GETSRMLISTVERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_getsrmlistversion).pSrmListVersion** is NULL, the OS will set **SrmListVersionBufferOutputCount** to the size, in bytes, of the buffer needed to read the SRM list version description. If **IDARG_IN_GETSRMLISTVERSION.pSrmListVersion** is non-NULL, then **SrmListVersionBufferOutputCount** is the number of bytes returned in **IDARG_IN_GETSRMLISTVERSION.pSrmListVersion** buffer. If there was no SRM list set, the OS will set **SrmListVersionBufferOutputCount** to zero.

## Remarks

## See also

[**IDARG_IN_GETSRMLISTVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_getsrmlistversion)

[**IddCxMonitorGetSrmListVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorgetsrmlistversion)