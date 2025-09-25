# IProvideWinSATResultsInfo::get_SystemRating

## Description

[IProvideWinSATResultsInfo::SystemRating may be altered or unavailable for releases after Windows 8.1.]

Retrieves the base score for the computer.

This property is read-only.

## Parameters

## Remarks

The Windows Experience Index feature measures the capability of your computer's hardware configuration and expresses this measurement as a number called a base score. A higher base score generally means that your computer will perform better and faster than a computer with a lower base score, especially when performing more advanced and resource-intensive tasks.

Each hardware component receives an individual subscore. Your computer's base score is determined by the lowest subscore. For example, if the lowest subscore of an individual hardware component is 2.6, then the base score is 2.6. The base score is not an average of the combined subscores.

You can use the base score to confidently buy programs and other software that are matched to your computer's base score. For example, if your computer has a base score of 3.3, then you can confidently purchase any software designed for this version of Windows that requires a computer with a base score of 3 or lower.

To get the score for a subcomponent of the assessment, such as the CPU, call the [IProvideWinSATAssessmentInfo::get_Score](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iprovidewinsatassessmentinfo-get_score) method.

#### Examples

For an example, see the [IQueryRecentWinSATAssessment::Info](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iqueryrecentwinsatassessment-get_info) property.

## See also

[IProvideWinSATResultsInfo](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iprovidewinsatresultsinfo)

[Win32_WinSAT](https://learn.microsoft.com/windows/desktop/WinSAT/win32-winsat)