# IDebugFailureAnalysis2::GetFailureCode

## Description

The **GetFailureCode** method gets the bug check code or exception code of a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object.

## Return value

This method returns a [bug check code](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2) or an [exception code](https://learn.microsoft.com/windows/win32/debug/structured-exception-handling).

## Remarks

When the [!analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/-analyze) debugger command runs in response to a code failure, the analysis engine creates a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object to store data that describes and categorizes the failure. If the failure being analyzed is a bug check, this method returns a bug check code. If the failure being analyzed is an exception, this method returns an exception code.

## See also

[GetFailureClass](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-getfailureclass)

[GetFailureType](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-getfailuretype)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)