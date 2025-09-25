# NetGetJoinInformation function

## Description

The
**NetGetJoinInformation** function retrieves join status information for the specified computer.

## Parameters

### `lpServer` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the computer on which to call the function. If this parameter is **NULL**, the local computer is used.

### `lpNameBuffer` [out]

Pointer to the buffer that receives the NetBIOS name of the domain or workgroup to which the computer is joined. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `BufferType` [out]

Receives the join status of the specified computer. This parameter can have one of the following values.

```cpp
typedef enum _NETSETUP_JOIN_STATUS {

    NetSetupUnknownStatus = 0,
    NetSetupUnjoined,
    NetSetupWorkgroupName,
    NetSetupDomainName

} NETSETUP_JOIN_STATUS, *PNETSETUP_JOIN_STATUS;

```

These values have the following meanings.

| Value | Meaning |
| --- | --- |
| **NetSetupUnknownStatus** | The status is unknown. |
| **NetSetupUnjoined** | The computer is not joined. |
| **NetSetupWorkgroupName** | The computer is joined to a workgroup. |
| **NetSetupDomainName** | The computer is joined to a domain. |

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be the following error code or one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough storage is available to process this command. |

## Remarks

No special group membership is required to successfully execute the
**NetGetJoinInformation** function.

## See also

[NetGetJoinableOUs](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netgetjoinableous)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)