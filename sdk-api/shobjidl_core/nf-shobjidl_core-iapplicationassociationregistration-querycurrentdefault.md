# IApplicationAssociationRegistration::QueryCurrentDefault

## Description

Determines the default application for a given association type. This is the default application launched by [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea) for that type.

## Parameters

### `pszQuery` [in]

Type: **LPCWSTR**

A pointer to a null-terminated, Unicode string that contains the file name extension or protocol, such as .mp3 or http.

### `atQueryType` [in]

Type: **[ASSOCIATIONTYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationtype)**

One of the [ASSOCIATIONTYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationtype) enumeration values that specifies the type of association, such as extension or MIME type.

### `alQueryLevel` [in]

Type: **[ASSOCIATIONLEVEL](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationlevel)**

One of the [ASSOCIATIONLEVEL](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationlevel) enumeration values that specifies the level of association, such as per-user or machine. This is typically [AL_EFFECTIVE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-associationlevel).

### `ppszAssociation` [out]

Type: **LPWSTR***

When this method returns, contains the address of a pointer to the ProgID that identifies the current default association.

**Note** It is the responsibility of the calling application to release the string through [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The string produced is typically a ProgID matching one of the ProgIDs associated with a registered application, but there are a few exceptions: If the string returned is a machine default protocol, it is a legacy string indicating a command line to a .exe handler instead of a ProgID. Similarly, if returning a machine default MIME type, it returns a legacy class identifier (CLSID) string instead of a ProgID.

## See also

[Default Programs](https://learn.microsoft.com/windows/desktop/shell/default-programs)

[IApplicationAssociationRegistration](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationassociationregistration)