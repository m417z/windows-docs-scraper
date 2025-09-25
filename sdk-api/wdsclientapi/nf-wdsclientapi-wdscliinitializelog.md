# WdsCliInitializeLog function

## Description

Initializes logging for the WDS client.

## Parameters

### `hSession` [in]

A handle to a session with a WDS server. This was a handle returned by
the [WdsCliCreateSession](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclicreatesession) function.

### `ulClientArchitecture` [in]

A constant that identifies the processor architecture of the client.

This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **PROCESSOR_ARCHITECTURE_AMD64**<br><br>9 | The image is an x64 image (AMD AMD64 or Intel EM64T). |
| **PROCESSOR_ARCHITECTURE_IA64**<br><br>6 | The image is an Itanium-based system image. |
| **PROCESSOR_ARCHITECTURE_INTEL**<br><br>0 | The image is a 32-bit Intel x86 image. |

### `pwszClientId` [in]

A pointer to a string value that contains a GUID that represents this WDS client. This is typically the GUID for the System Management BIOS (SMBIOS.)

### `pwszClientAddress` [in]

A pointer to a string value that contains the network address of the WDS client. This is typically the IP address in string form, for example,
"127.0.0.1".

## Return value

If the function succeeds, the return is **S_OK**.

If logging has already been initialize for the session, the return value is
**HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)**.

## See also

[WdsCliClose](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliclose)

[WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage)

[WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage)

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)