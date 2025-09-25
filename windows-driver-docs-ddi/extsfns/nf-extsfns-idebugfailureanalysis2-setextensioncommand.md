# IDebugFailureAnalysis2::SetExtensionCommand

## Description

The **SetExtensionCommand** method searches a [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object for the first [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) that has a specified tag. If it finds an FA entry with the specified tag, it sets (overwrites) the data block of the FA entry to a specified extension command string. If this method does not find an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) that has the specified tag, it creates a new FA entry with that tag and sets the data block of the new FA entry to the specified extension command string.

## Parameters

### `Tag`

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration.

### `Extension`

A pointer to a null-terminated string that is the extension command. An example of an extension command is "!analyze -v".

## Return value

If this method succeeds, it returns a pointer to the new or existing [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure. Otherwise, it returns **NULL**.

## Remarks

If this method finds an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) with the specified tag, it checks to see whether the data type associated with that tag is **DEBUG_FA_ENTRY_EXTENSION_CMD** or **DEBUG_FA_ENTRY_ANSI_STRING**. If the data type associated with the tag does not have one of those two values, this method returns **NULL** and does not overwrite the entry's data block.

If this method does not find an [FA entry](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) with the specified tag, it creates a new FA entry with that tag, and it associates the tag with the data type **DEBUG_FA_ENTRY_EXTENSION_CMD**.

## See also

[AddExtensionCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis2-addextensioncommand)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)