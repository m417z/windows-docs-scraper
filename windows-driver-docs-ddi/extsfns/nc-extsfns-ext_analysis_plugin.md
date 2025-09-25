# EXT_ANALYSIS_PLUGIN callback function

## Description

When you write an [Analysis Extension](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze), you must implement an **EXT_ANALYSIS_PLUGIN** exported as (**_EFN_Analyze**). When the [!analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/-analyze) debugger command runs, it calls your **_EFN_Analyze** in each phase, so that you can participate in the analysis.

The WINAPI (__stdcall) calling convention is required. No exceptions (noexcept) should leave the function.

## Parameters

### `Client` [in]

A pointer to an [IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4) interface. Use this interface to access the debugger. Use QueryInterface to access other Debugger interfaces, such as the Legacy (`IDebug*`), Debug Host (`IDebugHost*`), Data Model (`IDataModel*`), etc., interfaces.

### `CallPhase` [in]

A value in the [FA_EXTENSION_PLUGIN_PHASE](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ne-extsfns-_fa_extension_plugin_phase) enumeration that specifies which phase of the analysis is currently in progress. Analysis phases include initialization, stack analysis, pre-bucketing, and post-bucketing.

### `pAnalysis` [in]

A pointer to a **IDebugFailureAnalysis2** interface. Use this interface to Get/Set properties of the analysis. Use QueryInterface to access other !analyze interfaces.

## Return value

**S_OK** – A change was made.

**S_FALSE** – No changes were made.

**E_*** - An error occurred. !analyze will report the error via Key/Value using a Key string of `Plugin.Exception."Phase"."DLL"` and Value string of the HRESULT in “0x%08x” format.

## See also

[Writing Custom Analysis Debugger Extension](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-custom-analysis-debugger-extensions)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)