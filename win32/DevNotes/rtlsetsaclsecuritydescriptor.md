# RtlSetSaclSecurityDescriptor function

Adds the suppled SACL to the specified security descriptor.

## Parameters

### SecurityDescriptor [in, out]

The security descriptor to be updated with a new SACL.

### SaclPresent [in]

A Boolean variable that indicates wether the SACL present flag should be set in the specified security descriptor.

### PACL [in]

A pointer to the SACL to write to the specified by SecurityDescriptor parameter. If NULL, a NULL SACL is written to the security descriptor.

### SaclDefaulted [in]

If present, supplies a pointer to a variable which, on success, receives a pointer to the base name portion of the output NT path name.

## Return value

An NTSTATUS code. For more information, see [Using NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. The API is exported from ntdll.dll.

## Requirements

| Requirement | Value |
|-----------------------------------|-------------------------------------------------------------------------------------------------------|
| DLL | ntdll.dll |