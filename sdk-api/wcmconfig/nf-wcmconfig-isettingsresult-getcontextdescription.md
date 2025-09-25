# ISettingsResult::GetContextDescription

## Description

Returns the description of the context that surrounds the error.

## Parameters

### `description` [out]

The text that describes the context.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It may return **E_OUTOFMEMORY** if there are insufficient resources to return information to the user.

## See also

[ISettingsResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsresult)