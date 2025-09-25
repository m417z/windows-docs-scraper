# PropertyConstraint enumeration

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Qualifies the filter conditions used for searching for function instances. This enumeration is used when adding a constraint to a query using the [IFunctionInstanceCollectionQuery::AddPropertyConstraint](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollectionquery-addpropertyconstraint) method.

A function instance will only match a property constraint when the property key (PKEY) passed to [AddPropertyConstraint](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollectionquery-addpropertyconstraint) has the same PROPVARIANT type as the PKEY in the function instance's property store and the PROPVARIANT value satisfies the constraint's filter conditions.

## Constants

### `QC_EQUALS:0`

The constraint's PKEY and the function instance's PKEY must be equal.

### `QC_NOTEQUAL:1`

The constraint's PKEY and the function instance's PKEY must not be equal.

### `QC_LESSTHAN:2`

The constraint's PKEY must be less than the function instance's PKEY. This value can be used only with numbers.

### `QC_LESSTHANOREQUAL:3`

The constraint's PKEY must be less than or equal to the function instance's PKEY. This value can be used only with numbers.

### `QC_GREATERTHAN:4`

The constraint's PKEY must be greater than the function instance's PKEY. This value can be used only with numbers.

### `QC_GREATERTHANOREQUAL:5`

The constraint's PKEY must be greater than or equal to the function instance's PKEY. This value can be used only with numbers.

### `QC_STARTSWITH:6`

The constraint's PKEY must be the start of the function instance's PKEY. This value can be used with strings only.

### `QC_EXISTS:7`

The property must exist.

### `QC_DOESNOTEXIST:8`

The property must not exist.

### `QC_CONTAINS:9`

The constraint's PKEY value must be contained within the function instance's PKEY value. This filter is only supported for PROPVARIANTs of type VT_LPWSTR or VT_VECTOR|VT_LPWSTR.

For PROPVARIANTs of type VT_LPWSTR, the constraint PKEY value must be a substring of the function instance's PKEY value.

For PROPVARIANTs of type VT_VECTOR|VT_LPWSTR, the constraint PKEY value must have exactly one element, and matching function instances must have a PKEY with at least one vector element that exactly matches the constraint PKEY value.

## See also

[IFunctionInstanceCollectionQuery::AddPropertyConstraint](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollectionquery-addpropertyconstraint)