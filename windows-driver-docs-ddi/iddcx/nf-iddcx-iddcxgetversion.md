## Description

**IddCxGetVersion** is an OS callback function that an indirect display (ID) driver calls to obtain the IddCx version (Indirect Display Driver Class eXtension).

## Parameters

### `pOutArgs` [out]

Pointer to an [**IDARG_OUT_GETVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_getversion) structure in which the current IddCx version is returned. See Remarks.

## Return value

(NTSTATUS) **IddCxGetVersion** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

See [IddCx versions](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-versions) for a complete list of possible version values.

## See also

[**IDARG_OUT_GETVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_getversion)

[IddCx versions](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-versions)