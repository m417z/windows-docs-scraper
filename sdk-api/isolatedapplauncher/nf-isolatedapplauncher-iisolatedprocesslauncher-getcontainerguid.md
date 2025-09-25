## Description

Returns the container/VM Id.

## Parameters

### `guid`

The container/VM Id.

## Return value

Returns an **HRESULT** success or error code.

## Remarks

> [!WARNING]
> This is a deprecated API.

The *guid* (container Id) is a parameter needed to open hvsocket communication from host to container.

This call will fail if the container hasn't been created yet.

#### Examples

The following example shows how to use the `GetContainerGuid` method.

```cpp
wil::com_ptr<IIsolatedProcessLauncher> isolatedProcessLauncher;

THROW_IF_FAILED(CoCreateInstance(
    CLSID_IsolatedAppLauncher,
    NULL,
    CLSCTX_LOCAL_SERVER,
    IID_PPV_ARGS(&isolatedProcessLauncher)));

GUID containerId;
THROW_IF_FAILED(isolatedProcessLauncher->GetContainerGuid(&containerId));
```

## See also