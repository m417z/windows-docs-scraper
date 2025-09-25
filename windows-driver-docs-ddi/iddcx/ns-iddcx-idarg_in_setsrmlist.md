# IDARG_IN_SETSRMLIST structure

## Description

**IDARG_IN_SETSRMLIST** is the input structure for [**IddCxMonitorSetSrmList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorsetsrmlist).

## Members

### `SrmListSizeInBytes` [in]

The size, in bytes, of the buffer pointed to by **pSrmList**.

### `pSrmList` [in]

Pointer to a buffer that holds the SRM list to pass to the appropriate WDDM driver. This buffer should contain the SRM in the format required by the Digital Content Protection LLC for HDCP.

## Remarks

## See also

[**IddCxMonitorSetSrmList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorsetsrmlist)