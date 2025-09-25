## Description

Launches a process in an isolated environment.

## Parameters

### `process`

The process to launch.

### `arguments`

### `workingDirectory`

The working directory of the process.

### `correlationGuid`

The correlation GUID to associate with the process.

## Return value

Returns an **HRESULT** success or error code.

## Remarks

> [!WARNING]
> This is a deprecated API.

#### Examples

This example assumes `c:\hostfolder1` is already shared into the container by following the [ShareDirectory](https://learn.microsoft.com/windows/win32/api/isolatedapplauncher/nf-isolatedapplauncher-iisolatedprocesslauncher-sharedirectory) example.

```cpp
wil::com_ptr<IIsolatedProcessLauncher2> isolatedProcessLauncher;

THROW_IF_FAILED(CoCreateInstance(
    CLSID_IsolatedAppLauncher,
    NULL,
    CLSCTX_LOCAL_SERVER,
    IID_PPV_ARGS(&isolatedProcessLauncher)));

THROW_IF_FAILED(isolatedProcessLauncher->LaunchProcess(
    L"c:\\hostfolder1\\sampleprocess.exe",
    L"",
    L""));

GUID correlationGuid;
THROW_IF_FAILED(CoCreateGuid(&correlationGuid));

THROW_IF_FAILED(isolatedProcessLauncher->LaunchProcess2(
    L"c:\\hostfolder1\\sampleprocess.exe",
    L"",
    L"",
    correlationGuid));
```

## See also