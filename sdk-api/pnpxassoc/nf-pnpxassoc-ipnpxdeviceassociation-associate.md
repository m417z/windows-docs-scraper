# IPNPXDeviceAssociation::Associate

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Marks an association database entry as associated and sends an appropriate notification. If there is no association database entry for the function instance, one is created; otherwise the existing entry is updated. Any notification sent reflects the online presence of the device, as reported by the Plug and Play (PnP) component.

## Parameters

### `pszSubCategory` [in, optional]

The subcategory of the association database in which the entry is stored. This parameter can be **NULL**.

### `pIFunctionDiscoveryNotification` [in]

An [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) object that is registered for notifications with Function Discovery.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The method failed. |

## Remarks

This method modifies the association database entry corresponding to the function instance from which the [IPNPXDeviceAssociation](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nn-pnpxassoc-ipnpxdeviceassociation) interface was obtained.

Once a device is associated, the PnP-X Service IP Bus Enumerator (IPBusEnum) sends a request to the PnP component to create the device [devnode](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/function-discovery-glossary). Once the devnode has been created, the appropriate notification is sent. The following logic is used to determine the callback method used for notification:

* If a PnP notification is received after the device is associated, then the [IFunctionDiscoveryNotification::OnUpdate](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onupdate) method is called with the *enumQueryUpdateAction* parameter set to **QUA_ADD**.
* If no PnP notification is received after the device is associated, and there are no pending PnP events, then the [IFunctionDiscoveryNotification::OnError](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onerror) method is called.
* Finally, if no PnP notification is received after the device is associated, and there are pending PnP events, then no callback method is called.

The **Found New Hardware** wizard appears if user intervention is required to install a device driver after association.

## See also

[IPNPXAssociation::Associate](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nf-pnpxassoc-ipnpxassociation-associate)

[IPNPXDeviceAssociation](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nn-pnpxassoc-ipnpxdeviceassociation)