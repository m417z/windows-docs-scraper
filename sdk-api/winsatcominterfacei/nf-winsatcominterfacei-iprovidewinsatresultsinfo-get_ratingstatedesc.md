# IProvideWinSATResultsInfo::get_RatingStateDesc

## Description

[IProvideWinSATResultsInfo::RatingStateDesc may be altered or unavailable for releases after Windows 8.1.]

Retrieves a string that you can use in a UI to indicate whether the assessment is valid.

This property is read-only.

## Parameters

## Remarks

If the assessment is valid, the string is "Windows Experience Index"; otherwise, the string is "Windows Experience Index : Unrated". To determine the validity of the assessment, call the [IProvideWinSATResultsInfo::get_AssessmentState](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iprovidewinsatresultsinfo-get_assessmentstate) method.

## See also

[IProvideWinSATResultsInfo](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iprovidewinsatresultsinfo)

[IProvideWinSATResultsInfo::AssessmentState](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iprovidewinsatresultsinfo-get_assessmentstate)