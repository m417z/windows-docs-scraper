# DhcpUndoRequestParams function

## Description

The
**DhcpUndoRequestParams** function removes persistent requests previously made with a
**DhcpRequestParams** function call.

## Parameters

### `Flags` [in]

Reserved. Must be zero.

### `Reserved` [in]

Reserved for future use. Must be set to **NULL**.

### `AdapterName` [in]

GUID of the adapter for which information is no longer required. Must be under 256 characters.

**Note** This parameter is no longer used.

### `RequestIdStr` [in]

Application identifier (ID) originally used to make a persistent request. This string must match the *RequestIdStr* parameter used in the
**DhcpRequestParams** function call that obtained the corresponding persistent request. Note that this must match the previous application identifier (ID) used, and must be a printable string with no special characters (commas, backslashes, colons, or other illegal characters may not be used).

## Return value

Returns ERROR_SUCCESS upon successful completion. Otherwise, returns a Windows error code.

## Remarks

Persistent requests are typically made by the setup or installer process associated with the application. When appropriate, the setup or installer process would likely make the
**DhcpUndoRequestParams** function call to cancel its associated persistent request.

## See also

[DHCP Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-functions)

[DhcpCApiInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpcsdk/nf-dhcpcsdk-dhcpcapiinitialize)

[DhcpRequestParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpcsdk/nf-dhcpcsdk-dhcprequestparams)