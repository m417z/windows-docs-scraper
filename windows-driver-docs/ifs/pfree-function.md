# PFREE_FUNCTION function pointer

A file system legacy filter driver can register a **PFREE_FUNCTION** typed routine as the filter's *FreeCallback* callback routine. The file system calls *FreeCallback* when the file system removes a file context object by using [**FsRtlTeardownPerFileContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperfilecontexts) or removes a stream context object by using [**FsRtlTeardownPerStreamContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts).

You must declare the callback routine by using the **FREE_FUNCTION** type. For more information, see the example in the Remarks section.

## Parameters

- **Buffer** [in]: A pointer to the [**FSRTL_PER_FILE_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_per_file_context) or the [**FSRTL_PER_STREAM_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_per_stream_context) structure to be freed.

## Return value

None

## Remarks

When a file system tears down the per-file context object for a file, it must call [**FsRtlTeardownPerFileContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperfilecontexts). This routine calls the *FreeCallback* routines of all per-file context structures associated with the file. This callback routine must free any memory used for the [**FSRTL_PER_FILE_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_per_file_context) object and any associated context information. This is also the case for per-stream contexts when [**FsRtlTeardownPerStreamContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts) is called and *FreeCallback* will free memory used for [**FSRTL_PER_STREAM_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_per_stream_context) objects.

For remarks about synchronizing access to per-file context objects or to per-stream context objects during a call to *FreeCallback*, see [**FsRtlTeardownPerFileContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperfilecontexts) and [**FsRtlTeardownPerStreamContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts).

> [!NOTE]
> The *FreeCallback* routine cannot recursively call down into the file system or acquire any file system resources.

To define a *FreeCallback* callback function that is named *MyFreeFunction*, you must first provide a function declaration that the [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows:

```cpp
FREE_FUNCTION MyFreeFunction;
```

And then implement your callback function as follows:

```cpp
VOID
 MyFreeFunction (
 __in PVOID Buffer
    )
  {...}
```

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Minimum supported client | Windows Vista |
| Header | *Wdm.h* (include *Wdm.h* or *Ntddk.h*) |
| IRQL | <= APC_LEVEL |

## See also

[**FsRtlTeardownPerFileContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperfilecontexts)

[**FsRtlTeardownPerStreamContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlteardownperstreamcontexts)

[**FSRTL_PER_FILE_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_per_file_context)

[**FSRTL_PER_STREAM_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_per_stream_context)

[Tracking Per-File Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/tracking-per-file-context-in-a-legacy-file-system-filter-driver)

[Tracking Per-Stream Context in a Legacy File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/file-streams--stream-contexts--and-per-stream-contexts)