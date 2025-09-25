# IEnroll4::addAttributeToRequestWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **addAttributeToRequestWStr** method adds an [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `Flags` [in]

This parameter is reserved for future use and must be set to zero.

### `pwszName` [in]

A pointer to a null-terminated wide character string that represents the object identifier (OID) for the attribute name.

### `pblobValue` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that represents the attribute value.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)