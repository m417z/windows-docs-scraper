# PFNRASGETBUFFER callback function

## Description

The custom-scripting DLL calls
*RasGetBuffer* to allocate memory for sending or receiving data over the port connected to the server.

## Parameters

### `ppBuffer`

Pointer to a pointer that receives the address of the returned buffer.

### `pdwSize`

Pointer to a **DWORD** variable that, on input, contains the requested size of the buffer. On output, this variable contains the actual size of the buffer allocated.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is the following error code.

| Value | Meaning |
| --- | --- |
| **ERROR_OUT_OF_BUFFERS** | RAS cannot allocate anymore buffer space. |

## Remarks

The maximum buffer size that can be obtained is 1500 bytes.

The custom-scripting DLL calls
*RasGetBuffer* through a function pointer. The function pointer is passed to the custom-scripting DLL as a parameter when RAS calls the DLL's implementation of
[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn).

## See also

[RAS Custom-Scripting](https://learn.microsoft.com/windows/desktop/RRAS/ras-custom-scripting)

[RasCustomScriptExecute](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomscriptexecutefn)

[RasFreeBuffer](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-pfnrasfreebuffer)