# IPNPXAssociation::Delete

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Removes an entry from the association database.

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

To mark a device as unavailable for use without deleting the association database entry, call [IPNPXAssociation::Unassociate](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nf-pnpxassoc-ipnpxassociation-unassociate).

## See also

[IPNPXAssociation](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nn-pnpxassoc-ipnpxassociation)

[IPNPXDeviceAssociation::Delete](https://learn.microsoft.com/windows/desktop/api/pnpxassoc/nf-pnpxassoc-ipnpxdeviceassociation-delete)