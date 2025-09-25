## Description

The **IoCheckFileObjectOpenedAsCopySource** routine checks whether a file was previously opened with copy intent as a source file.

## Parameters

### `FileObject` [in]

Pointer to the source file object to check for copy intent.

## Return value

**IoCheckFileObjectOpenedAsCopySource** returns TRUE if the file object represents a source file that was previously opened with copy file intent; otherwise it returns FALSE. A return value of TRUE only signals the intent at create time; it does not mean that all operations on the file object are all part of copies.

## Remarks

The following example shows how to check if a file object was opened with copy intent.

``` C

typedef
BOOLEAN (*PIO_CHECK_FILE_OBJECT_OPENED_AS_COPY_SOURCE)(
    _In_ PFILE_OBJECT FileObject
);
typedef
BOOLEAN (*PIO_CHECK_FILE_OBJECT_OPENED_AS_COPY_DESTINATION)(
    _In_ PFILE_OBJECT FileObject
);

PIO_CHECK_FILE_OBJECT_OPENED_AS_COPY_SOURCE IoCheckFileObjectOpenedAsCopySource;
PIO_CHECK_FILE_OBJECT_OPENED_AS_COPY_DESTINATION IoCheckFileObjectOpenedAsCopyDestination;

// First resolve the API
RtlInitUnicodeString(&RoutineName, L"IoCheckFileObjectOpenedAsCopySource");
IoCheckFileObjectOpenedAsCopySource = (PIO_CHECK_FILE_OBJECT_OPENED_AS_COPY_SOURCE)MmGetSystemRoutineAddress(&RoutineName);

RtlInitUnicodeString(&RoutineName, L"IoCheckFileObjectOpenedAsCopyDestination");
IoCheckFileObjectOpenedAsCopyDestination = (PIO_CHECK_FILE_OBJECT_OPENED_AS_COPY_DESTINATION)MmGetSystemRoutineAddress(&RoutineName);

// Now use the API
IoCheckFileObjectOpenedAsCopySource(FltObjects->FileObject);
IoCheckFileObjectOpenedAsCopyDestination(FltObjects->FileObject);
```

See [Kernel-mode file copy and detecting copy file scenarios](https://learn.microsoft.com/windows-hardware/drivers/ifs/km-file-copy) for more information.

## See also

[**EXTENDED_CREATE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-extended_create_information)

[**IoCheckFileObjectOpenedAsCopyDestination**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckfileobjectopenedascopydestination)

[**NtCopyFileChunk**](https://learn.microsoft.com/windows-hardware/drivers/ifs/nf-ntifs-ntcopyfilechunk)

[**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)