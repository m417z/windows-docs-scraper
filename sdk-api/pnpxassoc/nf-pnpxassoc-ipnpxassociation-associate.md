# IPNPXAssociation::Associate

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Marks an association database entry as associated. If there is no association database entry for the function instance, one is created; otherwise the existing entry is updated.

## Parameters

### `pszSubcategory` [in, optional]

The subcategory of the association database in which the entry is stored. This parameter can be **NULL**.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The method failed. |

## Remarks

This method modifies the association database entry corresponding to the function instance from which the [IPNPXAssociation](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nn-pnpxassoc-ipnpxassociation) interface was obtained.

Once a device is associated, the PnP-X Service IP Bus Enumerator (IPBusEnum) sends a request to the PnP component to create the device [devnode](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/function-discovery-glossary). The **Found New Hardware** wizard appears if user intervention is required to install a device driver after association.

## See also

[IPNPXAssociation](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nn-pnpxassoc-ipnpxassociation)

[IPNPXDeviceAssociation::Associate](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nf-pnpxassoc-ipnpxdeviceassociation-associate)