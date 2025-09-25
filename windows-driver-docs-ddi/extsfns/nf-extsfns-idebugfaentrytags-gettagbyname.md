# IDebugFAEntryTags::GetTagByName

## Description

The **GetTagByName** method searches for a tag that has a specified name.

## Parameters

### `PluginId` [in]

A pointer to a null-terminated string that specifies the identifier of an analysis extension plug-in. This parameter can be **NULL**.

### `TagName` [in]

A pointer to a null-terminated string that specifies the name to search for.

### `Tag` [out]

A pointer to a variable that receives either a value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration or the value of a custom tag. If this method does not find a tag that has the specified name, nothing is written to this parameter.

## Return value

If this method finds a tag that has the specified name, it returns **S_OK**. Otherwise it returns a failure code.

## Remarks

A [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object has a collection of [FA entries](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries), each of which has a tag. A **DebugFailureAnalysis** object is associated with a [DebugFailureAnalysisTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags), which contains a collection of tag properties. Also, the analysis engine has a global tag table. For more information, see [Failure Analysis Entries, Tags, and Data Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze).

If you specify a *PluginId*, this method does the following:

* In the [DebugFailureAnalysisTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) object, search the collection of tag properties for a tag whose name matches *TagName* and whose plug-in id matches the *PluginId*. Note that this limits the search to custom tags created by the analysis extension plug-in identified by *PluginId*. If a match is found, return the tag in the *Tag* output parameter.
* If a match is not found in the [DebugFailureAnalysisTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) object, search the global tag table for a tag whose name matches *TagName*. If a matching name is found, add the found tag to the **DebugFailureAnalysisTags** collection of tag properties, and return the tag in the *Tag* output parameter.
* If a match is not found in the global tag table, write nothing to the *Tag* output parameter, and return a failure code.

If you call this method from an analysis extension plug-in, and you set *PluginId* to **NULL**, this method uses the plug-in identifier of the current plug-in. Then it behaves the same way that it does when a non-NULL *PluginId* is specified.

## See also

[IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Metadata Files for Analysis Extension Plug-ins](https://learn.microsoft.com/windows-hardware/drivers/debugger/metadata-files-for-analysis-extensions)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)