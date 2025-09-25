# IEnumPublishedApps::Next

## Description

Gets the next [IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp) object in the enumeration.

## Parameters

### `pia` [out]

Type: **[IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp)****

A pointer to an [IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp) interface reference variable that returns the next application object. Note that the category of the application object returned must match that passed into [EnumApps](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-iapppublisher-enumapps).

## Return value

Type: **HRESULT**

Returns S_OK if an item is returned, S_FALSE if there are no more items to enumerate, a COM-defined error value otherwise.

## Remarks

**Note** [IEnumPublishedApps](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ienumpublishedapps) is not a standard enumeration interface. It does not support a Skip method, nor does its Next method support retrieval of multiple items.

## See also

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)

[IEnumPublishedApps](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ienumpublishedapps)

[IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp)