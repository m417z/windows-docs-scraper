# IWCWizard97Callback::AddWizard97Page

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Adds a Wizard97 property page to a Wizard97 wizard, such as the Failover Cluster Application Wizard.

## Parameters

### `hpage` [in]

Handle to the property page to be added.

## Return value

If **AddWizard97Page** is not
successful, it can return other **HRESULT** values.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057 | The *hpage* parameter represents an unknown page. |

## Remarks

[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) extensions call the
**AddWizard97Page** method from their
[IWEExtendWizard97::CreateWizard97Pages](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweextendwizard97-createwizard97pages)
methods. Before calling
**AddWizard97Page**, extensions must
call the function [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea)
to retrieve a handle to pass in the *hpage* parameter.

To add non-Wizard97 pages, use
[IWCWizardCallback::AddWizardPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwcwizardcallback-addwizardpage).

## See also

[IWCWizard97Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwcwizard97callback)

[IWCWizardCallback::AddWizardPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwcwizardcallback-addwizardpage)

[IWEExtendWizard97::CreateWizard97Pages](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweextendwizard97-createwizard97pages)