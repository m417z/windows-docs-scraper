## Description

The **IDARG_IN_REPORTCRITICALERROR** structure contains information about a critical error being reported by an indirect display driver (IDD).

## Members

### `MajorErrorCode`

[In] The major error code for this critical error. Valid range 0-0xff inclusive. IddCx will add 0x100 to this value before passing to Windows Error Reporting when creating a memory dump.

### `MinorErrorCode`

[in] The minor error code for this critical error. Valid range 0-0xff inclusive.

## Remarks

It is recommended that the driver use a unique combination of a major code and minor code so these cases can be identified in crashes and Watson reports.

## See also

[**IddCxReportCriticalError**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxreportcriticalerror)