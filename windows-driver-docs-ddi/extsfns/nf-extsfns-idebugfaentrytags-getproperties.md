# IDebugFAEntryTags::GetProperties

## Description

The **GetProperties** method gets the name or description (or both) of a tag in a [DebugFailureAnalysisTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags) object.

## Parameters

### `Tag`

A value in the [FA_TAG](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze) enumeration. This method gets the name or description (or both) of this tag.

### `Name` [out]

A pointer to a buffer that receives a null-terminated string that is the name of the tag. If *NameSize* is less than the length of the tag's name, this method copies only *NameSize* bytes, including the **NULL** terminator, to this buffer.

### `NameSize` [in, out]

On input, this parameter, specifies the size, in bytes, of the buffer pointed to by *Name*. On output, this parameter receives the size, in bytes, of the name of the tag. If the tag has no name, this parameter receives a value of 0.

**Note** If *Name* is NULL, this parameter receives no information. You should either set both *Name* and *NameSize* to non-NULL values or set them both to **NULL**.

### `Description` [out]

A pointer to a buffer that receives a null-terminated string that is the description of the tag. If *DescSize* is less than the length of the tag's description, this method copies only *DescSize* bytes, including the **NULL** terminator, to this buffer.

### `DescSize` [in, out]

On input, this parameter, specifies the size, in bytes, of the buffer pointed to by *Description*. On output, this parameter receives the size, in bytes, of the description of the tag. If the tag has no description, this parameter receives a value of 0.

**Note** If *Description* is NULL, this parameter receives no information. You should either set both *Description* and *DescSize* to non-NULL values or set them both to **NULL**.

### `Flags` [out]

Reserved. Set this parameter to NULL.

## Return value

The **HRESULT** values returned by this method are defined in winerror.h and strsafe.h. The values returned by this method include, but are not limited to the following:

| Return code | Description |
| --- | --- |
| **S_OK** | This method successfully retrieved the requested name or description (or both), and no truncation of the requested string or strings was required. |
| **STRSAFE_E_INSUFFICIENT_BUFFER** | This method retrieved the requested name or description (or both), but the name or description was truncated. |
| **STRSAFE_E_INVALID_PARAMETER** | The caller passed at least one invalid parameter. |

## See also

[IDebugFAEntryTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[SetProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfaentrytags-setproperties)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)

[_EFN_Analyze](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nc-extsfns-ext_analysis_plugin)