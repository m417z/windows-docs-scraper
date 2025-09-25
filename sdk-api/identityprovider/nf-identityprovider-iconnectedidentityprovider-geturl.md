# IConnectedIdentityProvider::GetUrl

## Description

Returns the URL string for the specified wizard or webpage.

## Parameters

### `Identifier` [in]

Identifies the wizard or webpage that should be returned.

### `Context` [in]

Describes the context in which the URL will be displayed.

### `PostData` [out]

A **VARIANT** of type VT_ARRAY and VT_UI1 that will be posted to the provided URL. If the post data is not required, this parameter should be set to VT_EMPTY.

### `Url` [out]

Returns a URL for the specified identity wizard or webpage. The URL must begin with **https://**.

## Return value

If the method succeeds, the method returns S_OK.

If the method fails, the method returns a Win32 error code.

## See also

[IConnectedIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iconnectedidentityprovider)