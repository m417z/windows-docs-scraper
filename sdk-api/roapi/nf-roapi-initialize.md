# Initialize function

## Description

Initializes a thread to use Windows Runtime APIs.

## Parameters

### `initType`

Specifies the apartment type of the thread to be initialized.

## Return value

* **S_OK** - Successfully initialized for the first time on the current thread
* **S_FALSE** - Successful nested initialization (current thread was already
  initialized for the specified apartment type)
* **E_INVALIDARG** - Invalid *initType* value
* **CO_E_INIT_TLS** - Failed to allocate COM's internal TLS structure
* **E_OUTOFMEMORY** - Failed to allocate per-thread/per-apartment structures other
  than the TLS
* **RPC_E_CHANGED_MODE** - The current thread is already initialized for a different
  apartment type from what is specified.

## Remarks

**Windows::Foundation::Initialize** is changed to create
ASTAs instead of classic STAs for the [RO_INIT_TYPE](https://learn.microsoft.com/windows/desktop/api/roapi/ne-roapi-ro_init_type)
value **RO_INIT_SINGLETHREADED**.
**Windows::Foundation::Initialize**(**RO_INIT_SINGLETHREADED**)
is not supported for desktop applications and will return **CO_E_NOTSUPPORTED** if called
from a process other than a Windows Store app.

For Microsoft DirectX applications, you must initialize the initial thread by using
**Windows::Foundation::Initialize**(**RO_INIT_MULTITHREADED**).

For an out-of-process EXE server, you must initialize the initial thread of the server by using
**Windows::Foundation::Initialize**(**RO_INIT_MULTITHREADED**).

## See also

[RO_INIT_TYPE](https://learn.microsoft.com/windows/desktop/api/roapi/ne-roapi-ro_init_type)