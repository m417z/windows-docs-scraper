# RpcErrorGetNextRecord function

## Description

The
**RpcErrorGetNextRecord** function retrieves the next extended error information record for an enumeration handle.

## Parameters

### `EnumHandle` [in]

Pointer to the enumeration handle, in the form of an
[RPC_ERROR_ENUM_HANDLE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_error_enum_handle) structure. The structure must be allocated by the caller, and cannot be freed until the operation is complete. All members are ignored on input.

### `CopyStrings` [in]

Specifies whether the string fields in *ErrorInfo* are copied to the default system heap, at which point ownership of those buffers is transferred to the caller.

TRUE indicates the strings are to be copied to the system heap.

FALSE indicates the strings in *ErrorInfo* point to internal RPC data structures; the caller cannot free or write to them, and they become invalid once the
[RpcErrorEndEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorendenumeration) function is called.

### `ErrorInfo` [out]

Pointer to an
[RPC_EXTENDED_ERROR_INFO](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_extended_error_info) structure. See Remarks.

## Return value

If *CopyStrings* is false the function call cannot fail unless its parameters are invalid. When the last extended error record is retrieved,
**RpcErrorGetNextRecord** returns RPC_S_OK. Any subsequent calls return RPC_S_ENTRY_NOT_FOUND.

Upon any error, the enumeration position is not advanced.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Upon input, the following fields must be set in *ErrorInfo*:

* **Version** must be set to RPC_EEINFO_VERSION.
* **NumberOfParameters** must be set to a value between zero and MaxNumberOfEEInfoParams. Callers are free to provide space for any number of parameters. If the number of parameters provided by the caller is smaller than the number of parameters in the extended error record, RPC_S_BUFFER_TOO_SMALL is returned.
* **Flags** must be zero, or **EEInfoUseFileTime** must be specified. If **Flags** is zero, the **SystemTime** member of the u union is used. If **EEInfoUseFileTime** is specified, the **FileTime** member of the u union is used.

Other fields of *ErrorInfo* are ignored on input.

Upon output, the fields in *ErrorInfo* are filled as follows:

* **Version** is unchanged.
* **ComputerName** is **NULL** if there is no computer name in the record, or a Unicode string if a computer name does exist in the extended error information record. If **NULL**, the last record with a computer name can be assumed, however, the computer name may have been dropped for insufficient memory. **ComputerName** is a non-qualified DNS name.
* **ProcessID** is the PID of the process where the record originated.
* **SystemTime** or **FileTime** is the time the record was generated, expressed in UCT, for the machine on which the record was generated. Either **FileTime** or **SystemTime** is valid, based on whether **EEInfoUseFileTime** is used.
* **GeneratingComponent** is the code for the generating component.
* **Status** is the status code for the record.
* **DetectionLocation** is the code for the detection location.
* **Flags** specifies whether records are missing. If one or more records is missing after the current record is missing, **EEInfoNextRecordsMissing** is set. If one or more record before the current record is missing, **EEInfoPreviousRecordsMissing** is set.
* **NumberOfParameters** specifies the true number of parameters. If the caller specified space for more parameters on input than there are in the record, this field contains the number of parameters used.
* **Parameters** is the actual parameters, provided as an array of
  [RPC_EE_INFO_PARAM](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_ee_info_param) structures with **NumberOfParameters** structures.

## See also

[Obtaining Extended RPC Error Information](https://learn.microsoft.com/windows/desktop/Rpc/obtaining-extended-rpc-error-information)

[RPC_EE_INFO_PARAM](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_ee_info_param)

[RPC_ERROR_ENUM_HANDLE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_error_enum_handle)

[RPC_EXTENDED_ERROR_INFO](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_extended_error_info)

[RpcErrorEndEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorendenumeration)

[RpcErrorStartEnumeration](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcerrorstartenumeration)