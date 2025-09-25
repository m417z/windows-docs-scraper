# AuxKlibQueryModuleInformation function

## Description

The **AuxKlibQueryModuleInformation** routine retrieves information about the image modules that the operating system has loaded.

## Parameters

### `BufferSize` [in, out]

A pointer to a location that contains or receives a buffer size, in bytes. If *QueryInfo* is **NULL**, the location receives the number of bytes that the driver must allocate for the array that receives the retrieved information. If *QueryInfo* is not **NULL**, the location must contain the specified number of bytes.

### `ElementSize` [in]

The size, in bytes, of each element of the array that *QueryInfo* points to. This value must be **sizeof**(**AUX_MODULE_BASIC_INFO**) or **sizeof**(**AUX_MODULE_EXTENDED_INFO**).

### `QueryInfo` [out, optional]

A pointer to an array of [AUX_MODULE_BASIC_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/ns-aux_klib-_aux_module_basic_info) or [AUX_MODULE_EXTENDED_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/ns-aux_klib-_aux_module_extended_info) structures that receives information about loaded image modules. If this pointer is **NULL**, **AuxKlibQueryModuleInformation** writes the required buffer size to the location that *BufferSize* points to.

## Return value

**AuxKlibQueryModuleInformation** returns STATUS_SUCCESS if the operation succeeds. **AuxKlibQueryModuleInformation** returns STATUS_BUFFER_TOO_SMALL if the *QueryInfo* pointer is not **NULL** and the driver-supplied *BufferSize* value is too small.

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

To obtain information about the operating system's loaded image modules, a driver must:

1. Call **AuxKlibQueryModuleInformation** with a **NULL** *QueryInfo* pointer. After **AuxKlibQueryModuleInformation** returns, the location that the *BufferSize* parameter points to will contain the number of bytes that the driver will have to allocate for the array.
2. Call a memory allocation routine, such as [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag), to allocate a buffer for the array.
3. Call **AuxKlibQueryModuleInformation** again. This time, the *QueryInfo* pointer must contain the address of the allocated buffer. After **AuxKlibQueryModuleInformation** returns, the buffer contains an array of module information.

The number of loaded modules can change between the first and second calls to **AuxKlibQueryModuleInformation**. As a result, the second call to **AuxKlibQueryModuleInformation** might return STATUS_BUFFER_TOO_SMALL even if the driver allocates a buffer that is based on the size that was obtained from the first call.

If a call to **AuxKlibQueryModuleInformation** succeeds, the routine writes an **ImageBase** value to each element in the *QueryInfo* array. Each **ImageBase** value is a pointer to the base of a loaded driver image. This pointer remains valid only while the driver remains loaded. The caller should assume that the driver can be unloaded at any time unless the caller can guarantee otherwise. For example, a driver might be unloaded between a call to **AuxKlibQueryModuleInformation** that obtains a pointer to the driver image and a call to [AuxKlibGetImageExportDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibgetimageexportdirectory) that uses this pointer.

Drivers must call [AuxKlibInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibinitialize) before calling **AuxKlibQueryModuleInformation**.

#### Examples

The following code example illustrates the steps that are listed in the preceding Remarks section.

```
NTSTATUS  status;
ULONG  modulesSize;
AUX_MODULE_EXTENDED_INFO*  modules;
ULONG  numberOfModules;
//
// Get the required array size.
//
status = AuxKlibQueryModuleInformation(
                                       &modulesSize,
                                       sizeof(AUX_MODULE_EXTENDED_INFO),
                                       NULL
                                       );

if (!NT_SUCCESS(status) || modulesSize == 0) {
    break;
    }

//
// Calculate the number of modules.
//
numberOfModules = modulesSize / sizeof(AUX_MODULE_EXTENDED_INFO);

//
// Allocate memory to receive data.
//
modules =
    (AUX_MODULE_EXTENDED_INFO*) ExAllocatePoolWithTag(
                                      PagedPool,
                                      modulesSize,
                                      '3LxF'
                                      );
if (modules == NULL) {
    status = STATUS_INSUFFICIENT_RESOURCES;
    break;
    }

RtlZeroMemory(
              modules,
              modulesSize
              );

//
// Obtain the module information.
//
status = AuxKlibQueryModuleInformation(
                                       &modulesSize,
                                       sizeof(AUX_MODULE_EXTENDED_INFO),
                                       modules
                                       );
if (!NT_SUCCESS(status)) {
    break;
    }
```

## See also

[AUX_MODULE_BASIC_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/ns-aux_klib-_aux_module_basic_info)

[AUX_MODULE_EXTENDED_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/ns-aux_klib-_aux_module_extended_info)

[AuxKlibGetImageExportDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibgetimageexportdirectory)

[AuxKlibInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibinitialize)

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)