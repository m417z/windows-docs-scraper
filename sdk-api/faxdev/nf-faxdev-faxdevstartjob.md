# FaxDevStartJob function

## Description

The fax service calls the **FaxDevStartJob** function to initialize a new fax job. The fax service also calls **FaxDevStartJob** to signal the beginning of each fax operation to the fax service provider (FSP). Each FSP must export the **FaxDevStartJob** function.

## Parameters

### `LineHandle` [in]

Type: **HLINE**

Specifies a handle to the open line device associated with the fax job.

### `DeviceId` [in]

Type: **DWORD**

Specifies the TAPI line device identifier associated with the fax job.

### `FaxHandle` [out]

Type: **PHANDLE**

Pointer to a variable that receives a fax handle associated with the fax job. The FSP must set this handle to a meaningful value; this handle usually specifies a pointer to a block of memory with job-specific instance data.

### `CompletionPortHandle` [in]

Type: **HANDLE**

Specifies a handle to an I/O completion port. For more information, see [I/O Completion Ports](https://learn.microsoft.com/windows/desktop/FileIO/i-o-completion-ports).

### `CompletionKey` [in]

Type: **ULONG_PTR**

Specifies a completion key value. The fax service provider should pass this opaque value to the [PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **FaxDevStartJob** function provides an opportunity for the fax service provider to perform call setup.

The fax service calls **FaxDevStartJob** at the beginning of a new fax job and once for each fax operation. This is because each operation executes in a separate thread. It calls **FaxDevStartJob** just before the [FaxDevSend](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevsend) function call for a fax send operation, and just before the [FaxDevReceive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevreceive) function call for a fax receive operation. For more information, see [Operating in a Multithreaded Environment](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-operating-in-a-multithreaded-environment).

The FSP should create an I/O completion packet and call the [PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus) function when the FSP changes its status. One example of a status change is when the FSP finishes receiving or sending fax transmission pages. The completion packet must be a [FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status) structure. The FSP must allocate memory for the structure from the heap indicated by the *HeapHandle* parameter passed to the [FaxDevInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevinitialize) function. The fax service provider must pass the size of the memory allocated to the *dwNumberOfBytesTransferred* parameter of the PostQueuedCompletionStatus method. The fax service frees any memory allocated for the completion packet structure.

The FSP should use the *CompletionPortHandle* and *CompletionKey* parameters to post completion packets for FSP status changes. This method of status notification optimizes performance because the fax service does not need to poll FSPs to obtain updated status information. For more information, see [Creating a Completion Packet](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-creating-a-completion-packet).

## See also

[FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status)

[Fax Service Provider Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-functions)

[FaxDevEndJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevendjob)

[FaxDevInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevinitialize)

[FaxDevReceive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevreceive)

[FaxDevSend](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevsend)

[PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)