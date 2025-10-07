# LdrFastFailInLoaderCallout function

\[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.\]

This function forcefully terminates the calling program if it is invoked inside a loader callout. Otherwise, it has no effect.

## Parameters

This function has no parameters.

## Return value

This function does not return a value.

## Remarks

This routine does not catch all potential deadlock cases; it is possible for a thread inside a loader callout to acquire a lock while some thread outside a loader callout holds the same lock and makes a call into the loader. In other words, there can be a lock order inversion between the loader lock and a client lock.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------|
| Library<br> | NTDll.lib |
| DLL<br> | NTDll.dll |

