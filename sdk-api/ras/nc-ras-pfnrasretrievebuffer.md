# PFNRASRETRIEVEBUFFER callback function

## Description

The custom-scripting DLL calls the
*RasRetrieveBuffer* function to obtain data received from the RAS server over the specified port. The custom-scripting DLL should call
*RasRetrieveBuffer* only after RAS has signaled the event object passed in the call to
[RasReceiveBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasreceivebuffer).

The [PFNRASRETRIEVEBUFFER](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn) type defines a pointer to this callback function. *RasRetrieveBuffer* is a placeholder for the application-defined function name.

## Parameters

### `hPort`

Handle to the port on which to receive the data. This handle should be the handle passed in by RAS as the first parameter of the
[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn) function.

### `pBuffer`

Pointer to a buffer to receive the data from the port specified by the *hPort* parameter. Obtain this buffer using
[RasGetBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasgetbuffer) function. The value of this parameter may be the same as the pointer to the buffer passed into the
[RasReceiveBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasreceivebuffer) function.

### `pdwSize`

Pointer to a **DWORD** variable that receives the size of the data returned in the buffer pointed to by the *pBuffer* parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value can be one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_BUFFER_INVALID** | The pointer to the buffer passed in the *pBuffer* parameter is invalid. |
| **ERROR_INVALID_PORT_HANDLE** | The handle specified by the *hPort* parameter is invalid. |

RAS signals the event object if the port gets disconnected for some reason before the data is posted. In this case,
*RasRetrieveBuffer* returns an error defined in Raserror.h, that indicates the cause of the failure.

## Remarks

The
*RasRetrieveBuffer* function is synchronous. When it returns, the buffer pointed to by the *pBuffer* parameter contains the data received over the specified port. The custom-scripting DLL should call
*RasRetrieveBuffer* only after RAS has signaled the event object that the DLL passed in the call to
[RasReceiveBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasreceivebuffer).

The custom-scripting DLL calls
*RasRetrieveBuffer* through a function pointer. The function pointer is passed to the custom-scripting DLL as a parameter when RAS calls the DLL's implementation of
[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn).

## See also

[RAS Custom-Scripting](https://learn.microsoft.com/windows/desktop/RRAS/ras-custom-scripting)

[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn)

[RasReceiveBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasreceivebuffer)

[RasSendBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrassendbuffer)