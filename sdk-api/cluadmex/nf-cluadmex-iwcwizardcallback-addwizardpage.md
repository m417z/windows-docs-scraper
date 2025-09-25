# IWCWizardCallback::AddWizardPage

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Adds a property page to a Failover Cluster Administrator Wizard.

## Parameters

### `hpage` [in]

Handle to the property page to be added.

## Return value

If **AddWizardPage** is not successful,
it can return other **HRESULT** values.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057 | The *hpage* parameter represents an unknown page. |

## Remarks

[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) extensions call the
**AddWizardPage** method from their
[IWEExtendWizard::CreateWizardPages](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweextendwizard-createwizardpages)
methods. Before calling **AddWizardPage**,
extensions must call the function
[CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea) to retrieve a
handle to pass in the *hpage* parameter.

Use
[IWCWizard97Calllback::AddWizard97Page](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwcwizard97callback-addwizard97page)
to add Wizard97 pages.

## See also

[IWCWizard97Callback::AddWizard97Page](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwcwizard97callback-addwizard97page)

[IWCWizardCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwcwizardcallback)

[IWEExtendWizard::CreateWizardPages](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweextendwizard-createwizardpages)