# CounterPathCallBack callback function

## Description

Applications implement the **CounterPathCallBack** function to process the counter path strings returned by the **Browse** dialog box.

## Parameters

### `unnamedParam1`

User-defined value passed to the callback function by the **Browse** dialog box. You set this value in the **dwCallBackArg** member of the
[PDH_BROWSE_DLG_CONFIG](https://learn.microsoft.com/windows/win32/api/pdh/ns-pdh-pdh_browse_dlg_config_a) structure.

## Return value

Return ERROR_SUCCESS if the function succeeds.

If the function fails due to a transient error, you can return PDH_RETRY and PDH will call your callback immediately.

Otherwise, return an appropriate error code. The error code is passed back to the caller of [PdhBrowseCounters](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbrowsecountersa).

## Remarks

The following members of the
[PDH_BROWSE_DLG_CONFIG](https://learn.microsoft.com/windows/win32/api/pdh/ns-pdh-pdh_browse_dlg_config_a) structure are used to communicate with the callback function:

## See also

[PDH_BROWSE_DLG_CONFIG](https://learn.microsoft.com/windows/win32/api/pdh/ns-pdh-pdh_browse_dlg_config_a)

[PdhBrowseCounters](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbrowsecountersa)