# AnalysisModes enumeration

Specifies how the [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) performs ink analysis.

## Constants

**AnalysisModes\_None**

No modes are specified.

**AnalysisModes\_AutomaticReconciliation**

Whether the [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) automatically starts the reconciliation operation as soon as the intermediate or final results are ready.

If this mode is enabled, the [**\_IAnalysisEvents::ReadyToReconcile**](https://learn.microsoft.com/windows/win32/tablet/-ianalysisevents-readytoreconcile) event is not raised. If this mode is disabled, the **\_IAnalysisEvents::ReadyToReconcile** event is raised.

**AnalysisModes\_StrokeCacheAutoCleanup**

Whether the [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) automatically clears unneeded strokes from the stroke cache before performing analysis.

If this mode is enabled, the [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) clears the stroke data before performing analysis. Your code must also then handle the [**\_IAnalysisEvents::UpdateStrokesCache**](https://learn.microsoft.com/windows/win32/tablet/-ianalysisevents-updatestrokescache) event. If the **\_IAnalysisEvents::UpdateStrokesCache** event is not handled, an exception is raised. This check is done both at the Analyze (or BackgroundAnalyze) and Reconciliation phases.

If this mode is disabled, the [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) does not clear the stroke data. To clear the stroke data, call [**IInkAnalyzer::ClearStrokeData Method**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer-clearstrokedata). If this mode is disabled, the [**\_IAnalysisEvents::UpdateStrokesCache**](https://learn.microsoft.com/windows/win32/tablet/-ianalysisevents-updatestrokescache) event is raised so the **IInkAnalyzer** can retrieve the latest stroke data for any strokes that have had their cache cleared. If the stroke cache is cleared, but the **\_IAnalysisEvents::UpdateStrokesCache** event is not handled, an exception is raised.

**AnalysisModes\_PersonalizationEnabled**

Personalization of handwriting recognition is enabled.

**AnalysisModes\_Default**

All modes are enabled.

## Remarks

This enumeration allows a bitwise combination of its member values.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Header<br> | IACom.h (also requires IACom\_i.c) |

## See also

[**IInkAnalyzer::GetAnalysisModes Method**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer-getanalysismodes)

[**IInkAnalyzer::SetAnalysisModes Method**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer-setanalysismodes)

[**\_IAnalysisEvents::IntermediateResults**](https://learn.microsoft.com/windows/win32/tablet/-ianalysisevents-intermediateresults)

[**\_IAnalysisEvents::ReadyToReconcile**](https://learn.microsoft.com/windows/win32/tablet/-ianalysisevents-readytoreconcile)

[**\_IAnalysisEvents::UpdateStrokesCache**](https://learn.microsoft.com/windows/win32/tablet/-ianalysisevents-updatestrokescache)

[Ink Analysis Reference](https://learn.microsoft.com/windows/win32/tablet/ink-analysis-reference)

