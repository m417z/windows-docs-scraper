# IEnumPublishedApps::Reset

## Description

Resets the enumeration of [IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp) objects to the first item.

## Return value

Type: **HRESULT**

Returns the following value.

| Return code | Description |
| --- | --- |
| **S_OK** | This method only returns S_OK. |

## Remarks

**Note** [IEnumPublishedApps](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ienumpublishedapps) is not a standard enumeration interface.

It does not support a Skip method nor does its Next method support retrieval of multiple items.

## See also

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)

[IEnumPublishedApps](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ienumpublishedapps)

[IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp)