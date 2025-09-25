## Description

The **QUERY_ON_CREATE_SECURITY_INFORMATION** structure is used to write file information when [**FltRequestSecurityInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestsecurityinfooncreatecompletion) is called in pre-create.

## Members

### `Reserved`

This is undefined and reserved for future use.

### `SecurityDescriptorSize`

Size, in bytes, of the SecurityDescriptor buffer.

### `SecurityDescriptor`

Pointer to a buffer that receives a copy of the security descriptor for the specified object. The [**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure is returned in self-relative format.

## Remarks

The system allocates this structure and the file system fills in the requested information, if supported, while it processes a file create. Filter Manager will eventually free the allocated structure.

## See also

[**FltQuerySecurityObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltquerysecurityobject)

[**FltRequestFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestfileinfooncreatecompletion)

[**FltRetrieveFileInfoOnCreateCompletionEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletionex)