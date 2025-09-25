# IoQueryFileDosDeviceName function

## Description

The **IoQueryFileDosDeviceName** routine retrieves an MS-DOS device name for a file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the file.

### `ObjectNameInformation` [out]

A returned pointer to a newly allocated **OBJECT_NAME_INFORMATION** structure. This structure is filled in on successful return with the MS-DOS device name information. The structure is defined as follows:

```
typedef struct _OBJECT_NAME_INFORMATION {
    UNICODE_STRING Name;
} OBJECT_NAME_INFORMATION, *POBJECT_NAME_INFORMATION;
```

**Note** This structure must eventually be freed by calling [ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool).

## Return value

**IoQueryFileDosDeviceName** returns STATUS_SUCCESS or an error NTSTATUS value, such as STATUS_INSUFFICIENT_RESOURCES.

## Remarks

For more information about MS-DOS names, see the Files and I/O section of the Platform Software Development Kit (SDK) documentation.

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)