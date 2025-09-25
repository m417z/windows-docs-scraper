# RasCustomHangUpFn callback function

## Description

The
**RasCustomHangUp** function is an application-defined function that is exported by a third-party custom-dialing DLL. This function allows third-party vendors to implement custom connection hang-up routines.

## Parameters

### `hRasConn`

Handle to the RAS connection to hang up.

## Return value

If the function succeeds, the return value should be **ERROR_SUCCESS**.

If the function fails, the return value should be a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

## Remarks

RAS calls this entry point from
[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa), if the **szCustomDialDll** member of the
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure for the entry being dialed specifies a custom-dialing DLL.

## See also

[Custom Dialers](https://learn.microsoft.com/windows/desktop/RRAS/custom-dialers)

[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))

[RasCustomDial](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomdialfn)

[RasCustomDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nc-rasdlg-rascustomdialdlgfn)

[RasCustomEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nc-rasdlg-rascustomentrydlgfn)

[RasHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rashangupa)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)