# IDebugFailureAnalysis2::GetFailureClass

## Description

The **GetFailureClass** method gets the failure class of a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object. The failure class indicates whether the debugging session that created the **DebugFailureAnalysis** object is a kernel mode session or a user mode session.

## Return value

| Return code/value | Description |
| --- | --- |
| **DEBUG_CLASS_UNINITIALIZED**<br><br>0 | The debug class has not been initialized. |
| **DEBUG_CLASS_KERNEL**<br><br>1 | The debugging session is a kernel-mode session. |
| **DEBUG_CLASS_USER_WINDOWS**<br><br>2 | The debugging session is a user-mode session. |

These return values are defined in dbgeng.h.

## See also

[GetFailureCode](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-getfailurecode)

[GetFailureType](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-getfailuretype)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)