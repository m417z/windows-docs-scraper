# NPGetResourceParent function

## Description

Retrieves the parent of a specified network resource in the browse hierarchy. This function is typically called for resources that were returned by the same provider from prior calls to
[NPEnumResource](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npenumresource) or
[NPGetResourceInformation](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetresourceinformation).

## Parameters

### `lpNetResource` [in]

Pointer to the network resource whose parent name is required. The
[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) could have been obtained from a previous call to
[NPEnumResource](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npenumresource) or
[NPGetResourceInformation](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetresourceinformation), or constructed by the caller.

The **lpRemoteName** field specifies the remote name of the network resource whose parent is required.

The **lpProvider** field specifies the provider to call. This must be supplied.

The **dwType** field is filled in if the calling program knows its value. Otherwise, it is set to **NULL**.

All other fields in the [NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) are ignored and are not initialized.

### `lpBuffer` [out]

Pointer to a buffer to receive the result, which is a single [NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) structure representing the parent resource. The **lpRemoteName**, **lpProvider**, **dwType**, **dwDisplayType**, and **dwUsage** fields are returned; all other fields are set to **NULL**.

The output **lpRemoteName** should be in the same format as that returned from an enumeration by
[NPEnumResource](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npenumresource), so that the caller can perform a case-sensitive string comparison to determine whether the parent resource is the same as one returned by **NPEnumResource**. If the input resource syntactically has a parent, the provider can return it, without determining whether the input resource or its parent actually exist. If a resource has no browse parent on the network, then **lpRemoteName** is returned as **NULL**.

The RESOURCEUSAGE_CONNECTABLE bit in the returned **dwUsage** field does not necessarily indicate that the resource can currently be connected to, only that the resource is connectable when it is available on the network.

### `lpBufferSize` [in, out]

Pointer to a location that specifies the size, in bytes, of the buffer pointed to by the *lpBuffer* parameter. If the buffer is too small for the result, the function places the required buffer size at this location and returns the error WN_MORE_DATA.

## Return value

If the function succeeds, it should return WN_SUCCESS. Otherwise, it should return an error code, which may be one of the following.

| Return code | Description |
| --- | --- |
| **WN_MORE_DATA** | The input buffer is too small. |
| **WN_BAD_NETNAME** | This provider does not own the resource specified by *lpNetResource* (or the resource is syntactically not valid). |
| **WN_BAD_VALUE** | Either **dwUsage** or **dwType** is not valid, or there is an incorrect combination of parameters specified (for example, **lpRemoteName** is syntactically not valid for **dwType**). |
| **WN_NOT_AUTHENTICATED** | The caller has not been authenticated to the network. |
| **WN_ACCESS_DENIED** | The caller has been authenticated to the network, but does not have sufficient permissions. |