# WcmSettingType enumeration

## Description

Describes setting types that are returned from the [ISettingsItem::GetSettingType](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getsettingtype) method and defines the object model type for the calling [ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem) interface.

## Constants

### `settingTypeScalar:1`

For items of this type, you can call the [ISettingsItem::GetDataType](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getdatatype), [ISettingsItem::GetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getvalue), [ISettingsItem::GetValueRaw](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getvalueraw), [ISettingsItem::GetRestriction](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getrestriction), [ISettingsItem::GetRestrictionFacets](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getrestrictionfacets), [ISettingsItem::SetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-setvalue), and [ISettingsItem::SetValueRaw](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-setvalueraw) methods.

### `settingTypeComplex:2`

Items of this type may have children. You may call the [ISettingsItem::Children](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-children), [ISettingsItem::GetChild](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getchild), or [ISettingsItem::HasChild](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-haschild) methods on this setting type.

### `settingTypeList:3`

Items of this type may have children. You may call the [ISettingsItem::Children](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-children), [ISettingsItem::GetChild](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getchild), or [ISettingsItem::HasChild](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-haschild) methods on this setting type. You can also call the [ISettingsItem::CreateListElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-createlistelement) and [ISettingsItem::RemoveListElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-removelistelement) methods on children of items of this type.

## Remarks

**Note** All methods of the [ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem) interface, other than the ones that are explicitly described for a particular type, may be called on any type of setting.