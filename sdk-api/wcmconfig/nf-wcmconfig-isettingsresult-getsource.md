# ISettingsResult::GetSource

## Description

Returns the file or path where the error has occurred.

## Parameters

### `file` [out]

The file or path where the error has occurred.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It may return **E_OUTOFMEMORY** if there are insufficient resources to return information to the user.

## See also

[ISettingsResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsresult)