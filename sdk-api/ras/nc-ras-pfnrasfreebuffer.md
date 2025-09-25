# PFNRASFREEBUFFER callback function

## Description

The custom-scripting DLL calls
*RasFreeBuffer* to release a memory buffer that was allocated by a previous call to
[RasGetBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasgetbuffer).

## Parameters

### `pBufer`

#### - pBuffer

Pointer to the memory buffer to free. This memory must have been obtained by a previous call to
[RasGetBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasgetbuffer).

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_BUFFER_INVALID** | The pointer to the buffer passed in the *pBuffer* parameter is invalid. |
| **ERROR_INVALID_PORT_HANDLE** | The handle specified by the *hPort* parameter is invalid. |

## Remarks

The custom-scripting DLL calls
*RasFreeBuffer* through a function pointer. The function pointer is passed to the custom-scripting DLL as a parameter when RAS calls the DLL's implementation of
[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn).

## See also

[RAS Custom-Scripting](https://learn.microsoft.com/windows/desktop/RRAS/ras-custom-scripting)

[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn)

[RasGetBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasgetbuffer)