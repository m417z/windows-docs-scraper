## Description

The **IDARG_OUT_GETVERSION** structure identifies the IddCx (Indirect Display Driver Class eXtension) version.

## Members

### `IddCxVersion`

ULONG value that identifies the IddCx version that the driver is running on. See [IddCx versions](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-versions) for a complete list of possible version values.

## Remarks

An ID driver calls [**IddCxGetVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxgetversion) to determine the IddCx version that the driver is running on.

## See also

[IddCx versions](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-versions)

[**IddCxGetVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxgetversion)

[**PFN_IDDCXGETVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-pfn_iddcxgetversion)