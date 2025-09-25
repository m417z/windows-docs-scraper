# PFNRASSETCOMMSETTINGS callback function

## Description

Call
**RasSetCommSettings** from a custom-scripting DLL to change the settings on the port for the connection.

## Parameters

### `hPort` [in]

Handle to the port on which to apply the settings. This handle is passed to the custom-scripting DLL in the
[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn) function.

### `pRasCommSettings` [in]

Pointer to a
[RASCOMMSETTINGS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376724(v=vs.85)) structure that specifies the settings to be applied to the port.

### `pvReserved` [in]

Reserved for future use. This parameter must be **NULL**.

## Return value

This callback function does not return a value.

## Remarks

RAS passes the custom-scripting DLL a pointer to the
**RasSetCommSettings** function when RAS calls
[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn). The pointer is stored in the
[RASCUSTOMSCRIPTEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376738(v=vs.85)) structure that is passed as the last parameter of
**RasCustomScriptExecute**.

## See also

[RAS Custom-Scripting](https://learn.microsoft.com/windows/desktop/RRAS/ras-custom-scripting)

[RASCOMMSETTINGS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376724(v=vs.85))

[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn)