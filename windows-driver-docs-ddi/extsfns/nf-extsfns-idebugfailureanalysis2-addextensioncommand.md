# IDebugFailureAnalysis2::AddExtensionCommand

## Description

The **AddExtensionCommand** method adds a new [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) to a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object and sets the data block of the FA entry to a specified debugger command.

## Parameters

### `Tag`

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration. The data type associated with this tag must be **DEBUG_FA_ENTRY_EXTENSION_CMD** or **DEBUG_FA_ENTRY_ANSI_STRING**.

### `Extension` [in]

A pointer to a null-terminated ANSI string that is the debugger command. An example of debugger command is "!analyze -v".

## Return value

If this method succeeds, it returns a returns a pointer to the new [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure. If this method fails, it returns **NULL**.

## Remarks

This method sets the **DataSize** member of the new [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure to the length, in bytes, of the extension command including the **NULL** terminator.

Each tag is associated with one of the data types in the [FA_ENTRY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ne-extsfns-_fa_entry_type) enumeration. To determine the data type associated with a tag, call the [GetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfaentrytags-gettype) method of the [IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) interface.

To get a pointer to an [IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) interface, call the [GetDebugFATagControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-getdebugfatagcontrol) method of the [IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) interface.

[sperry] Note to Self: If the given tag has not already had its data type fixed, this method sets and fixes the data type for the tag. That would be the case if the DebugFailureAnalysis object does not yet have an FA entry with this tag. But if the DebugFailureAnalysis object already has an FA entry with this tag, then the data type of the tag is fixed. This method creates a new FA entry with the same tag. Now what if the data type that we're trying to write into the new data buffer does not match the data type that has been fixed for this tag. Then we see whether it's OK to cast from the fixed data type to the type we want to write.

It's OK to cast among ULONG64, POINTER, and InstructionOffset. It's OK to cast among String and ExtensionCommand. ULONG can only be ULONG. STRINGs can only be STRINGs.

Question: When does the data type of a tag get fixed? Is it when the first FA entry with that tag is created?

```cpp
typedef struct _FA_TAG_PROPS
{
    FA_TAG Tag;
    FA_ENTRY_TYPE Type;
    ULONG Fixed:1;
    ULONG NameAllocated:1;
    ULONG DescriptionAllocated:1;
    PCSTR Name;
    PCSTR Description;
    AnalysisPlugIn *Plugin;
} FA_TAG_PROPS, *PFA_TAG_PROPS;
```

## See also

[IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[SetExtensionCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-setextensioncommand)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)