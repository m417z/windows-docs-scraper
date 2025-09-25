# IDebugFailureAnalysis2::AddString

## Description

The **AddString** method adds a new [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) to a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object and sets the data block of the FA entry to a specified string.

## Parameters

### `Tag`

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration. The data type associated with this tag must be **DEBUG_FA_ENTRY_ANSI_STRING**.

### `Str` [in]

A pointer to a null-terminated ANSI string to be written to the data block of the new [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries).

## Return value

If this method succeeds, it returns a returns a pointer to the new [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure. If this method fails, it returns **NULL**.

## Remarks

This method sets the **DataSize** member of the new [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure to the length, in bytes, of the string including the **NULL** terminator.

Each tag is associated with one of the data types in the [FA_ENTRY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ne-extsfns-_fa_entry_type) enumeration. To determine the data type associated with a tag, call the [GetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfaentrytags-gettype) method of the [IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) interface.

To get a pointer to an [IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) interface, call the [GetDebugFATagControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-getdebugfatagcontrol) method of the [IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) interface.

## See also

[IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[SetString](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-setstring)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)