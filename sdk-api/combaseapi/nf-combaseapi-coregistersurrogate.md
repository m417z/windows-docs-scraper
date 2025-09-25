# CoRegisterSurrogate function

## Description

Registers the surrogate process through its [ISurrogate](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isurrogate) interface pointer.

## Parameters

### `pSurrogate` [in]

A pointer to the [ISurrogate](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isurrogate) interface on the surrogate process to be registered.

## Return value

This function returns S_OK to indicate that the surrogate process was registered successfully.

## Remarks

The **CoRegisterSurrogate** function sets a global interface pointer to the [ISurrogate](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isurrogate) interface implemented on the surrogate process. This pointer is set in the ole32 DLL loaded in the surrogate process. COM uses this global pointer in ole32 to call the methods of **ISurrogate**. This function is usually called by the surrogate implementation when it is launched.

As of Windows Server 2003, if a COM object application is registered as a service, COM verifies the registration. COM makes sure the process ID of the service, in the service control manager (SCM), matches the process ID of the registering process. If not, COM fails the registration.

## See also

[ISurrogate](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isurrogate)

[Writing a Custom Surrogate](https://learn.microsoft.com/windows/desktop/com/writing-a-custom-surrogate)