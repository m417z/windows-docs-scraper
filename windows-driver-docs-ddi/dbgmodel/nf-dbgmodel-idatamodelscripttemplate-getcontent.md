# IDataModelScriptTemplate::GetContent

## Description

The GetContent method returns the content (or code) of the template. This is what would be pre-filled into the edit window if a user elected to create a new script from this template. The template is responsible for creating (and returning) a standard stream over the content that the client can pull.

## Parameters

### `contentStream`

A newly created standard stream over the content (code) for the template. This stream may be backed by memory, a file, or whatever the implementation wishes.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptTemplate interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscripttemplate)