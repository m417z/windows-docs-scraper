# IPNPXDeviceAssociation::Unassociate

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Marks an association database entry as unassociated and sends an appropriate notification.

## Parameters

### `pszSubCategory` [in, optional]

The subcategory of the association database in which the entry is stored. This parameter can be **NULL**.

### `pIFunctionDiscoveryNotification` [in]

An [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) object that is registered for notifications with Function Discovery.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The method failed. |

## Remarks

This method modifies the association database entry corresponding to the function instance from which the [IPNPXDeviceAssociation](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nn-pnpxassoc-ipnpxdeviceassociation) interface was obtained.

The following logic is used to determine the callback method used for notification:

* If a PnP notification is received after the device is unassociated, then the [IFunctionDiscoveryNotification::OnUpdate](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onupdate) method is called with the *enumQueryUpdateAction* parameter set to **QUA_REMOVE**.
* If no PnP notification is received after the device is unassociated, and there are no pending PnP events, then the [IFunctionDiscoveryNotification::OnError](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onerror) method is called.
* Finally, if no PnP notification is received after the device is unassociated, and there are pending PnP events, then no callback method is called.

This method does not remove the entry from the association database. To remove an entry from the association database, call [IPNPXAssociation::Delete](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nf-pnpxassoc-ipnpxassociation-delete).

## See also

[IPNPXAssociation::Unassociate](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nf-pnpxassoc-ipnpxassociation-unassociate)

[IPNPXDeviceAssociation](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nn-pnpxassoc-ipnpxdeviceassociation)