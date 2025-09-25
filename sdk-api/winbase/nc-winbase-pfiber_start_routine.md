# PFIBER_START_ROUTINE callback function

## Description

An application-defined function used with the
[CreateFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiber) function. It serves as the starting address for a fiber. The **LPFIBER_START_ROUTINE** type defines a pointer to this callback function.
**FiberProc** is a placeholder for the application-defined function name.

## Parameters

### `lpFiberParameter`

#### - lpParameter [in]

The fiber data passed using the *lpParameter* parameter of the
[CreateFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiber) function.

## See also

[CreateFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiber)

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)