# ISettingsEngine::GetErrorDescription

## Description

Retrieves a text message for a returned HRESULT code.

## Parameters

### `HResult` [in]

The HRESULT code for which this method retrieves the error description.

### `Message` [out]

The text message that corresponds to the HRESULT code.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It may return **E_OUTOFMEMORY** if there are insufficient resources to allocate the string returned in the message.

## See also

[ISettingsEngine](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine)