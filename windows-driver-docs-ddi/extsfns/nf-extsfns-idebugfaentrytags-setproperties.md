# IDebugFAEntryTags::SetProperties

## Description

The **SetProperties** method sets the name or description (or both) of a tag in a [DebugFailureAnalysisTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) object.

## Parameters

### `Tag` [in]

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration. This method sets the name or description (or both) of this tag.

### `Name` [in]

A pointer to a null-terminated string that specifies the name to be set. If the tag already has a name, this method overwrites the old name. If this parameter is **NULL**, the name of the tag is not changed.

### `Description` [in]

A pointer to a null-terminated string that specifies the description to be set. If the tag already has a description, this method overwrites the old description. If this parameter is **NULL**, the description of the tag is not changed.

### `Flags` [in]

Reserved. Set this parameter to **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise it returns an error code. Error codes are defined in winerror.h and strsafe.h.

## See also

[GetProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfaentrytags-getproperties)

[IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)