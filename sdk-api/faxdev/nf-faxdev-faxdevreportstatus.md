# FaxDevReportStatus function

## Description

The fax service calls the **FaxDevReportStatus** function to query a fax service provider (FSP) for status information about an individual active fax operation, or for status information after a failed fax operation. Each FSP must export the **FaxDevReportStatus** function.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax handle returned by the [FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob) function that is associated with the fax job.

### `FaxStatus` [out]

Type: **PFAX_DEV_STATUS**

Pointer to a [FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status) structure that receives status and identification information. This parameter can also be a **NULL** pointer. For more information, see the following Remarks section.

### `FaxStatusSize` [in]

Type: **DWORD**

Specifies the size, in bytes, of the buffer pointed to by the *FaxStatus* parameter.

### `FaxStatusSizeRequired` [out]

Type: **LPDWORD**

Pointer to a variable that receives the calculated size, in bytes, of the buffer required to hold a [FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status) structure. For more information, see the following Remarks section.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** For a successful send, FaxDevSend() should return **TRUE** and FaxDevReportStatus() should return FS_COMPLETED. For an unsuccessful send, FaxDevSend() should return **FALSE**, and FaxDevReportStatus() should return any of the following codes: FS_LINE_UNAVAILABLE, FS_NO_ANSWER, FS_NO_DIAL_TONE, FS_DISCONNECTED, FS_BUSY, FS_NOT_FAX_CALL, or FS_FATAL_ERROR. If after a failed fax the fax should not be re-sent, FaxDevReportStatus() should return any code other than those listed here.

## Remarks

To obtain status information for the operation, the **FaxDevReportStatus** function is called asynchronously on an execution thread that is independent of the fax operation. It is usually necessary to synchronize access by multiple threads. For more information, see [Synchronizing Execution of Multiple Threads](https://learn.microsoft.com/windows/desktop/ProcThread/synchronizing-execution-of-multiple-threads).

If the *FaxStatusSize* parameter is equal to zero, and *FaxStatus* is a **NULL** pointer, the FSP must calculate the size, in bytes, of the buffer required to hold a [FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status) structure. The FSP must return this value in the *FaxStatusSizeRequired* parameter. The fax service will then allocate the required memory. It will also return both the memory size in the *FaxStatusSize* parameter, and a pointer to that memory in the *FaxStatus* parameter.

The FSP must set all of the members of the [FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status) structure with status information for the active fax operation. The fax service allocates the memory for the strings pointed to by the **CSI**, **CallerId**, and **RoutingInfo** members. The size of the memory the service allocates is equal to **sizeof(FAX_DEV_STATUS) + FAXDEVREPORTSTATUS_SIZE**. The FSP must place the strings in the block of memory that immediately follows the **FAX_DEV_STATUS** structure. The **CSI**, **CallerId**, and **RoutingInfo** members must point to the location of the strings in the memory block.

## See also

[FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status)

[Fax Service Provider Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-functions)

[FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)