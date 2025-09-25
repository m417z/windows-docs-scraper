# MFStartup function

## Description

Initializes Microsoft Media Foundation.

## Parameters

### `Version`

Version number. Use the value **MF_VERSION**, defined in mfapi.h.

### `dwFlags`

This parameter is optional when using C++ but required in C. The value must be one of the following flags:

| Value | Meaning |
| --- | --- |
| MFSTARTUP_NOSOCKET | Do not initialize the sockets library. |
| MFSTARTUP_LITE | Equivalent to MFSTARTUP_NOSOCKET. |
| MFSTARTUP_FULL | Initialize the entire Media Foundation platform. This is the default value when *dwFlags* is not specified. |

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_BAD_STARTUP_VERSION** | The *Version* parameter requires a newer version of Media Foundation than the version that is running. |
| **MF_E_DISABLED_IN_SAFEMODE** | The Media Foundation platform is disabled because the system was started in "Safe Mode" (fail-safe boot). |
| **E_NOTIMPL** | Media Foundation is not implemented on the system. This error can occur if the media components are not present (See [KB2703761](https://support.microsoft.com/help/2703761) for more info). |

## Remarks

An application must call this function before using Media Foundation. Before your application quits, call [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) once for every previous call to **MFStartup**.
**MFStartup** should be called during should be called during app initialization and not from static constructors during process initialization.

Do not call **MFStartup** or [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) from work queue threads. For more information about work queues, see [Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues).

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

#### Examples

```cpp
    hr = MFStartup(MF_VERSION);

```

## See also

[Initializing Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/initializing-media-foundation)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)