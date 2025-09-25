# NtSetInformationKey function

## Description

[This function may be changed or removed from Windows without further notice.]

Sets information for the specified registry key.

## Parameters

### `KeyHandle` [in]

A handle to the registry key. The handle must be opened with the **KEY_WRITE** access
right.

### `KeySetInformationClass` [in]

A [KEY_SET_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ne-wdm-_key_set_information_class) value that
specifies the kind of information to be set.

### `KeySetInformation` [in]

A pointer to the buffer that contains the information to be set. The format of this buffer is determined by
the *KeySetInformationClass* parameter.

### `KeySetInformationLength` [in]

The length of the buffer specified by the *KeySetInformation* parameter, in
bytes.

## Return value

Returns an **NTSTATUS** or error code. An error code of
**STATUS_INFO_LENGTH_MISMATCH** indicates that the
*KeySetInformationLength* parameter is the wrong length for the information class
specified by the *KeySetInformationClass* parameter.

The forms and significance of **NTSTATUS** error codes are listed in the Ntstatus.h
header file available in the WDK, and are described in the WDK documentation.

## Remarks

You can also use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/DevNotes/-loadlibrary) and
[GetProcAddress](https://learn.microsoft.com/windows/desktop/DevNotes/-getprocaddress-) functions to dynamically link to
Ntdll.dll.

## See also

[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights)