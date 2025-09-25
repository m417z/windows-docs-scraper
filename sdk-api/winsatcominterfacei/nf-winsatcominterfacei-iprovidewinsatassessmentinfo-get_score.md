# IProvideWinSATAssessmentInfo::get_Score

## Description

[IProvideWinSATAssessmentInfo::Score may be altered or unavailable for releases after Windows 8.1.]

Retrieves the score for the subcomponent.

This property is read-only.

## Parameters

## Remarks

The score represents the subcomponent's metrics as normalized by WinSAT. The score is a floating point value that should be displayed with only one significant digit to the right of the decimal point. The value is 0.0 if the assessment is unavailable or not valid.

A user can use the score to determine if a subcomponent of the computer can support a specific type of application. For example, a user that spends more time reading or writing documents may require a higher score for the disk than a user who runs scientific applications, and a user who runs scientific applications would probably want a higher CPU subcomponent score and may not be concerned with a lower disk score.

To get the base score for the computer, call the [IProvideWinSATResultsInfo::get_SystemRating](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iprovidewinsatresultsinfo-get_systemrating) method.

#### Examples

For an example, see the [IProvideWinSATResultsInfo::GetAssessmentInfo](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iprovidewinsatresultsinfo-getassessmentinfo) method.

## See also

[IProvideWinSATAssessmentInfo](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iprovidewinsatassessmentinfo)

[Win32_WinSAT](https://learn.microsoft.com/windows/desktop/WinSAT/win32-winsat)