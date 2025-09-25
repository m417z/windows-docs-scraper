# WdfRequestCompleteWithPriorityBoost function

## Description

[Applies to KMDF only]

The **WdfRequestCompleteWithPriorityBoost** method completes a specified I/O request and supplies a completion status. It also specifies a value that the system can use to boost the run-time priority of the thread that requested the I/O operation.

## Parameters

### `Request` [in]

A handle to the framework request object that represents the I/O request that is being completed.

### `Status` [in]

An [NTSTATUS value](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) that represents the completion status of the request. Valid status values include, but are not limited to, the following:

#### STATUS_SUCCESS

The driver successfully completed the request.

#### STATUS_CANCELLED

The driver canceled the request.

#### STATUS_UNSUCCESSFUL

The driver encountered an error while processing the request.

### `PriorityBoost` [in]

A system-defined constant value by which to increment the run-time priority of the original thread that requested the operation. Constant values are device-type-specific and are defined in *Wdm.h*. The format for the constant names is *XXX*_INCREMENT. For more information about priority boost values, see [Specifying Priority Boosts When Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-priority-boosts-when-completing-i-o-requests).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Your driver should call **WdfRequestCompleteWithPriorityBoost** if you want to override the default priority boost that the framework provides. For example, the driver might set the priority boost to IO_NO_INCREMENT if it was able to complete the request quickly, perhaps because it detected an error.

After a call to **WdfRequestCompleteWithPriorityBoost** returns, the request handle is no longer valid unless the driver has called [WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference) to add one or more additional reference counts to the request object. Note that after **WdfRequestCompleteWithPriorityBoost** returns, the driver must not attempt to access the associated WDM IRP structure, even if it has called **WdfObjectReference**.

For more information about calling **WdfRequestCompleteWithPriorityBoost**, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

#### Examples

The following code example shows how the example at [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) can use **WdfRequestCompleteWithPriorityBoost** instead of **WdfRequestComplete**.

```cpp
switch (params.Type) {
    case WdfRequestTypeRead:
        length = params.Parameters.Read.Length;
        direction = WdfDmaDirectionReadFromDevice;
        break;
    case WdfRequestTypeWrite:
        length = params.Parameters.Write.Length;
        direction = WdfDmaDirectionWriteToDevice;
        break;
    default:
        WdfRequestCompleteWithPriorityBoost(
                                            Request,
                                            STATUS_INVALID_PARAMETER,
                                            IO_NO_INCREMENT
                                            );
        return;
    }
```

## See also

[WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)

[WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation)