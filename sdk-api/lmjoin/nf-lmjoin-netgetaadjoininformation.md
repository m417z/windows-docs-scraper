# NetGetAadJoinInformation function

## Description

Retrieves the join information for the specified tenant. This function examines the join information for Microsoft Azure Active Directory and the work account that the current user added.

## Parameters

### `pcszTenantId` [in, optional]

The tenant identifier for the joined account. If the device
is not joined to Azure Active Directory (Azure AD), and the user currently logged into Windows added no Azure AD work accounts for the specified tenant,
the buffer that the *ppJoinInfo* parameter points to is set to NULL.

If the specified
tenant ID is NULL or empty, *ppJoinInfo* is set to the default
join account information, or NULL if the device is not joined to Azure AD and the current user added no Azure AD work accounts.
The default join account is one of the following:

* The Azure AD account, if the device is joined to Azure AD.
* The Azure AD work account that the current user added, if the device is not joined to Azure AD,
  but the current user added a single Azure AD work account.
* Any of the Azure AD work accounts that the current user added, if the device is not joined to Azure AD, but the current user added multiple
  Azure AD work accounts. The algorithm for selecting one of the work
  accounts is not specified.

### `ppJoinInfo` [out]

The join information for the tenant that the *pcszTenantId* parameter specifies. If this parameter is NULL, the device is not joined to Azure AD and the current user added no Azure AD work accounts. You must call
the [NetFreeAadJoinInformation](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netfreeaadjoininformation) function to free the memory allocated for
this structure.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[NetFreeAadJoinInformation](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netfreeaadjoininformation)