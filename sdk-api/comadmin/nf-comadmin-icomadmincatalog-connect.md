# ICOMAdminCatalog::Connect

## Description

Connects to the COM+ catalog on a specified remote computer.

## Parameters

### `bstrCatalogServerName` [in]

The name of the remote computer. To connect to the local computer, use an empty string.

### `ppCatalogCollection` [out, retval]

The [ICatalogCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogcollection) interface for the root collection on the remote computer.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The **Connect** method also retrieves a root collection that is bound to the remote computer. A root collection serves as a starting point to locate top-level collections and does not contain any objects or properties.

You can use the [GetCollection](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog-getcollection) method to get a top-level collection on the local computer without first using the **Connect** method.

When you use the **Connect** method, the [ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog) interface you are holding works on the computer to which you have connected.

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)