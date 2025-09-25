# IWEInvokeCommand::InvokeCommand

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Allows you to implement procedures that execute when users select your context menu items.

## Parameters

### `nCommandID` [in]

Identifier of the menu item containing the command to perform. The identifier represented by
*nCommandID* is the identifier passed to the
[IWCContextMenuCallback::AddExtensionMenuItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwccontextmenucallback-addextensionmenuitem)
method.

### `piData` [in]

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer for retrieving information associated with the
command identified by *nCommandID*. By calling the
[IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method with the *piData*
pointer, the following interfaces are available:

* [IGetClusterUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusteruiinfo)
* [IGetClusterDataInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterdatainfo)
* [IGetClusterObjectInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterobjectinfo)

Depending on the type of [cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) to
which the context menu item applies, a pointer to one of the following interfaces is also available:

* [IGetClusterNodeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternodeinfo), if the property page
  relates to a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes).
* [IGetClusterGroupInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclustergroupinfo), if the property page
  relates to a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups).
* [IGetClusterNetworkInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternetworkinfo), if the property
  page relates to a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks).
* [IGetClusterNetInterfaceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternetinterfaceinfo), if the
  property page relates to a [network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces).
* [IGetClusterResourceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterresourceinfo), if the property
  page relates to a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources).

## Return value

Returns one of the following values or any **HRESULT** that describes the results of
the operation.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_NOTIMPL**<br><br>0x80004001 | The operation is not implemented by this method. |

## Remarks

To create context menu items and add them to Failover Cluster Administrator, use the
[IWEExtendContextMenu::AddContextMenuItems](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweextendcontextmenu-addcontextmenuitems)
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

[IWCContextMenuCallback::AddExtensionMenuItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwccontextmenucallback-addextensionmenuitem)

[IWEExtendContextMenu::AddContextMenuItems](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweextendcontextmenu-addcontextmenuitems)

[IWEInvokeCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iweinvokecommand)