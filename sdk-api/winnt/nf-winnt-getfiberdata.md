# GetFiberData function

## Description

Retrieves the fiber data associated with the current fiber.

## Return value

The macro returns the fiber data for the currently running fiber.

## Remarks

The fiber data is the value passed to the
[CreateFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiber) or
[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber) function in the *lpParameter* parameter. This value is also received as the parameter to the fiber function. It is stored as part of the fiber state information.

## See also

[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber)

[CreateFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiber)

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)