# LINEREQMAKECALL structure

## Description

The
**LINEREQMAKECALL** structure describes a request initiated by a call to the
[lineGetRequest](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetrequest) function.

## Members

### `szDestAddress`

**Null**-terminated destination address of the make-call request. The address can use the canonical address format or the dialable address format. The maximum length of the address is TAPIMAXDESTADDRESSSIZE characters, which includes the **NULL** terminator. Longer strings are truncated.

### `szAppName`

**Null**-terminated user-friendly application name or filename of the application that originated the request. The maximum length of the address is TAPIMAXAPPNAMESIZE characters, which includes the **NULL** terminator.

### `szCalledParty`

**Null**-terminated user-friendly called-party name. The maximum length of the called-party information is TAPIMAXCALLEDPARTYSIZE characters, which includes the **NULL** terminator.

### `szComment`

**Null**-terminated comment about the call request. The maximum length of the comment string is TAPIMAXCOMMENTSIZE characters, which includes the **NULL** terminator.

## Remarks

This structure may not be extended.

The **szDestAddress** member contains the address of the remote party; the other members are useful for logging purposes. An application must use this structure to interpret the request buffer it received from
[lineGetRequest](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetrequest) with the LINEREQUESTMODE_MAKECALL request mode.

## See also

[lineGetRequest](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetrequest)