# NPGetResourceInformation function

## Description

Separates the part of a network resource accessed through the WNet API from the part accessed through APIs specific to the resource type.

## Parameters

### `lpNetResource` [in]

Specifies the network resource for which information is required. The **lpRemoteName** field specifies the remote name of the resource. The calling program should fill in the values for the **lpProvider** and **dwType** fields if it knows these values; otherwise, it should set these fields to **NULL**. All other fields in the [NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) are ignored and are not initialized.

If the **lpRemoteName** string contains a portion that is accessed through WNet APIs and a portion that is accessed through other system APIs specific to the resource type, the function should return information only about the network portion of the resource (except for *lplpSystem*, as described later in this topic).

For example, if the resource is "\\server\share\dir1\dir2", where "\\server\share" is accessed through WNet APIs and "\dir1\dir2" is accessed through file system APIs, the provider should verify that it is the right provider for "\\server\share", but need not check whether "\dir1\dir2" actually exists.

### `lpBuffer` [out]

Pointer to the buffer to receive the result. The first field in the result is a single
[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/winnetwk/ns-winnetwk-netresourcea) structure, and associated strings, representing that portion of the input resource that is accessed through the WNet API, rather than system APIs specific to the resource type. For example, if the input remote resource name was "\\server\share\dir1\dir2", then the output **NETRESOURCE** contains information about the resource "\\server\share". The **lpRemoteName**, **lpProvider**, **dwType**, **dwDisplayType**, and **dwUsage** fields are returned containing values, all other fields being set to **NULL**.

The **lpRemoteName** field should be returned in the same format as that returned from an enumeration by the
[NPEnumResource](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npenumresource) function, so that the caller can perform a case-sensitive string comparison. This is necessary to determine whether the output network resource is the same as one returned by **NPEnumResource**.

The provider should not do purely syntactic checking to determine whether it owns the resource. This could produce incorrect results when two networks are running on the client and the provider doing syntactic checking is called first.

### `lpBufferSize` [in, out]

Pointer to a location that specifies the size, in bytes, of the buffer pointed to by *lpBuffer*. If the buffer is too small for the result, the function places the required buffer size at this location and returns the error WN_MORE_DATA.

### `lplpSystem` [out]

On a successful return, a pointer to a **null**-terminated string in the output buffer specifying that part of the resource that is accessed through system APIs specific to the resource type, rather than through the WNet API. If there is no such part, *lplpSystem* is set to **NULL**. For example, if the input remote resource name was "\\server\share\dir", **lpRemoteName** is returned pointing to "\\server\share" and *lplpSystem* points to "\dir", both strings being stored in the buffer pointed to by *lpBuffer*.

## Return value

If the function succeeds, it should return WN_SUCCESS. Otherwise, it should return an error code, which may be one of the following.

| Return code | Description |
| --- | --- |
| **WN_MORE_DATA** | The input buffer is too small. |
| **WN_BAD_NETNAME** | The resource is not recognized by this provider. |
| **WN_BAD_VALUE** | Invalid *dwUsage* or *dwType*. |
| **WN_BAD_DEV_TYPE** | The caller passed in a nonzero *dwType* that does not match the actual type of the network resource. |
| **WN_NOT_AUTHENTICATED** | The caller has not been authenticated to the network. |
| **WN_ACCESS_DENIED** | The caller has been authenticated to the network but does not have sufficient permissions. |

## Remarks

The enumeration tree can be navigated down from a named network resource by using
[NPOpenEnum](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npopenenum) and its related functions. To navigate up from a named resource, the **NPGetResourceInformation** function can be called to obtain information about the resource, followed by the
[NPGetResourceParent](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetresourceparent) function to obtain the name and type of the parent resource.

**NPGetResourceInformation** determines whether the specified provider is the right provider to respond to a request for a specified network resource. It then returns information about the resource's type.