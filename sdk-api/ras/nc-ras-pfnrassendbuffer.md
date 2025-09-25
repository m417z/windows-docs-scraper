# PFNRASSENDBUFFER callback function

## Description

The custom-scripting DLL calls the
*RasSendBuffer* function to send data to the server over the specified port.

The [PFNRASSENDBUFFER](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn) type of the **RasCustomScriptExecute** callback defines a pointer to this function. *RasSendBuffer* is a placeholder for the application-defined function name.

## Parameters

### `hPort`

Handle to the port on which to send the data in the buffer. This handle should be the handle passed in by RAS as the first parameter of the
[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn) function.

### `pBuffer`

Pointer to a buffer of data to send over the port specified by the *hPort* parameter. Obtain this buffer using
[RasGetBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasgetbuffer) function.

### `dwSize`

Specifies the size of the data in the buffer pointed to by the *pBuffer* parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value can be one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_BUFFER_INVALID** | The pointer to the buffer passed in the *pBuffer* parameter is invalid. |
| **ERROR_INVALID_PORT_HANDLE** | The handle specified by the *hPort* parameter is invalid. |

## Remarks

The custom-scripting DLL calls
*RasSendBuffer* through a function pointer. The function pointer is passed to the custom-scripting DLL as a parameter when RAS calls the DLL's implementation of
[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn).

## See also

[RAS Custom-Scripting](https://learn.microsoft.com/windows/desktop/RRAS/ras-custom-scripting)

[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn)

[RasReceiveBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasreceivebuffer)

[RasRetrieveBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasretrievebuffer)