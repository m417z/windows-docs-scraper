# ITSGAuthorizeResourceSink::OnChannelAuthorized

## Description

Notifies Remote Desktop Gateway (RD Gateway) about the result of an attempt to authorize a resource.

## Parameters

### `hrIn` [in]

The result of the authorization attempt. Specify **S_OK** to indicate that the attempt succeeded. Specify any other value to indicate that the attempt failed.

### `mainSessionId` [in]

A unique identifier assigned to the connection request by RD Gateway.

### `subSessionId` [in]

A unique identifier assigned to the subsession by RD Gateway. A subsession is a session launched from another session.

### `allowedResourceNames` [in]

A pointer to a **BSTR** that contains a list of resources that were successfully authorized.

### `numAllowedResourceNames` [in]

The number of resources referenced by the *allowedResourceNames* parameter. If the function succeeds, this parameter must be one or more.

### `failedResourceNames` [in]

A pointer to a **BSTR** that contains a list of resources that failed authorization.

### `numFailedResourceNames` [in]

The number of resources referenced by the *failedResourceNames* parameter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can call this method from your implementation of
[AuthorizeResource](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nf-tsgpolicyengine-itsgpolicyengine-authorizeresource). If
authorization requires more than 1 second, we recommend launching a separate thread to perform
authentication.

For a sample that uses the **OnChannelAuthorized** method, see the [Remote Desktop Gateway Pluggable Authentication and Authorization](https://github.com/microsoftarchive/msdn-code-gallery-community-m-r/tree/master/Remote%20Desktop%20Gateway%20Pluggable%20Authentication%20and%20Authorization%20Sample) sample.

## See also

[ITSGAuthorizeResourceSink](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgauthorizeresourcesink)