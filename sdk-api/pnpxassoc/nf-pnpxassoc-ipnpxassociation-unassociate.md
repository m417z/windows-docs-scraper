# IPNPXAssociation::Unassociate

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Marks an association database entry as unassociated. If a function instance is unassociated, then it is a *not present* instance and the device corresponding to the function instance is not available for use.

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

This method does not remove the entry from the association database. To remove an entry from the association database, call [IPNPXAssociation::Delete](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nf-pnpxassoc-ipnpxassociation-delete).

## See also

[IPNPXAssociation](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nn-pnpxassoc-ipnpxassociation)

[IPNPXDeviceAssociation::Unassociate](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nf-pnpxassoc-ipnpxdeviceassociation-unassociate)