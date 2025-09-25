# SecMakeSPNEx2 function

## Description

**SecMakeSPNEx2** creates a service provider name string that can be used when it communicates with specific security service providers.

## Parameters

### `ServiceClass` [in]

A pointer to a Unicode string that specifies the service class for the security service provider.

### `ServiceName` [in]

A pointer to a Unicode string that specifies the service name for the security service provider.

### `InstanceName` [in, optional]

A pointer to an optional Unicode string that specifies the instance name that is used to connect with the security service provider.

### `InstancePort` [in, optional]

Port number for an instance of the service. Use 0 for the default port. If this parameter is zero, the SPN does not include a port number.

### `Referrer` [in, optional]

Pointer to a constant null-terminated string that specifies the DNS name of the host that gave an IP address referral. This parameter is ignored unless the **ServiceName** parameter specifies an IP address.

### `InTargetInfo` [in, optional]

A pointer to a null-terminated string that indicates the target of the context.

### `Spn` [in, out]

A pointer to a Unicode string that receives the security service provider name string that is created by this function.

### `TotalSize` [out, optional]

Pointer to a ULONG that receives the actual length of the SPN created, including the terminating null character.

### `Allocate` [in]

A Boolean variable that indicates if the memory that is used to store the **Spn** Unicode string should be allocated by this function. If this parameter is TRUE, memory for **Spn** will be allocated from paged pool.

### `IsTargetInfoMarshaled` [in]

A Boolean variable that indicates that the caller provided a marshaled **InTargetInfo** structure. If **IsTargetInfoMarshaled** is TRUE, **InTargetInfo**->Buffer points to a string representation of the CREDENTIAL_TARGET_INFORMATION structure as returned by the **CredMarshalTargetInfo** function.

## Return value

**SecMakeSPNEx2** returns STATUS_SUCCESS on success or one of the following error codes on failure.

| Return code | Description |
| ----------- | ----------- |
| STATUS_BUFFER_OVERFLOW | The **Allocate** parameter was set to false and one of the following conditions occurred: (1) The **Spn** parameter was a NULL pointer. (2) The maximum length for the **Spn** Unicode string parameter was too small. |
| STATUS_INVALID_PARAMETER | A total length of the **Spn** parameter exceeds 65535 bytes. |
| STATUS_NO_MEMORY | The **Allocate** parameter was set to true, but the memory allocation request failed. |

## Remarks

**SecMakeSPNEx2** is an enhanced version of **SecMakeSPNEx**.

## See also

[**SecMakeSPN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secmakespn)

[**SecMakeSPNEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secmakespnex)