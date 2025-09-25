# IWEExtendPropertySheet::CreatePropertySheetPages

## Description

Creates property pages for a [cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and
adds them to a [Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator)
property sheet.

## Parameters

### `piData` [in]

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer for retrieving information relating to the new
property pages. By calling the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method with the
*piData* pointer, the following interfaces are available:

* [IGetClusterUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusteruiinfo)
* [IGetClusterDataInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterdatainfo)
* [IGetClusterObjectInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterobjectinfo)

Depending on the type of [cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) for
which property sheet pages are being created, a pointer to one of the following interfaces is also
available:

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

### `piCallback` [in]

Pointer to an [IWCPropertySheetCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwcpropertysheetcallback)
interface implementation for adding property pages to the Cluster Administrator property sheet.

## Return value

Return one of the following values or any **HRESULT** that describes the results of
the operation.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057 | At least one of the parameters is invalid. |
| **E_NOTIMPL**<br><br>0x80004001 | The extension does not support adding property pages. |

## Remarks

[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) calls
an extension's
**CreatePropertySheetPages**
method to extend a property sheet to handle an additional
[cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects).

### Notes to Implementers

**For each property page to be added**

1. Use *piData* to call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) and retrieve an
   interface pointer for the cluster object associated with the page. For example, if you are adding a property
   page for a resource, you want to retrieve a pointer to the
   [IGetClusterResourceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterresourceinfo) interface.
   Although it is possible to successfully query for interfaces that retrieve data unrelated to the target object,
   you should expect to receive errors when you attempt to call the methods.
2. To create the page, call the function
   [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea). To produce pages
   that look like the pages provided by Cluster Administrator, each new property page should be no larger than 252
   dialog units wide and 218 dialog units high, and should contain two standard controls:

   * For the object icon, an icon control positioned at (8,7) with a size of (18,20).
   * For the object name, a static control positioned at (38,12) with a size of (206,10).
3. To add the page to the property sheet, call the
   [IWCPropertySheetCallback::AddPropertySheetPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwcpropertysheetcallback-addpropertysheetpage)
   method pointed to by *piCallback*.

## See also

[IGetClusterDataInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterdatainfo)

[IGetClusterGroupInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclustergroupinfo)

[IGetClusterNetInterfaceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternetinterfaceinfo)

[IGetClusterNetworkInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternetworkinfo)

[IGetClusterNodeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternodeinfo)

[IGetClusterObjectInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterobjectinfo)

[IGetClusterResourceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterresourceinfo)

[IGetClusterUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusteruiinfo)

[IWCPropertySheetCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwcpropertysheetcallback)

[IWCPropertySheetCallback::AddPropertySheetPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwcpropertysheetcallback-addpropertysheetpage)

[IWEExtendPropertySheet](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iweextendpropertysheet)