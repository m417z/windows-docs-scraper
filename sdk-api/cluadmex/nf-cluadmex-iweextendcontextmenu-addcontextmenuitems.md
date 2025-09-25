# IWEExtendContextMenu::AddContextMenuItems

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Allows you to create context menu items for a cluster object and add the items to a
[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) context menu.

## Parameters

### `piData` [in]

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer for retrieving information relating to the new menu
item. By calling the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method with the
*piData* pointer, the following interfaces are available:

* [IGetClusterUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusteruiinfo)
* [IGetClusterDataInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterdatainfo)
* [IGetClusterObjectInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterobjectinfo)

Depending on the type of [cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) for
which the context menu is being created, one of the following interfaces may also be available:

* [IGetClusterNodeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternodeinfo), if the menu item
  relates to a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes).
* [IGetClusterGroupInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclustergroupinfo), if the menu item
  relates to a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups).
* [IGetClusterNetworkInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternetworkinfo), if the menu item
  relates to a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks).
* [IGetClusterNetInterfaceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternetinterfaceinfo), if the
  menu item relates to a [network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces).
* [IGetClusterResourceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterresourceinfo), if the menu
  item relates to a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources).

### `piCallback` [in]

Pointer to an [IWCContextMenuCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwccontextmenucallback)
interface implementation for adding new items to the Cluster Administrator context menu.

## Return value

Return one of the following values or any **HRESULT** that describes the results of
the operation.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057 | At least one of the parameters is invalid. |
| **E_NOTIMPL**<br><br>0x80004001 | The extension does not support adding context menu items. |

## Remarks

**To implement AddContextMenuItems**

1. Call the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method pointed to by
   *piData* to retrieve a pointer to an interface that can provide information about the
   object associated with the menu item.
2. Call the
   [IWCContextMenuCallback::AddExtensionMenuItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwccontextmenucallback-addextensionmenuitem)
   method using the *piCallback* pointer to add the item to the menu.

To add context menu items and to implement code that executes when your context menu items are selected,
implement the
[IWEInvokeCommand::InvokeCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweinvokecommand-invokecommand)
method.

## See also

[IGetClusterDataInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterdatainfo)

[IGetClusterGroupInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclustergroupinfo)

[IGetClusterNetInterfaceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternetinterfaceinfo)

[IGetClusterNetworkInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternetworkinfo)

[IGetClusterNodeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternodeinfo)

[IGetClusterObjectInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterobjectinfo)

[IGetClusterResourceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterresourceinfo)

[IGetClusterUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusteruiinfo)

[IWCContextMenuCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwccontextmenucallback)

[IWCContextMenuCallback::AddExtensionMenuItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwccontextmenucallback-addextensionmenuitem)

[IWEExtendContextMenu](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iweextendcontextmenu)

[IWEInvokeCommand::InvokeCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweinvokecommand-invokecommand)