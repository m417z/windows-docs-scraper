# FwpsInjectionHandleDestroy0 function

## Description

The
**FwpsInjectionHandleDestroy0** function destroys an injection handle that was previously created by
calling the
[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function.

**Note** **FwpsInjectionHandleDestroy0** is a specific version of **FwpsInjectionHandleDestroy**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `injectionHandle` [in]

The injection handle being destroyed.

## Return value

The
**FwpsInjectionHandleDestroy0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The injection handle was successfully destroyed. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsInjectionHandleDestroy0** function to destroy an injection handle that was previously created by
calling the
[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function. The
**FwpsInjectionHandleDestroy0** function will not return to the caller until all pending injections are
completed.

## See also

[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0)