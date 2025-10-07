# NtRemoveIoCompletion function

Removes an entry from an I/O completion object. If there are currently no entries available, then the calling thread waits for an entry.

## Parameters

### IoCompletionHandle [in]

A handle to an I/O completion object.

### KeyContext [out]

A pointer to a variable that receives the key context that was specified when the I/O completion object was associated with a file object.

### ApcContext [out]

A pointer to a variable that receives the context that was specified when the I/O operation was issued.

### IoStatusBlock [out]

A pointer to a variable that receives the I/O completion status.

### Timeout [in, optional]

A pointer to an optional time out value.

## Return value

An NTSTATUS code. For more information, see [Using NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

IO_STATUS_BLOCK has the following definition.

```cpp
typedef struct _IO_STATUS_BLOCK {
    union {
        NTSTATUS Status;
        PVOID Pointer;
    } DUMMYUNIONNAME;

    ULONG_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;
```

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. The API is exported from ntdll.dll.

## Requirements

| Requirement | Value |
|-----------------------------------|-------------------------------------------------------------------------------------------------------|
| DLL | ntdll.dll |