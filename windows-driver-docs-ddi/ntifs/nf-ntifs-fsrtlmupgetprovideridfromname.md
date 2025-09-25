# FsRtlMupGetProviderIdFromName function

## Description

The **FsRtlMupGetProviderIdFromName** routine gets the provider identifier of a network redirector that is registered with the multiple UNC provider (MUP) from the device name of the network redirector.

## Parameters

### `pProviderName` [in]

A pointer to a Unicode string that contains the device name of the network redirector.

### `pProviderId` [out]

A pointer to a ULONG32-typed variable that receives the provider identifier of the network redirector.

## Return value

The **FsRtlMupGetProviderIdFromName** routine returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The provider identifier of the network redirector was successfully returned in the variable that is pointed to by the *pProviderId* parameter. |
| **STATUS_INVALID_PARAMETER** | One of the parameters is **NULL**. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The name of the network redirector specified in the *pProviderName* parameter does not match the name of any of the UNC providers that are registered with the MUP. |

## Remarks

A file system filter driver can call the **FsRtlMupGetProviderIdFromName** routine to get the provider identifier of a network redirector from the name of the network redirector. The file system filter driver can quickly compare the value of this identifier to the value of other provider identifiers without needing to do a string comparison.

The value of the provider identifier for a particular network redirector remains the same if the network redirector is unloaded from the system and then reloaded back into the system.

To get the provider identifier of a network redirector from a file object, a file system filter driver can call the [FsRtlMupGetProviderInfoFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlmupgetproviderinfofromfileobject) routine.

## See also

[FsRtlMupGetProviderInfoFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlmupgetproviderinfofromfileobject)