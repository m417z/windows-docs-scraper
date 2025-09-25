# SecMakeSPNEx function

## Description

**SecMakeSPNEx** creates a service provider name string that can be used when communicating with specific security service providers.

## Parameters

### `ServiceClass` [in]

A pointer to a Unicode string specifying the service class for the security service provider.

### `ServiceName` [in]

A pointer to a Unicode string specifying the service name for the security service provider.

### `InstanceName` [in]

A pointer to an optional Unicode string specifying the instance name for connecting with the security service provider.

### `InstancePort` [in, optional]

Port number for an instance of the service. Use 0 for the default port. If this parameter is zero, the SPN does not include a port number.

### `Referrer` [in, optional]

Pointer to a constant null-terminated string that specifies the DNS name of the host that gave an IP address referral. This parameter is ignored unless the **ServiceName** parameter specifies an IP address.

### `TargetInfo` [in, optional]

A pointer to a null-terminated string that indicates the target of the context.

### `Spn` [in, out]

A pointer to a Unicode string for storing the security service provider name string created by this function.

### `Length` [out, optional]

Pointer to a ULONG that receives the actual length of the SPN created, including the terminating null character.

### `Allocate` [in]

A Boolean variable indicating if the memory for storing the **Spn** Unicode string should be allocated by this function. If this parameter is true, memory for **Spn** will be allocated from paged pool.

## Return value

**SecMakeSPNEx** returns STATUS_SUCCESS on success or one of the following error codes on failure.

| Return code | Description |
| ----------- | ----------- |
| STATUS_BUFFER_OVERFLOW | The **Allocate** parameter was set to false and one of the following conditions occurred: (1) The **Spn** parameter was a NULL pointer. (2) The maximum length for the **Spn** Unicode string parameter was too small. |
| STATUS_INVALID_PARAMETER | A total length of the **Spn** parameter exceeds 65535 bytes. |
| STATUS_NO_MEMORY | The **Allocate** parameter was set to true, but the memory allocation request failed. |

## Remarks

**SecMakeSPNEx** is an enhanced version of **SecMakeSPN**.

## See also

[**SecMakeSPN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secmakespn)

[**SecMakeSPNEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secmakespnex2)