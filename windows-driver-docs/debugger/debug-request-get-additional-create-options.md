# DEBUG\_REQUEST\_GET\_ADDITIONAL\_CREATE\_OPTIONS control code

The DEBUG\_REQUEST\_GET\_ADDITIONAL\_CREATE\_OPTIONS [**Request**](https://learn.microsoft.com/windows-hardware/drivers/debugger/request) operation returns the default process creation options.

## Parameters

*InBuffer*
Not used.

*OutBuffer*
The default process creation options. The type of the process creation options is [**DEBUG\_CREATE\_PROCESS\_OPTIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_create_process_options).

## Remarks

The default process creation options are used by methods [**CreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocess) and [**CreateProcessAndAttach**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach) which, unlike [**CreateProcess2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocess2) and [**CreateProcessAndAttach2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2), do not specify the full range of process creation options.

The **CreateFlags** field of the [**DEBUG\_CREATE\_PROCESS\_OPTIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_create_process_options) structure is not used as a default because all process creation operations provide this information.

## See also

[**Request**](https://learn.microsoft.com/windows-hardware/drivers/debugger/request)

[**DEBUG\_REQUEST\_SET\_ADDITIONAL\_CREATE\_OPTIONS**](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-set-additional-create-options)

[**DEBUG\_CREATE\_PROCESS\_OPTIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_create_process_options)

[**CreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocess)

[**CreateProcessAndAttach**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach)

