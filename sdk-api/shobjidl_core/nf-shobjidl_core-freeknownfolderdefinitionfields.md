# FreeKnownFolderDefinitionFields function

## Description

Frees the allocated fields in the result from [IKnownFolder::GetFolderDefinition](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-getfolderdefinition).

## Parameters

### `pKFD` [in]

Type: **[KNOWNFOLDER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-knownfolder_definition)***

A pointer to a [KNOWNFOLDER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-knownfolder_definition) structure that contains information about the given known folder.

## Remarks

This is an inline helper function that calls [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) on the fields in the structure that need to be freed. Its implementation can be seen in the header file.

## See also

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))