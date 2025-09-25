# FsRtlMupGetProviderInfoFromFileObject function

## Description

The **FsRtlMupGetProviderInfoFromFileObject** routine gets information about a network redirector that is registered with the multiple UNC provider (MUP) from a file object for a file that is located on a remote file system.

## Parameters

### `pFileObject` [in]

A pointer to a file object of a file that is located on a remote file system.

### `Level` [in]

The level of information that is returned by the **FsRtlMupGetProviderInfoFromFileObject** routine. For more information about the possible values for this parameter, see the Remarks section.

### `pBuffer` [out]

A pointer to a buffer that receives the information that is returned by the **FsRtlMupGetProviderInfoFromFileObject** routine. For more information about the format of the data that is returned in this buffer, see the Remarks section.

### `pBufferSize` [in, out]

A pointer to a ULONG-typed variable that contains the size, in bytes, of the buffer that is pointed to by the *pBuffer* parameter. If the routine succeeds, this variable receives the size, in bytes, of data that is returned in the buffer.

## Return value

The **FsRtlMupGetProviderInfoFromFileObject** routine returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The information about the network redirector was successfully returned in the buffer that is pointed to by the *pBuffer* parameter. |
| **STATUS_INVALID_PARAMETER** | One of the parameters was **NULL** or contained an invalid value. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The file object that is pointed to by the *pFileObject* parameter does not correspond to a completely opened remote file system file object. |
| **STATUS_BUFFER_TOO_SMALL** | The size of the buffer that is pointed to by the *pBuffer* parameter is too small to return any data. In this situation, the variable that is pointed to by the *pBufferSize* parameter receives the required size, in bytes, of the buffer. |
| **STATUS_BUFFER_OVERFLOW** | The size of the buffer that is pointed to by the *pBuffer* parameter is too small to return all of the data. Only the data that would fit in the buffer was returned. In this situation, the variable that is pointed to by the *pBufferSize* parameter receives the required size, in bytes, of the buffer. |

## Remarks

A file system filter driver can call the **FsRtlMupGetProviderInfoFromFileObject** routine to get information about a network redirector from a file object for a file that is located on a remote file system. The amount of information that is returned by the **FsRtlMupGetProviderInfoFromFileObject** routine depends on the value of the *Level* parameter. If the *Level* parameter is set to 1, the **FsRtlMupGetProviderInfoFromFileObject** routine returns a FSRTL_MUP_PROVIDER_INFO_LEVEL_1 structure in the buffer that is pointed to by the *pBuffer* parameter. The FSRTL_MUP_PROVIDER_INFO_LEVEL_1 structure is defined as follows:

```
typedef struct _FSRTL_MUP_PROVIDER_INFO_LEVEL_1 {
  ULONG32  ProviderId;
} FSRTL_MUP_PROVIDER_INFO_LEVEL_1, *PFSRTL_MUP_PROVIDER_INFO_LEVEL_1;
```

If the *Level* parameter is set to 2, the **FsRtlMupGetProviderInfoFromFileObject** routine returns a FSRTL_MUP_PROVIDER_INFO_LEVEL_2 structure in the buffer that is pointed to by the *pBuffer* parameter. The FSRTL_MUP_PROVIDER_INFO_LEVEL_2 structure is defined as follows:

```
typedef struct _FSRTL_MUP_PROVIDER_INFO_LEVEL_2 {
  ULONG32  ProviderId;
  UNICODE_STRING  ProviderName;
} FSRTL_MUP_PROVIDER_INFO_LEVEL_2, *PFSRTL_MUP_PROVIDER_INFO_LEVEL_2;
```

A file system filter driver can quickly compare the value of the provider identifier to the value of other provider identifiers without needing to do a string comparison.

The value of the UNC provider identifier for a particular network redirector remains the same if the network redirector is unloaded from the system and then reloaded back into the system.

To get the UNC provider identifier of a network redirector from the device name of the network redirector, a file system filter driver can call the [FsRtlMupGetProviderIdFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlmupgetprovideridfromname) routine.

## See also

[FsRtlMupGetProviderIdFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlmupgetprovideridfromname)