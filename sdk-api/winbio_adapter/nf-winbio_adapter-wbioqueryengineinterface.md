# WbioQueryEngineInterface function

## Description

Retrieves a pointer to the [WINBIO_ENGINE_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_engine_interface) structure for the engine adapter.

## Parameters

### `EngineInterface` [out]

Address of a variable that receives a pointer to the [WINBIO_ENGINE_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_engine_interface) structure.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| ****E_POINTER**** | The *EngineInterface* parameter cannot be **NULL**. |

## Remarks

The Windows Biometric Framework calls this function after loading an engine adapter DLL into memory.
Every engine adapter DLL must therefore implement and export the **WbioQueryEngineInterface** function. The function name is case-sensitive, and its spelling and signature must exactly match that provided in the Syntax section.

To be visible to the Windows Biometric Framework, the **WbioQueryEngineInterface** function must be named in the EXPORTS section of the export definition linker command file for the DLL.

#### Examples

The following pseudocode shows one possible implementation of this function.

```cpp
HRESULT
WINAPI
WbioQueryEngineInterface(
    __out PWINBIO_ENGINE_INTERFACE *EngineInterface)
{
    // g_EngineInterface is a global variable.
    *EngineInterface = &g_EngineInterface;
    return S_OK;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)