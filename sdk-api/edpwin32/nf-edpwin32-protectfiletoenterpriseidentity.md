# ProtectFileToEnterpriseIdentity function

## Description

**Note** Windows Information Protection (WIP) policy can be applied on Windows 10, version 1607.

Protects the data in a file to an enterprise identity, so that only users who are associated with that enterprise identity can access the data. The application can then use standard APIs to read or write from the file.

## Parameters

### `fileOrFolderPath` [in]

The path for the file or folder that you want to protect.

### `identity` [in]

The enterprise identity for which the data is protected. This identity is an email address or domain that is managed.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.