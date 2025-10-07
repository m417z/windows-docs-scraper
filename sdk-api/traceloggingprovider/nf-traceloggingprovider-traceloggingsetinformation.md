## Description

Configures a TraceLogging provider by calling
[EventSetInformation](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventsetinformation).

## Parameters

### `hProvider`

Handle to the TraceLogging provider to be configured. The provider must be in
the [registered](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingregister) state.

### `informationClass`

The [EVENT_INFO_CLASS](https://learn.microsoft.com/windows/win32/api/evntprov/ne-evntprov-event_info_class) of the
setting to be configured.

### `pvInformation`

The input buffer with the value of the setting to be configured. The format of
this buffer depends on the value of the _informationClass_ parameter.

### `cbInformation`

The size, in bytes, of the data in the input buffer.

## Return value

If you call this function from user-mode code, the function returns an
`HRESULT`. Use the `SUCCEEDED()` macro to determine whether the function
succeeds.

If you call this function from kernel-mode code, the function returns an
`NTSTATUS`. Use the `NT_SUCCESS()` macro to determine whether the function
succeeds.

## Remarks

This function serves as a wrapper around the
[EventSetInformation](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventsetinformation) function.

The **EventSetInformation** function is not available on all versions of
Windows. The default behavior of **TraceLoggingSetInformation** depends on the
compile-time values of the `WINVER` (user-mode) or `NTDDI_VERSION` (kernel-mode)
macros:

- If the target version of Windows (as specified by `WINVER` or `NTDDI_VERSION`)
is known to support **EventSetInformation** then
  **TraceLoggingSetInformation** will directly invoke **EventSetInformation**.
- Otherwise, **TraceLoggingSetInformation** will use **GetProcAddress**
(user-mode) or **MmGetSystemRoutineAddress** (kernel-mode) to locate and
invoke **EventSetInformation**. If this fails, **TraceLoggingSetInformation**
will return `HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)` (user-mode) or
`STATUS_NOT_SUPPORTED` (kernel-mode).

To override the default behavior of this function, define the
`TLG_HAVE_EVENT_SET_INFORMATION` macro before you
`#include <TraceLoggingProvider.h>`:

- If you `#define TLG_HAVE_EVENT_SET_INFORMATION 0` then
  **TraceLoggingSetInformation** will do nothing and return
`HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)` (user-mode) or
`STATUS_ENTRYPOINT_NOT_FOUND` (kernel-mode).
- If you `#define TLG_HAVE_EVENT_SET_INFORMATION 1` then
  **TraceLoggingSetInformation** will directly invoke **EventSetInformation**.
- If you `#define TLG_HAVE_EVENT_SET_INFORMATION 2` then
  **TraceLoggingSetInformation** will invoke **EventSetInformation** via
  **GetProcAddress** (user-mode) or **MmGetSystemRoutineAddress** (kernel-mode).

For additional information, refer to the comments in the
`TraceLoggingProvider.h` header regarding the `TLG_HAVE_EVENT_SET_INFORMATION`
macro.

## See also

[TraceLoggingRegister](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingregister)

[EventSetInformation](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventsetinformation)

[EVENT_INFO_CLASS](https://learn.microsoft.com/windows/win32/api/evntprov/ne-evntprov-event_info_class)