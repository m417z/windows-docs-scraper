# IEnroll4::addExtensionToRequestWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **addExtensionToRequestWStr** method adds an extension to the request. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `Flags` [in]

Specifies whether the extension is critical.
If **TRUE**, the extension being added is critical. If **FALSE**, it is not critical.

### `pwszName` [in]

A pointer to a null-terminated wide character string that represents the Object Identifier (OID) for the extension name.

### `pblobValue` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that represents the extension value.

## Return value

The return value is an **HRESULT**, with S_OK returned if the call is successful.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)