# WIA_PROPID_TO_NAME structure

## Description

Provides a quick means by which applications can look up the standard Windows Image Acquisition (WIA) property name from the WIA property ID (or vice versa). If the **propid** does not exist in this array, it is likely not a standard WIA property. Other ways to get the property name from the property ID include using the **IEnumSTATPROPSTG** retrieved by calling [IWiaPropertyStorage::Enum](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiapropertystorage) on a particular item.

## Members

### `propid`

Type: **PROPID**

WIA property ID.

### `pszName`

Type: **LPOLESTR**

WIA property name.

**Note** Property names are not localized. They are primarily used to support scripting languages; therefore, they are always the same on any system.