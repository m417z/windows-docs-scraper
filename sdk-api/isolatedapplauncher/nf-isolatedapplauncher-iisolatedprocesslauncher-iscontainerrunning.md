## Description

Determines if a container is running or suspended.

## Parameters

### `running`

The *running* parameter is set to **true** if the container is running, or **false** if the container is suspended.

## Return value

Returns an **HRESULT** success or error code.

## Remarks

> [!WARNING]
> This is a deprecated API.

#### Examples

The following example shows how to use the `IsContainerRunning` method.

```cpp
wil::com_ptr<IIsolatedProcessLauncher> isolatedProcessLauncher;

THROW_IF_FAILED(CoCreateInstance(
    CLSID_IsolatedAppLauncher,
    NULL,
    CLSCTX_LOCAL_SERVER,
    IID_PPV_ARGS(&isolatedProcessLauncher)));

BOOL isRunning;
THROW_IF_FAILED(isolatedProcessLauncher->IsContainerRunning(&isRunning));
LogMessage(L"Container is %s.", isRunning ? L"running" : L"suspended");
```

## See also