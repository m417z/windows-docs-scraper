# ISettingsEngine::CreateTargetInfo

## Description

Creates an empty target.

## Parameters

### `Target` [out]

An [ITargetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-itargetinfo) interface pointer to an empty target.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It may return **E_OUTOFMEMORY** if there are insufficient resources to create an ITargetInfo object.

## See also

[ISettingsEngine](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsengine)