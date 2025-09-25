## Description

A PSHED plug-in's *GetAllErrorSources* callback function returns a list of error source descriptor structures that represents all of the error sources that are implemented by the hardware platform.

## Parameters

### `PluginContext` [in, out, optional]

A pointer to the context area that was specified in the **Context** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure when the PSHED plug-in called the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

### `Count` [in, out]

A pointer to a ULONG-typed variable. When the *GetAllErrorSources* callback function is called, this variable contains the number of error source descriptor structures that are contained in the buffer pointed to by the *ErrorSources* parameter as provided by the PSHED. If the *GetAllErrorSources* callback function changes the number of error source descriptor structures that are in the buffer, it must set this variable to the new number of error source descriptor structures before it returns.

### `ErrorSrcs` [in, out]

A pointer to a buffer that receives an array of [**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structures that represents all of the error sources that are implemented by the hardware platform. When the *GetAllErrorSources* callback function is called, this buffer contains an initial list of error source descriptor structures that is provided by the PSHED. The PSHED plug-in can make changes to the list so that it accurately represents all of the error sources that are implemented by the hardware platform.

### `Length` [in, out]

A pointer to a ULONG-typed variable that contains the size, in bytes, of the buffer pointed to by the *ErrorSources* parameter. If the size is too small to contain the modified list of error source descriptor structures, the *GetAllErrorSources* callback function sets this variable to the buffer size that is required to contain the list and returns STATUS_BUFFER_TOO_SMALL.

## Return value

A PSHED plug-in's *GetAllErrorSources* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | The modified list of error source descriptor structures was successfully returned in the buffer pointed to by the *ErrorSources* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The size of the buffer pointed to by the *ErrorSources* parameter is too small to contain the list of error source descriptor structures. |
| **STATUS_UNSUCCESSFUL** | An error occurred. |

## Remarks

A PSHED plug-in that participates in error source discovery sets the **Callbacks.GetAllErrorSources** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its *GetAllErrorSources* callback function when the plug-in calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED. The PSHED plug-in must also set the **PshedFADiscovery** flag in the **FunctionalAreaMask** member of the **WHEA_PSHED_PLUGIN_REGISTRATION_PACKET** structure.

When the operating system starts, the Windows kernel calls into the PSHED to retrieve the list of error source descriptor structures that represents all of the error sources that are implemented by the hardware platform. The PSHED creates an initial list of error source descriptor structures. If a PSHED plug-in is registered to participate in error source discovery, the PSHED calls the PSHED plug-in's *GetAllErrorSources* callback function. The PSHED plug-in can make any combination of the following changes to the list of error source descriptor structures so that it accurately represents all of the error sources that are implemented by the hardware platform.

- Modify the contents of one or more of the error source descriptor structures.

- Remove one or more of the error source descriptor structures from the list.

- Add one or more new error source descriptor structures to the list.

If the PSHED plug-in must add one or more new error source descriptor structures to the list and the size of the buffer is too small to include the additional structures, the PSHED plug-in's *GetAllErrorSources* callback function must set the variable pointed to by the *Length* parameter to the buffer size that is required to contain the list with the additional structures and return STATUS_BUFFER_TOO_SMALL. In this situation, the PSHED will allocate a larger buffer, copy the list of error source descriptor structures into the new buffer, and call the PSHED plug-in's *GetAllErrorSources* callback function a second time.

A PSHED plug-in that participates in error source discovery can also implement an optional [GetErrorSourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_error_source_info) callback function. In this situation, the PSHED plug-in also sets the **Callbacks.GetErrorSourceInfo** member of the [**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet) structure to point to its *GetErrorSourceInfo* callback function when it calls the [PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin) function to register itself with the PSHED.

## See also

[GetErrorSourceInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_error_source_info)

[PshedRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pshedregisterplugin)

[**WHEA_ERROR_SOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[**WHEA_PSHED_PLUGIN_REGISTRATION_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pshed_plugin_registration_packet)