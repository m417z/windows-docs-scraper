## Description

Launches a process inside the container.

## Parameters

### `process`

The process to launch.

### `arguments`

The arguments to pass to the process.

### `workingDirectory`

The working directory of the process.

## Return value

Returns an **HRESULT** success or error code.

## Remarks

> [!WARNING]
> This is a deprecated API.

This process must exist inside the container already either by being in windows image itself, or in a folder that is shared in through the [ShareDirectory](https://learn.microsoft.com/windows/win32/api/isolatedapplauncher/nf-isolatedapplauncher-iisolatedprocesslauncher-sharedirectory) API. The process being launched here has to be Microsoft-signed to launch successfully, or else it will be blocked by Code Integrity policy. It also needs to show some UI to the user within 30 seconds. This function dictates all the restrictions third party needs to follow in order to work in a Microsft Defender Application Guard (MDAG) Edge environment.

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

[ShareDirectory](https://learn.microsoft.com/windows/win32/api/isolatedapplauncher/nf-isolatedapplauncher-iisolatedprocesslauncher-sharedirectory)