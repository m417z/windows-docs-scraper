# IWEExtendWizard97::CreateWizard97Pages

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Allows you to create Wizard97 property pages and add them to a
[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) Wizard.

## Parameters

### `piData` [in]

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer for retrieving information
relating to the wizard97 pages to be added. By calling
[IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) with the
*piData* pointer, the following interfaces are available:

* [IGetClusterUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusteruiinfo)
* [IGetClusterDataInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterdatainfo)
* [IGetClusterObjectInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterobjectinfo)

Depending on the type of [cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly), a
pointer to one of the following interfaces is also available:

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

Pointer to an [IWCWizard97Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwcwizard97callback) interface
implementation used to add the new Wizard97 property pages to the wizard.

## Return value

Return one of the following values or any **HRESULT** that describes the results of
the operation.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057 | At least one of the parameters is invalid. |
| **E_NOTIMPL**<br><br>0x80004001 | The extension does not support adding Wizard97 pages. |

## Remarks

### Notes to Implementers

If your extension has no Wizard97 pages but does have non-Wizard97 pages, you can either:

* Support only the [IWEExtendWizard](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iweextendwizard) interface.
* Support both the [IWEExtendWizard](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iweextendwizard) and
  [IWEExtendWizard97](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iweextendwizard97) interfaces, but in your
  implementation of **IWEExtendWizard97**, query for the
  [IWCWizardCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwcwizardcallback) interface from the interface
  passed in by way of the *piCallback* parameter.

**For each Wizard97 property page to be added**

1. Use *piData* to call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) and retrieve an
   interface pointer for the [object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) associated with the new
   page. For example, if you are adding a property page for a resource, you want to retrieve a pointer to the
   [IGetClusterResourceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterresourceinfo) interface.
   Although it is possible to successfully query for interfaces that retrieve data unrelated to the object being
   extended, you should expect to receive errors when you attempt to call the methods.
2. To create the page, call the function
   [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea). To produce pages
   that look like the pages provided by Cluster Administrator, each new wizard97 page should be no larger than 293
   dialog units wide and 172 dialog units high, and should contain a static control positioned at (38,12) with a
   size of (247,10).
3. To add the page to a Cluster Administrator Wizard, call
   [IWCWizard97Callback::AddWizard97Page](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwcwizard97callback-addwizard97page)
   using the *piCallback* pointer.

## See also

[CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea)

[IGetClusterDataInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterdatainfo)

[IGetClusterGroupInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclustergroupinfo)

[IGetClusterNetInterfaceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternetinterfaceinfo)

[IGetClusterNetworkInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternetworkinfo)

[IGetClusterNodeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusternodeinfo)

[IGetClusterObjectInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterobjectinfo)

[IGetClusterResourceInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterresourceinfo)

[IGetClusterUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusteruiinfo)

[IWCPropertySheetCallback::AddPropertySheetPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwcpropertysheetcallback-addpropertysheetpage)

[IWCWizardCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwcwizardcallback)

[IWEExtendWizard](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iweextendwizard)

[IWEExtendWizard97](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iweextendwizard97)