# GetCurrentFiber function

## Description

Retrieves the address of the current fiber.

## Return value

The macro returns the address of the currently running fiber.

## Remarks

The
[CreateFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiber) and
[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber) functions return the fiber address when the fiber is created. The
**GetCurrentFiber** macro allows you to retrieve the address at any other time.

## See also

[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber)

[CreateFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiber)

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)