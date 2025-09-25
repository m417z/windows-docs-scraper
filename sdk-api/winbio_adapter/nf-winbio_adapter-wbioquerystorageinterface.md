# WbioQueryStorageInterface function

## Description

Retrieves a pointer to the [WINBIO_STORAGE_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_storage_interface) structure for the storage adapter.

## Parameters

### `StorageInterface` [out]

Address of a variable that receives a pointer to the [WINBIO_STORAGE_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_storage_interface) structure.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| ****E_POINTER**** | The *StorageInterface* parameter cannot be **NULL**. |

## Remarks

The Windows Biometric Framework calls this function after loading a storage adapter DLL into memory.
Every storage adapter DLL must therefore implement and export the **WbioQueryStorageInterface** function. The function name is case-sensitive, and its spelling and signature must exactly match that provided in the Syntax section.

To be visible to the Windows Biometric Framework, the **WbioQueryStorageInterface** function must be named in the EXPORTS section of the export definition linker command file for the DLL.

#### Examples

The following pseudocode shows one possible implementation of this function.

```cpp
HRESULT
WINAPI
WbioQueryStorageInterface(
    __out PWINBIO_STORAGE_INTERFACE *StorageInterface
    )
{
    *StorageInterface = &g_StorageInterface;
    return S_OK;
}
```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)