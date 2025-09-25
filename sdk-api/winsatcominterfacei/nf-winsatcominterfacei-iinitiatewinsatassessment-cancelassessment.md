# IInitiateWinSATAssessment::CancelAssessment

## Description

[IInitiateWinSATAssessment::CancelAssessment may be altered or unavailable for releases after Windows 8.1.]

Cancels a currently running assessment.

## Return value

Returns S_OK if successful; otherwise, the method returns the following error code or a Win32 error code returned as an HRESULT.

| Return code/value | Description |
| --- | --- |
| **WINSAT_ERROR_WINSAT_NOT_RUNNING**<br><br>0x80040006 | There is no running assessment to cancel. |

## Remarks

This method sends WinSAT a request to cancel the assessment. To determine if the cancel request succeeded, implement the [IWinSATInitiateEvents::WinSATComplete](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iwinsatinitiateevents-winsatcomplete) method and check the *hresult* parameter for a value of WINSAT_ERROR_WINSAT_CANCELED.

## See also

[IInitiateWinSATAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iinitiatewinsatassessment)

[IInitiateWinSATAssessment::InitiateAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iinitiatewinsatassessment-initiateassessment)

[IInitiateWinSATAssessment::InitiateFormalAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iinitiatewinsatassessment-initiateformalassessment)