# ISnapinHelp2::GetLinkedTopics

## Description

The **ISnapinHelp2::GetLinkedTopics** method enables a snap-in to specify the names and locations of any HTML Help files that are linked to the snap-in's Help file (specified in the
[GetHelpTopic](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-isnapinhelp-gethelptopic) method).

## Parameters

### `lpCompiledHelpFiles` [out]

A pointer to the address of the null-terminated Unicode string that contains the path of one or more compiled Help files (.chm) that are linked to the snap-in's Help file. A semicolon is used to separate multiple file paths from each other.

When specifying the path, place the file anywhere and specify the full path name.

## Return value

This method can return one of these values.

## Remarks

MMC calls the snap-in's **ISnapinHelp2::GetLinkedTopics** method only if the snap-in returned **S_OK** from the
[ISnapinHelp2::GetHelpTopic](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814944(v=vs.85)) method call.

Allocate the *lpCompiledHelpFiles* string with the COM API function [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) (or the equivalent) and MMC will release it

## See also

[Adding HTML Help Support](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-html-help-support)

[ISnapinHelp2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-isnapinhelp2)

[ISnapinHelp2::GetHelpTopic](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814944(v=vs.85))