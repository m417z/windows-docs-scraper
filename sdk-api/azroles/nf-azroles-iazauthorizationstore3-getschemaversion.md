# IAzAuthorizationStore3::GetSchemaVersion

## Description

The **GetSchemaVersion** method gets the version number of this authorization store.

## Parameters

### `plMajorVersion` [out]

The major version of the authorization store. Valid values are 1 and 2. A version 1 Authorization Manager (AzMan) runtime cannot read from or write to an authorization store with a major version of 2.

### `plMinorVersion` [out]

The minor version of the authorization store. Valid values are 1 and 2. A version 1 AzMan runtime can read from but not write to an authorization store with a minor version of 2.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).