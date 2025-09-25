# SetServiceBits function

## Description

Registers a service type with the service control manager and the Server service. The Server service can then announce the registered service type as one it currently supports. The
[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo) and
[NetServerEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserverenum) functions obtain a specified machine's supported service types.

## Parameters

### `hServiceStatus` [in]

A handle to the status information structure for the service. A service obtains the handle by calling the
[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa) function.

### `dwServiceBits` [in]

The service type.

Certain bit flags (0xC00F3F7B) are reserved for use by Microsoft. The
**SetServiceBits** function fails with the error ERROR_INVALID_DATA if any of these bit flags are set in *dwServiceBits*. The following bit flags are reserved for use by Microsoft.

#### SV_TYPE_WORKSTATION (0x00000001)

#### SV_TYPE_SERVER (0x00000002)

#### SV_TYPE_DOMAIN_CTRL (0x00000008)

#### SV_TYPE_DOMAIN_BAKCTRL (0x00000010)

#### SV_TYPE_TIME_SOURCE (0x00000020)

#### SV_TYPE_AFP (0x00000040)

#### SV_TYPE_DOMAIN_MEMBER (0x00000100)

#### SV_TYPE_PRINTQ_SERVER (0x00000200)

#### SV_TYPE_DIALIN_SERVER (0x00000400)

#### SV_TYPE_XENIX_SERVER (0x00000800)

#### SV_TYPE_SERVER_UNIX (0x00000800)

#### SV_TYPE_NT (0x00001000)

#### SV_TYPE_WFW (0x00002000)

#### SV_TYPE_POTENTIAL_BROWSER (0x00010000)

#### SV_TYPE_BACKUP_BROWSER (0x00020000)

#### SV_TYPE_MASTER_BROWSER (0x00040000)

#### SV_TYPE_DOMAIN_MASTER (0x00080000)

#### SV_TYPE_LOCAL_LIST_ONLY (0x40000000)

#### SV_TYPE_DOMAIN_ENUM (0x80000000)

Certain bit flags (0x00300084) are defined by Microsoft, but are not specifically reserved for systems software. The following are these bit flags.

#### SV_TYPE_SV_TYPE_SQLSERVER (0x00000004)

#### SV_TYPE_NOVELL (0x00000080)

#### SV_TYPE_DOMAIN_CTRL (0x00100000)

#### SV_TYPE_DOMAIN_BAKCTRL (0x00200000)

Certain bit flags (0x3FC0C000) are not defined by Microsoft, and their use is not coordinated by Microsoft. Developers of applications that use these bits should be aware that other applications can also use them, thus creating a conflict. The following are these bit flags.

0x00004000

0x00008000

0x00400000

0x00800000

0x01000000

0x02000000

0x04000000

0x08000000

0x10000000

0x20000000

### `bSetBitsOn` [in]

If this value is TRUE, the bits in *dwServiceBit* are to be set. If this value is FALSE, the bits are to be cleared.

### `bUpdateImmediately` [in]

If this value is TRUE, the Server service is to perform an immediate update. If this value is FALSE, the update is not be performed immediately.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[NetServerEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserverenum)

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus)