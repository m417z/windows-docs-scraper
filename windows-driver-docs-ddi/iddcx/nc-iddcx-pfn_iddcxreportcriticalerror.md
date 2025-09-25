# PFN_IDDCXREPORTCRITICALERROR callback function

## Description

**PFN_IDDCXREPORTCRITICALERROR** is a pointer to an OS callback function through which to report a critical error.

## Parameters

### `DriverGlobals` [in]

Pointer to an [**IDD_DRIVER_GLOBALS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idd_driver_globals) structure containing system-defined per-driver data.

### `AdapterObject` [in, opt]

The adapter object of the adapter on which the critical error occurred. If the error occurred before an IDDCX_ADAPTER object was created, pass in ```nullptr``` for this value.

### `pInArgs` [in]

Pointer to an [**IDARG_IN_REPORTCRITICALERROR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_reportcriticalerror) structure containing input arguments to the function.

## Return value

If the routine succeeds, it never returns to the driver as the driver process will be terminated.

## Remarks

An indirect display driver (IDD) should not use this pointer to directly call the function that it points to. IDDs should instead call [**IddCxReportCriticalError**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxreportcriticalerror) to report a critical error.

## See also

[**IDARG_IN_REPORTCRITICALERROR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_reportcriticalerror)

[**IddCxReportCriticalError**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxreportcriticalerror)