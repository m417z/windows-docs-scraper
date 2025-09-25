## Description

**FltMupGetProviderInfoFromFileObject** retrieves the provider information corresponding to a file object.

## Parameters

### `Instance`

[in] Opaque pointer to the filter instance associated with this file object. This parameter is required and can't be NULL.

### `FileObject`

[in] Pointer to the file object for which the provider information is to be retrieved. This parameter is required and can't be NULL.

### `Level`

[in] The level of information that this routine should return. For more information about the possible values for this parameter, see [**FsRtlMupGetProviderInfoFromFileObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlmupgetproviderinfofromfileobject).

### `Buffer`

[out] Pointer to a buffer that receives the provider information. The returned data is based on the specified **Level**. This buffer must be large enough to hold the information requested by the Level parameter.

### `BufferSize`

[in/out] Pointer to a variable that specifies the size, in bytes, of the buffer that is pointed to by the **Buffer** parameter. On input, this variable specifies the size of the buffer. On output, this variable receives the number of bytes that were written to the buffer.

## Return value

**FltMupGetProviderInfoFromFileObject** returns STATUS_SUCCESS if the operation is successful. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

This routine is needed to handle the case of providers that register using
[**FsRtlRegisterUncProviderEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncproviderex). The device name on the file objects for such provider would be *\Device\Mup*.

Filters can use this routine for the following purposes:

* To be able to filter specific redirectors.
* To find a redirector backing a file object so that they can work around possible bugs in redirectors.

The MUP (multiple UNC provider) can't be unloaded for this call.

The caller guarantees that the **FileObject** will be valid for the duration of the call.

## See also

[**FsRtlMupGetProviderInfoFromFileObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlmupgetproviderinfofromfileobject)

[**FsRtlRegisterUncProviderEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncproviderex)