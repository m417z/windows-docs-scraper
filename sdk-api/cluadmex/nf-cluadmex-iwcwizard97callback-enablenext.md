# IWCWizard97Callback::EnableNext

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Enables or disables the **Next** or **Finish** button on a
Wizard97 wizard page, depending on whether the current page is last.

## Parameters

### `hpage` [in]

Handle to the property page containing the button to be enabled or disabled.

### `bEnable` [in]

Value indicating whether to enable or disable the button. If *bEnable* is set to
**TRUE**, the appropriate button is enabled. If *bEnable* is set
to **FALSE**, it is disabled.

## Return value

If **EnableNext** is not successful, it can return other
**HRESULT** values.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057 | The *hpage* parameter represents an unknown page. |

## Remarks

Extensions should call the **EnableNext**
method in their handling of the **PSN_SETACTIVE** message for a property page that
they have added to the Failover Cluster Administrator Wizard.
[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) determines whether
the **Next** or **Finish** button should be displayed based on
the page specified in the *hpage* parameter.

For non-Wizard97 pages use
[IWCWizardCallback::EnableNext](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwcwizardcallback-enablenext).

## See also

[IWCWizard97Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwcwizard97callback)

[IWCWizardCallback::EnableNext](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iwcwizardcallback-enablenext)