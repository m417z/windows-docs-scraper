## Description

**IddCxReportCriticalError** is an OS callback function called by an indirect display driver (IDD) to report a critical error.

## Parameters

### `AdapterObject`

An [IDDCX_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object of the adapter on which the critical error occurred. If the error occurred before an IDDCX_ADAPTER was created, the IDD should pass ```nullptr```.

### `pInArgs`

Pointer to an [**IDARG_IN_REPORTCRITICALERROR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_reportcriticalerror) structure containing the error code of the critical error.

## Return value

If the routine succeeds it never returns to the driver because the driver process will be terminated.

## Remarks

When an IDD calls **IddCxCriticalError**, the OS will do the following:

* Bugcheck the driver with the following bugcheck code: ```(pInArgs->MajorErrorCode+0x100 << 8) + pInArgs->MinorErrorCode```. It is recommended that the driver use a unique combination of a major code and minor code so these cases can be identified in crashes and Watson reports.
* Terminate the driver process and restart according to the UMDF driver restart policy.
* If the caller is a remote IDD, disconnect the user session.

As a user mode memory dump is generated, the driver should place any useful debug information on the stack of the function that called **IddCxCriticalError**.

## See also

[**IDARG_IN_REPORTCRITICALERROR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_reportcriticalerror)