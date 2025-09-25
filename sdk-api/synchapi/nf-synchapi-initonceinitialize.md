# InitOnceInitialize function

## Description

Initializes a one-time initialization structure.

## Parameters

### `InitOnce` [out]

A pointer to the one-time initialization structure.

## Remarks

The **InitOnceInitialize** function is used to initialize a one-time initialization structure dynamically. To initialize the structure statically, assign the constant **INIT_ONCE_STATIC_INIT** to the structure variable.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

A one-time initialization object cannot be moved or copied. The process must not modify the initialization object, and must instead treat it as logically opaque. Only use the one-time initialization functions to manage one-time initialization objects.

#### Examples

The following example calls **InitOnceInitialize** to initialize the one-time initialization structure named `InitOnce`. Alternatively, the structure can be declared as a global variable as shown in [Using One-Time Initialization](https://learn.microsoft.com/windows/desktop/Sync/using-one-time-initialization).

```cpp

//Requires Windows Vista, Windows Server 2008 or later
#define _WIN32_WINNT 0x0600

#include <windows.h>

BOOL StartInitialization()
{
    INIT_ONCE InitOnce;

    InitOnceInitialize(&InitOnce);

    //...
    return TRUE;
}

```

## See also

[InitOnceExecuteOnce](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-initonceexecuteonce)

[One-Time Initialization](https://learn.microsoft.com/windows/desktop/Sync/one-time-initialization)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)