# Dhcpv6RequestParams function

## Description

The Dhcpv6RequestParams function requests options from the DHCPv6 client cache or directly from the DHCPv6 server.

## Parameters

### `forceNewInform`

If this value is set to **TRUE**, any available cached information will be ignored and new information will be requested. Otherwise, the request is only sent if there is no cached information.

### `reserved`

Reserved for future use. Must be set to **NULL**.

### `adapterName`

GUID of the adapter for which this request is meant. This parameter must not be **NULL**.

### `classId`

Pointer to a [DHCPV6CAPI_CLASSID](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6capi_classid) structure that contains the binary ClassId information to use to send on the wire. This parameter is optional.

### `recdParams`

A [DHCPV6CAPI_PARAMS_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpv6csdk/ns-dhcpv6csdk-dhcpv6capi_params_array) structure that contains the parameters to be received from the DHCPV6 server.

### `buffer`

A buffer to contain information returned by some pointers in *recdParams*.

### `pSize`

Size of the buffer. When the function returns ERROR_MORE_DATA, this parameter will contain the size, in bytes, required to complete the operation. If the function is successful, this parameter contains the number of bytes used.

## Return value

Returns ERROR_SUCCESS upon successful completion.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Returned if one of the following conditions are true:<br><br>* *reserved* has a value that is not **NULL**.<br>* *AdapterName* is **NULL**. Or no adapter is found with the GUID specified.<br>* *pSize* is **NULL**.<br>* *buffer* is **NULL**. |
| **ERROR_MORE_DATA** | The call to this API was made with insufficient memory allocated for the *Buffer* parameter, while *pSize* contains the actual memory size required. |
| **ERROR_INVALID_NAME** | The *AdapterName* is not in the correct format. It should be in this format: {00000000-0000-0000-0000-000000000000}. |