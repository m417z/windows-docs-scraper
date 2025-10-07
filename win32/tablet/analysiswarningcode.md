# AnalysisWarningCode enumeration

Specifies the set of available warnings that can occur during ink analysis.

## Constants

**AnalysisWarningCode\_Aborted**

The analysis operation was aborted.

Returned only when the synchronous analysis operation is called. Aborting an asynchronous operation will not raise an [**\_IAnalysisEvents::Results**](https://learn.microsoft.com/windows/win32/tablet/-ianalysisevents-results) event.

**AnalysisWarningCode\_NoMatchingInkAnalysisRecognizerFound**

The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) cannot find an ink recognizer that meets language or capability requirements needed to perform the analysis operation.

**AnalysisWarningCode\_FactoidNotSupported**

The ink recognizer was unable to respect the specified factoid set on the analysis hint node (see [**IContextNode::GetType**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-gettype) and [Analysis Hint Properties](https://learn.microsoft.com/windows/win32/tablet/analysis-hint-properties)).

**AnalysisWarningCode\_FactoidCoercionNotSupported**

The ink recognizer was unable to coerce its results to the specified factoid set on the analysis hint node (see [**IContextNode::GetType**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-gettype) and [Analysis Hint Properties](https://learn.microsoft.com/windows/win32/tablet/analysis-hint-properties)).

**AnalysisWarningCode\_GuideNotSupported**

The ink recognizer was unable to respect the specified guide set on the analysis hint node (see [**IContextNode::GetType**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-gettype) and [Analysis Hint Properties](https://learn.microsoft.com/windows/win32/tablet/analysis-hint-properties)).

**AnalysisWarningCode\_WordlistNotSupported**

The ink recognizer was unable to respect the specified word list set on the analysis hint node (see [**IContextNode::GetType**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-gettype) and [Analysis Hint Properties](https://learn.microsoft.com/windows/win32/tablet/analysis-hint-properties)).

**AnalysisWarningCode\_WordModeNotSupported**

The ink recognizer was unable to respect the specified word mode set on the analysis hint node (see [**IContextNode::GetType**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-gettype) and [Analysis Hint Properties](https://learn.microsoft.com/windows/win32/tablet/analysis-hint-properties)).

**AnalysisWarningCode\_PartialDictionaryTermsNotSupported**

Indicates that partial dictionary terms could not be returned from the [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer).

**AnalysisWarningCode\_TextRecognitionProcessFailed**

Indicates the text recognition process failed.

**AnalysisWarningCode\_AddInkToRecognizerFailed**

The ink could not be added to the [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer). For example, adding strokes collected from a mouse on a gesture recognizer will fail, as the gesture recognizer requires strokes collected from a digitizer.

**AnalysisWarningCode\_SetPrefixSuffixFailed**

The [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer) was unable to respect the specified prefix or suffix text of an analysis hint node (see [**IContextNode::GetType**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-gettype) and [Analysis Hint Properties](https://learn.microsoft.com/windows/win32/tablet/analysis-hint-properties)).

**AnalysisWarningCode\_InkAnalysisRecognizerInitializationFailed**

The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) was not able to instantiate, clone, or set strokes on the [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer).

**AnalysisWarningCode\_ConfirmedWithoutInkRecognition**

Indicates that an [**IContextNode**](https://learn.microsoft.com/windows/win32/tablet/icontextnode) object has been confirmed by the user without having any recognition values computed for the node.

**AnalysisWarningCode\_BackgroundException**

The background operation did not complete due to an exception. This is a fatal error and requires that the [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) is re-instantiated before further use.

**AnalysisWarningCode\_ContextNodeLocationNotSet**

Indicates that an [**IContextNode**](https://learn.microsoft.com/windows/win32/tablet/icontextnode) object does not have a proper location set (see [**IContextNode::SetLocation**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-setlocation)). The [**IContextNode::GetLocation**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-getlocation) method must return a non-empty value unless the **IContextNode** object is marked as partially populated.

**AnalysisWarningCode\_LanguageIdNotRespected**

The language identifier set on a stroke associated with a custom recognizer node (see [**IContextNode::GetType**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-gettype)) did not match the language identifier of the [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer) used. The ink was still recognized with the specified **IInkAnalysisRecognizer**.

**AnalysisWarningCode\_EnableUnicodeCharacterRangesNotSupported**

The [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer) does not support enabling Unicode character ranges as specified.

**AnalysisWarningCode\_TopInkBreaksOnlyNotSupported**

The [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer) does not support TopInkBreaks only even though the hints contained the request for TopInkBreaks only.

**AnalysisWarningCode\_AnalysisAlreadyRunning**

The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) is already performing background analysis.

## Remarks

**AnalysisWarningCode\_BackgroundException** is the only warning code value that requires that the [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) object is re-instantiated before further use.

Other warnings code values, such as **AnalysisWarningCode\_InkAnalysisRecognizerInitializationFailed** and **AnalysisWarningCode\_NoMatchingInkAnalysisRecognizerFound**, might require that the [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) object use a different recognizer.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Header<br> | IACom.h (also requires IACom\_i.c) |

## See also

[**IAnalysisWarning::GetWarningCode**](https://learn.microsoft.com/windows/win32/tablet/ianalysiswarning-getwarningcode)

[Ink Analysis Reference](https://learn.microsoft.com/windows/win32/tablet/ink-analysis-reference)

