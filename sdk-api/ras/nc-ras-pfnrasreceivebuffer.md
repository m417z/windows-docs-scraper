# PFNRASRECEIVEBUFFER callback function

## Description

The custom-scripting DLL calls the
*RasReceiveBuffer* function to inform RAS that it is ready to receive data from the server over the specified port.

The [PFNRASRECEIVEBUFFER](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn) type defines a pointer to this callback function. *RasReceiveBuffer* is a placeholder for the application-defined function name.

## Parameters

### `hPort`

Handle to the port on which to receive the data. This handle should be the handle passed in by RAS as the first parameter of the
[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn) function.

### `pBuffer`

Pointer to a buffer to receive the data from the port specified by the *hPort* parameter. Obtain this buffer using
[RasGetBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasgetbuffer) function.

### `pdwSize`

Pointer to a **DWORD** variable that receives the size of the data returned in the buffer pointed to by the *pBuffer* parameter.

### `dwTimeOut`

### `hEvent`

Handle to an event object that RAS will signal when the received data is available.

### `dwTimeout`

Specifies a time-out period in milliseconds after which the custom-scripting DLL will no longer wait for the data.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value can be one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_BUFFER_INVALID** | The pointer to the buffer passed in the *pBuffer* parameter is invalid. |
| **ERROR_INVALID_PORT_HANDLE** | The handle specified by the *hPort* parameter is invalid. |

## Remarks

*RasReceiveBuffer* is an asynchronous function.
*RasReceiveBuffer* returns immediately even if the data is not yet available. The custom-scripting DLL must wait on the event object specified by the *hEvent* parameter. When the data is available, RAS signals this event. The custom-scripting DLL should then call the
[RasRetrieveBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasretrievebuffer) function to obtain the data. The custom-scripting DLL may pass the same buffer pointer in
**RasRetrieveBuffer** that it passed in **RasReceiveBuffer**.

RAS also signals the event object if, for some reason, the port is disconnected before the data is posted. In this case,
[RasRetrieveBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasretrievebuffer) returns an error defined in Raserror.h, that indicates the cause of the failure.

The custom-scripting DLL calls
*RasReceiveBuffer* through a function pointer. The function pointer is passed to the custom-scripting DLL as a parameter when RAS calls the DLL's implementation of
[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn).

## See also

[RAS Custom-Scripting](https://learn.microsoft.com/windows/desktop/RRAS/ras-custom-scripting)

[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn)

[RasSendBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrassendbuffer)