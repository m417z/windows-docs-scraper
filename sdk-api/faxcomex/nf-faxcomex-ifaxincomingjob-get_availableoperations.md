# IFaxIncomingJob::get_AvailableOperations

## Description

Retrieves the **AvailableOperations** property of a [FaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob) object. The **AvailableOperations** property indicates the combination of valid operations that you can perform on the fax job given its current status.

## Parameters

### `pAvailableOperations` [out, retval]

Type: **[FAX_JOB_OPERATIONS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_operations_enum)***

Pointer to a **long** value from the [FAX_JOB_OPERATIONS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_operations_enum) enumeration that specifies a bitwise combination of the operations that you can currently perform on the fax job. Some operations are mutually exclusive. For example, you cannot pause a job that has already been paused.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[AvailableOperations](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob-availableoperations)

[FAX_JOB_OPERATIONS_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_job_operations_enum)

[IFaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjob)