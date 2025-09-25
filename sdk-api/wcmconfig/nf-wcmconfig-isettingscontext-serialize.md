# ISettingsContext::Serialize

## Description

Serializes the data in this context into the provided stream.

## Parameters

### `pStream` [in]

The stream into which the XML, produced by the method, is inserted.

### `pTarget` [in]

Defines the parameters of the image against which the context must be serialized. This should match the target used while constructing the context.

## Return value

This method returns an HRESULT value. **S_OK** indicates success.

## See also

[ISettingsContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingscontext)