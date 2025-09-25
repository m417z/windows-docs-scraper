# FltStartFiltering function

## Description

**FltStartFiltering** starts filtering for a registered minifilter driver.

## Parameters

### `Filter` [in]

Opaque filter pointer returned by [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

## Return value

**FltStartFiltering** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | Filtering was already started for this minifilter driver. This is an error code. |

## Remarks

A minifilter driver typically calls **FltStartFiltering** from its **DriverEntry** routine after it has completed its global initialization and called [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter). **FltStartFiltering** notifies the Filter Manager that the minifilter driver is ready to begin attaching to volumes and filtering I/O requests. After the minifilter driver calls this routine, the Filter Manager treats the minifilter driver as a fully active minifilter driver, presenting it with volumes to attach to, as well as I/O requests. The minifilter driver must be prepared to begin receiving these notifications and I/O requests even before **FltStartFiltering** returns.

## See also

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)