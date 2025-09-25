## Description

The **FAX_DEV_STATUS** structure contains status and identification information about an individual active fax operation.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_DEV_STATUS** structure. Before responding to the [FaxDevReportStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevreportstatus) function, the FSP must set this member to **sizeof**(**FAX_DEV_STATUS**).

### `StatusId`

Type: **DWORD**

Specifies a fax status code or value. This can be a predefined fax status code (shown following), one of the TAPI [LINEERR_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineerr--constants) error codes, or a value that the FSP defines. If the status identifier is provider-defined, the FSP must also supply a value for the **StringId** member. Following are the predefined fax status codes.

| Value | Meaning |
| --- | --- |
| FS_INITIALIZING | The call is initializing. |
| FS_DIALING | The FSP is dialing digits for the call. |
| FS_TRANSMITTING | The FSP is transmitting the fax document. |
| FS_RECEIVING | The FSP is receiving the fax document. |
| FS_COMPLETED | The fax transmission call is complete. |
| FS_LINE_UNAVAILABLE | The FSP cannot complete the call because the device is not available. |
| FS_BUSY | The FSP received a busy signal. |
| FS_NO_ANSWER | The FSP cannot complete the call because the receiving device does not answer. |
| FS_BAD_ADDRESS | The FSP cannot complete the call because the destination address is invalid. |
| FS_NO_DIAL_TONE | The FSP cannot complete the call because it does not detect a dial tone. |
| FS_DISCONNECTED | The call was disconnected by the receiving device. |
| FS_FATAL_ERROR | A fatal error has occurred. |
| FS_NOT_FAX_CALL | The call is a data call or a voice call. |
| FS_CALL_DELAYED | The FSP received a busy signal multiple times. The provider cannot retry because dialing restrictions exist. (Some countries/regions restrict the number of retries when a number is busy.) |
| FS_USER_ABORT | The FSP has canceled the transmission. Cancellation can result from a call to the [FaxDevAbortOperation](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevabortoperation) function. FSPs can also provide a UI for cancellation of fax transmissions. |
| FS_ANSWERED | The FSP answered the inbound call but is not yet receiving the call. This status indicates to the fax service that the call may not be a fax call. |
| FS_CALL_BLACKLISTED | The FSP cannot complete the call because the telephone number is blocked or reserved, for example, a call to 911 or another emergency number. |

The fax status codes FS_BAD_ADDRESS, FS_CALL_BLACKLISTED and FS_USER_ABORT will result in no retry attempts. The fax status code FS_LINE_UNAVAILABLE will result in an immediate retry attempt in the case when the line is unavailable because the service lost the connection to the device (TAPI sent LINE_CLOSE, and the FSP reported FS_LINE_UNAVAILABLE). The retry depends on whether the device is detected back online. All other fax status codes will result in allowing the fax service to manage retry attempts.

### `StringId`

Type: **DWORD**

Specifies a string resource identifier for the **StatusId** member if the **StatusId** is provider-defined. The fax service loads the string from the FSP's image. If **StatusId** contains a provider-defined status code or value, this member is required. If **StatusId** contains a predefined status code or value, this member is ignored.

### `PageCount`

Type: **DWORD**

Specifies the number of the page in the fax transmission that the FSP is receiving. The page count is relative to one.

### `CSI`

Type: **LPWSTR**

Pointer to a null-terminated Unicode character string that specifies an identifier of the remote fax device that is connected with the current call to either the [FaxDevReceive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevreceive) or [FaxDevSend](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevsend) function.

If the operation is sending a fax, the identifier specifies the CSID of the remote device; if the operation is receiving a fax, the identifier specifies the TSID of the remote device.

### `CallerId`

Type: **LPWSTR**

Pointer to a null-terminated Unicode character string that identifies the calling device that sent the received fax document. This string can include the telephone number of the calling device.

### `RoutingInfo`

Type: **LPWSTR**

Pointer to a null-terminated Unicode character string that specifies the routing string for an inbound fax. The string must be of the form:

`Canonical-Phone-Number[|Additional-Routing-Info]`

where `Canonical-Phone-Number` is defined in the [Address](https://learn.microsoft.com/windows/desktop/Tapi/address-ovr) topic of the TAPI documentation (see the Canonical Address subheading); and `Additional-Routing-Info` is the *subaddress* of a Canonical Address, and uses the subaddress format.

For DID routing, append the specific DID digits to the telephone number prefix. The DID address must be the canonical telephone number that corresponds to the fully qualified telephone number that the sender would have dialed.

If there is additional routing information, for example, subaddressing or DTMF tones, separate it from the canonical telephone number by a vertical bar character as indicated in the TAPI specification. You can specify multiple recipients.

For more information, see the Dialable Address and Canonical Address subheadings in the Address topic of the TAPI documentation.

### `ErrorCode`

Type: **DWORD**

Specifies one of the Win32 [System Error Codes [Base]](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that the FSP should use to report an error that occurs. The FSP should set this value to NO_ERROR when it is running and after a fax job completes normally.

### `Reserved`

Type: **DWORD**

This member is reserved by Microsoft. It must be set to zero.

## Remarks

The FSP must either set all of the members of the **FAX_DEV_STATUS** structure to the status information for the active fax operation, or set them to zero.

The fax service allocates the memory for the strings pointed to by the **CSI**, **CallerId** and **RoutingInfo** members. The size of the memory the service allocates is equal to sizeof(**FAX_DEV_STATUS**) + **FAXDEVREPORTSTATUS_SIZE**. The FSP must place the strings in the block of memory that immediately follows the **FAX_DEV_STATUS** structure. The **CSI**, **CallerId** and **RoutingInfo** members must point to the location of the strings in the memory block.

## See also

[Fax Service Provider Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-structures)

[FaxDevReceive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevreceive)

[FaxDevReportStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevreportstatus)

[FaxDevSend](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevsend)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)