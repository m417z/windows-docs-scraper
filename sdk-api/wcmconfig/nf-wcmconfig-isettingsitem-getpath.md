# ISettingsItem::GetPath

## Description

Gets the path for the item.

## Parameters

### `Path` [out]

The path to the current setting. This path should be handled as opaque, and should be used only for invocations of [CreateSettingByPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-createsettingbypath), [GetSettingByPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getsettingbypath), or [RemoveSettingByPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-removesettingbypath).

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It may return **E_OUTOFMEMORY** if there are insufficient resources.

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)