# IPublishingWizard::GetTransferManifest

## Description

Gets a transfer manifest for a file transfer operation performed by a publishing wizard, such as the Online Print Wizard or the Add Network Place Wizard.

**Note** This method is deprecated for Windows Vista, as it is not supported for Online Print Wizard or Add Network Place Wizard.

## Parameters

### `phrFromTransfer` [out]

Type: **HRESULT***

A pointer to a variable of type **HRESULT** that, when this method returns, is set to S_OK if the transfer operation was successful, S_FALSE if the transfer has not yet begun, or a standard error value if the transfer has failed or has been canceled. This value can be **NULL** if you do not require this information.

### `pdocManifest` [out]

Type: **IXMLDOMDocument****

Address of an [IXMLDOMDocument interface](https://learn.microsoft.com/previous-versions/windows/desktop/dd892951(v=vs.85)) pointer that, when this method returns, points to the **IXMLDOMDocument interface** object that represents the manifest. This value can be **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if the manifest is successfully retrieved or a standard COM error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | The transfer manifest has not yet been created. |

## Remarks

The transfer manifest is not created until the wizard is actually displayed. For information on displaying a publishing wizard, see the [IPublishingWizard](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-ipublishingwizard) topic.

## See also

[IPublishingWizard](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-ipublishingwizard)

[Transfer Manifest Schema](https://learn.microsoft.com/windows/desktop/shell/interfaces)

[Using the Transfer Manifest](https://learn.microsoft.com/windows/desktop/lwef/pubwiz-manifest)