# IWinSATInitiateEvents::WinSATComplete

## Description

[IWinSATInitiateEvents::WinSATComplete may be altered or unavailable for releases after Windows 8.1.]

Receives notification when an assessment succeeds, fails, or is canceled.

## Parameters

### `hresult` [in]

The return value of the assessment. The following are the possible return values of the assessment.

| Value | Meaning |
| --- | --- |
| **WINSAT_STATUS_COMPLETED_SUCCESS**<br><br>0x40033 | The assessment completed successfully. |
| **WINSAT_ERROR_ASSESSMENT_INTERFERENCE**<br><br>0x80040034 | The assessment could not complete due to system activity. |
| **WINSAT_ERROR_COMPLETED_ERROR**<br><br>0x80040035 | The assessment could not complete due to an internal or system error. |
| **WINSAT_ERROR_WINSAT_CANCELED**<br><br>0x80040036 | The assessment was canceled. |
| **WINSAT_ERROR_COMMAND_LINE_INVALID**<br><br>0x80040037 | The command line passed to WinSAT was not valid. |
| **WINSAT_ERROR_ACCESS_DENIED**<br><br>0x80040038 | The user does not have sufficient privileges to run WinSAT. |
| **WINSAT_ERROR_WINSAT_ALREADY_RUNNING**<br><br>0x80040039 | Another copy of WinSAT.exe is already running; only one instance of WinSAT.exe can run on the computer at one time. |

### `strDescription` [in]

The description of the completion status. This string is valid during the life of this callback. Copy the string if you need it after the callback returns.

## Return value

This method should return S_OK; the value is ignored.

## See also

[IInitiateWinSATAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iinitiatewinsatassessment)

[IWinSATInitiateEvents](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iwinsatinitiateevents)

[IWinSATInitiateEvents::WinSATUpdate](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iwinsatinitiateevents-winsatupdate)