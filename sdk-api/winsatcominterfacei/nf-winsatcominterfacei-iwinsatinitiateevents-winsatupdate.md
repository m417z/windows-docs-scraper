# IWinSATInitiateEvents::WinSATUpdate

## Description

[IWinSATInitiateEvents::WinSATUpdate may be altered or unavailable for releases after Windows 8.1.]

Receives notification when an assessment is making progress.

## Parameters

### `uCurrentTick` [in]

The current progress tick of the assessment.

### `uTickTotal` [in]

The total number of progress ticks for the assessment.

### `strCurrentState` [in]

A string that contains the current state of the assessment. This string is valid during the life of this callback. Copy the string if you need it after the callback returns.

## Return value

This method should return S_OK; the value is ignored.

## Remarks

You can use this method to determine the progress of a formal assessment.

**Note** You can use the *uCurrentTick* and *uTickTotal* values to mark progress for formal assessments only; the values are zero for all other assessments.

You should keep your implementation short so you do not miss subsequent updates; you will not get new updates until the method returns.

**Note** If an instance of WinSAT is already running, it is possible that you could receive one or more update callbacks for the currently running assessment.

#### Examples

For an example implementation, see the [InitiateAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iinitiatewinsatassessment-initiateassessment) or [InitiateFormalAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iinitiatewinsatassessment-initiateformalassessment) method of [IInitiateWinSATAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iinitiatewinsatassessment).

## See also

[IInitiateWinSATAssessment](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iinitiatewinsatassessment)

[IWinSATInitiateEvents](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iwinsatinitiateevents)

[IWinSATInitiateEvents::WinSATComplete](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iwinsatinitiateevents-winsatcomplete)