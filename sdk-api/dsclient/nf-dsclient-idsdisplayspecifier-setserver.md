# IDsDisplaySpecifier::SetServer

## Description

The **IDsDisplaySpecifier::SetServer** method specifies the server from which display specifier data is obtained.

## Parameters

### `pszServer` [in]

Pointer to a null-terminated Unicode string that contains the name of the server that will be used to obtain the display specifier data.

### `pszUserName` [in]

Pointer to a null-terminated Unicode string that contains the user name to be used for access to the server specified in *pszServer*.

### `pszPassword` [in]

Pointer to a null-terminated Unicode string that contains the password used to access the server specified in *pszServer*.

### `dwFlags` [in]

Contains a set of flags used to bind to the directory service. This can be zero or a combination of one or more of the following values.

#### DSSSF_SIMPLEAUTHENTICATE (1 (0x1))

The [IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier) object uses simple authentication instead of secure authentication.

#### DSSSF_DONTSIGNSEAL (2 (0x2))

The [IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier) object does not use signing and sealing when opening objects.

#### DSSSF_DSAVAILABLE (2147483648 (0x80000000))

The [IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier) object will not check whether the directory server is available.

## Return value

Returns a standard **HRESULT** value including the following.

## Remarks

The server data is cached by the [IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier) object. The **IDsDisplaySpecifier** object does not actually bind to the server until a specific method, such as [IDsDisplaySpecifier::GetDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-getdisplayspecifier), is called.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier)

[IDsDisplaySpecifier::GetDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-getdisplayspecifier)