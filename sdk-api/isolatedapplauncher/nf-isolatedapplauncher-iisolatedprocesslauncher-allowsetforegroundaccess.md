## Description

Allows the remote window to reflecting what is going on in the container.

## Parameters

### `pid`

The process ID.

## Return value

Returns an **HRESULT** success or error code.

## Remarks

> [!WARNING]
> This is a deprecated API.

#### Examples

The following example shows how to use the `AllowSetForegroundAccess` method.

```cpp
wil::com_ptr<IIsolatedProcessLauncher> isolatedProcessLauncher;

THROW_IF_FAILED(CoCreateInstance(
    CLSID_IsolatedAppLauncher,
    NULL,
    CLSCTX_LOCAL_SERVER,
    IID_PPV_ARGS(&isolatedProcessLauncher)));

THROW_IF_FAILED(isolatedProcessLauncher->AllowSetForegroundAccess(GetCurrentProcessId()));
```

## See also