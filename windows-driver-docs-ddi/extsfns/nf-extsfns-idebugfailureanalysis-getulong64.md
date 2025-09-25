# IDebugFailureAnalysis::GetUlong64

## Description

The **GetUlong64** method searches a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object for the first [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) that has a specified tag. If it finds an FA entry with the specified tag, it gets the **ULONG64** value from the entry's data block.

## Parameters

### `Tag`

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration.

### `Value` [out]

A pointer to a **ULONG64** that receives the value from the entry's data block.

## Return value

If this method finds an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) with the specified tag, and if it succeeds in getting the data block, it returns a pointer to the [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure. Otherwise, it returns **NULL**.

## Remarks

If this method finds an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) with the specified tag, it checks to see whether the **DataSize** member of the [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure is equal to the size of a **ULONG64**. If **DataSize** is not equal to the size of a **ULONG64**, this method returns **NULL** and does not get the data block.

Each tag that has already been used in a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object is associated with one of the data types in the [FA_ENTRY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ne-extsfns-_fa_entry_type) enumeration. To determine the data type associated with a tag, call the [GetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfaentrytags-gettype) method of the [IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) interface. To get a pointer to an IDebugFAEntryTags interface, call the [GetDebugFATagControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-getdebugfatagcontrol) method of the **IDebugFailureAnalysis2** interface.

The appropriate use of this method is get the data block from an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) that has a data type of **DEBUG_FA_ENTRY_ULONG64** or **DEBUG_FA_ENTRY_INSTRUCTION_OFFSET** or **DEBUG_FA_ENTRY_POINTER**.

## See also

[AddUlong64](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-addulong64)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[SetUlong64](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-setulong64)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)