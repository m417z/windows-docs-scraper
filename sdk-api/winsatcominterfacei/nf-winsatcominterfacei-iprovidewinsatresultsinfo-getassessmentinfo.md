# IProvideWinSATResultsInfo::GetAssessmentInfo

## Description

[IProvideWinSATResultsInfo::GetAssessmentInfo may be altered or unavailable for releases after Windows 8.1.]

Retrieves summary information for a subcomponent of the assessment.

## Parameters

### `assessment` [in]

A subcomponent of the assessment whose summary information you want to retrieve. For possible values, see the [WINSAT_ASSESSMENT_TYPE](https://learn.microsoft.com/windows/win32/api/winsatcominterfacei/ne-winsatcominterfacei-winsat_assessment_type) enumeration.

### `ppinfo` [out]

An [IProvideWinSATAssessmentInfo](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iprovidewinsatassessmentinfo) interface that you use to get the score for the subcomponent.

## Return value

Returns S_OK if successful.

## See also

[IProvideWinSATResultsInfo](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iprovidewinsatresultsinfo)