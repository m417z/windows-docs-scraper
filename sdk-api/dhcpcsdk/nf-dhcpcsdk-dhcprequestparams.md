# DhcpRequestParams function

## Description

The
**DhcpRequestParams** function enables callers to synchronously, or synchronously and persistently obtain DHCP data from a DHCP server.

## Parameters

### `Flags` [in]

Flags that specify the data being requested. This parameter is optional. The following possible values are supported and are not mutually exclusive:

| Value | Meaning |
| --- | --- |
| **DHCPCAPI_REQUEST_PERSISTENT** | The request is persisted but no options are fetched. |
| **DHCPCAPI_REQUEST_SYNCHRONOUS** | Options will be fetched from the server. |

### `Reserved` [in]

Reserved for future use. Must be set to **NULL**.

### `AdapterName` [in]

GUID of the adapter on which requested data is being made. Must be under 256 characters.

### `ClassId` [in]

Class identifier (ID) that should be used if DHCP INFORM messages are being transmitted onto the network. This parameter is optional.

### `SendParams` [in]

Optional data to be requested, in addition to the data requested in the *RecdParams* array. The *SendParams* parameter cannot contain any of the standard options that the DHCP client sends by default.

### `RecdParams` [in, out]

Array of DHCP data the caller is interested in receiving. This array must be empty prior to the
**DhcpRequestParams** function call.

### `Buffer` [in]

Buffer used for storing the data associated with requests made in *RecdParams*.

### `pSize` [in, out]

Size of *Buffer*.

Required size of the buffer, if it is insufficiently sized to hold the data, otherwise indicates size of the buffer which was successfully filled.

### `RequestIdStr` [in]

Application identifier (ID) used to facilitate a persistent request. Must be a printable string with no special characters (commas, backslashes, colons, or other illegal characters may not be used). The specified application identifier (ID) is used in a subsequent
**DhcpUndoRequestParams** function call to clear the persistent request, as necessary.

## Return value

Returns ERROR_SUCCESS upon successful completion.

Upon return, *RecdParams* is filled with pointers to requested data, with corresponding data placed in *Buffer*. If *pSize* indicates that *Buffer* has insufficient space to store returned data, the
**DhcpRequestParams** function returns ERROR_MORE_DATA, and returns the required buffer size in *pSize*. Note that the required size of *Buffer* may increase during the time that elapses between the initial function call's return and a subsequent call; therefore, the required size of *Buffer* (indicated in *pSize*) provides an indication of the approximate size required of *Buffer*, rather than guaranteeing that subsequent calls will return successfully if *Buffer* is set to the size indicated in *pSize*.

Other errors return appropriate Windows error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Returned if the AdapterName parameter is over 256 characters long. |
| **ERROR_BUFFER_OVERFLOW** | Returned if the AdapterName parameter is over 256 characters long. |

## Remarks

DHCP clients store data obtained from a DHCP server in their local cache. If the DHCP client cache contains all data requested in the *RecdParams* array of a
**DhcpRequestParams** function call, the client returns data from its cache. If requested data is not available in the client cache, the client processes the
**DhcpRequestParams** function call by submitting a DHCP-INFORM message to the DHCP server.

When the client submits a DHCP-INFORM message to the DHCP server, it includes any requests provided in the optional *SendParams* parameter, and provides the Class identifier (ID) specified in the *ClassId* parameter, if provided.

Clients can also specify that DHCP data be retrieved from the DHCP server each time the DHCP client boots, which is considered a persistent request. To enable persistent requests, the caller must specify the *RequestIdStr* parameter, and also specify the additional **DHCPAPI_REQUEST_PERSISTENT** flag in the *dwFlags* parameter. This persistent request capability is especially useful when clients need to automatically request application-critical information at each boot. To disable a persist request, clients must call the
function.

**Note** The callers of this API must not make blocking calls to this API, since it can take up to a maximum of 2 minutes to return a code or status. UI behaviors in particular should not block on the return of this call, since it can introduce a significant delay in UI response time.

For more information about DHCP INFORM messages, and other standards-based information about DHCP, consult
[DHCP Standards](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/about-dynamic-host-configuration-protocol).

To see the
**DhcpRequestParams** function in use, see
[DHCP Examples](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-client-api-examples).

## See also

[DHCP Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-functions)

[DHCPCAPI_PARAMS_ARRAY](https://learn.microsoft.com/windows/win32/api/dhcpcsdk/ns-dhcpcsdk-dhcpcapi_params_array)

[DhcpCApiInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpcsdk/nf-dhcpcsdk-dhcpcapiinitialize)

[DhcpUndoRequestParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpcsdk/nf-dhcpcsdk-dhcpundorequestparams)