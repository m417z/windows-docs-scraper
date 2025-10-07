WINBASEAPI
__out
HANDLE
WINAPI
RegisterWaitForSingleObjectEx(
    __in     HANDLE hObject,
    __in     WAITORTIMERCALLBACK Callback,
    __in_opt PVOID Context,
    __in     ULONG dwMilliseconds,
    __in     ULONG dwFlags
    );