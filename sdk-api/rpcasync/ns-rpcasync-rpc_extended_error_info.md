# RPC_EXTENDED_ERROR_INFO structure

## Description

The
**RPC_EXTENDED_ERROR_INFO** structure is used to store extended error information.

## Members

### `Version`

Version of the structure. Must be RPC_EEINFO_VERSION.

### `ComputerName`

Non-qualified DNS name, expressed in Unicode.

### `ProcessID`

Process identifier for the offending error event.

### `u`

### `u.SystemTime`

Time the record was generated, expressed in seconds since the beginning of January 1, 1970, Greenwich Mean Time (GMT), excluding leap seconds. Either **FileTime** or **SystemTime** is valid, based on whether **EEInfoUseFileTime** is used in the **Flags** member.

### `u.FileTime`

Time the record was generated, expressed in seconds since the beginning of January 1, 1970, Greenwich Mean Time (GMT), excluding leap seconds. Either **FileTime** or **SystemTime** is valid, based on whether **EEInfoUseFileTime** is used in the **Flags** member..

### `u.KernelTime`

### `GeneratingComponent`

Code for the component that generated the error.

### `Status`

Status code for the error.

### `DetectionLocation`

Code for the detection location. See
[Extended Error Information Detection Locations](https://learn.microsoft.com/windows/desktop/Rpc/extended-error-information-detection-locations) for valid locations.

### `Flags`

On input, specifies whether **SystemTime** or **FileTime** is used. Set to zero to use **SystemTime**, or EEInfoUseFileTime to use **FileTime**.

On output, specifies whether records are missing. If a record is missing after the current record, **Flags** is set to EEInfoNextRecordsMissing. If a record is missing before the current record, **Flags** is set to EEInfoPreviousRecordsMissing.

### `NumberOfParameters`

Number of parameters in the **Parameters** member.

### `Parameters`

Array of
[RPC_EE_INFO_PARAM](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_ee_info_param) structures containing the extended error information.

## Remarks

On input, the caller fills in only the **Version** and **Flags** members of the
**RPC_EXTENDED_ERROR_INFO** structure. All other members are filled upon output by RPC.

The
**RPC_EXTENDED_ERROR_INFO** structure is used in conjunction with the **RpcError*** functions to investigate and create extended RPC error information.

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

[RPC_EE_INFO_PARAM](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_ee_info_param)

[RPC_ERROR_ENUM_HANDLE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_error_enum_handle)

[RpcErrorAddRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerroraddrecord)

[RpcErrorClearInformation](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorclearinformation)

[RpcErrorEndEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorendenumeration)

[RpcErrorGetNextRecord](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnextrecord)

[RpcErrorGetNumberOfRecords](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorgetnumberofrecords)

[RpcErrorLoadErrorInfo](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorloaderrorinfo)

[RpcErrorResetEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorresetenumeration)

[RpcErrorSaveErrorInfo](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorsaveerrorinfo)

[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration)