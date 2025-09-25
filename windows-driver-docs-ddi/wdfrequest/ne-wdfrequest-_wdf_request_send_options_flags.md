# _WDF_REQUEST_SEND_OPTIONS_FLAGS enumeration (wdfrequest.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_SEND_OPTIONS_FLAGS** enumeration type defines flags that are used in a driver's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure.

## Constants

### `WDF_REQUEST_SEND_OPTION_TIMEOUT:0x00000001`

If the driver sets this flag, the **Timeout** member of the WDF_REQUEST_SEND_OPTIONS structure is valid.

### `WDF_REQUEST_SEND_OPTION_SYNCHRONOUS:0x00000002`

If the driver sets this flag, the framework handles the associated I/O request synchronously. (The driver does not have to set this flag if it is calling an object method whose name ends with "Synchronously", such as [WdfIoTargetSendReadSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendreadsynchronously).)

### `WDF_REQUEST_SEND_OPTION_IGNORE_TARGET_STATE:0x00000004`

If the driver sets this flag, the framework sends the I/O request to the I/O target, regardless of the I/O target's state. If not set, the framework queues the request if the target is stopped. Setting this flag allows a driver to send a request, such as a request to reset a USB pipe, to a device after the driver has called [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop).

### `WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET:0x00000008`

If the driver sets this flag, the driver is sending the request asynchronously and does not need to be notified when the request is completed or canceled. The framework sends the I/O request to the I/O target, regardless of the I/O target's state. The driver does not set a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function or call [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) for the request. If the driver sets this flag, it cannot set any other flags. For more information about this flag, see the following Remarks section.

### `WDF_REQUEST_SEND_OPTION_IMPERSONATE_CLIENT:0x00010000`

This flag applies to UMDF only. If set, and if the I/O request type is **WdfRequestTypeCreate**, the [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) method attempts to pass the client's impersonation level to the driver's I/O target. The **WdfRequestSend** method returns an error code if the impersonation attempt fails, unless the driver also sets the **WDF_REQUEST_SEND_OPTION_IMPERSONATION_IGNORE_FAILURE** flag.

### `WDF_REQUEST_SEND_OPTION_IMPERSONATION_IGNORE_FAILURE:0x00020000`

This flag applies to UMDF only. If set, the framework still sends the request even if impersonation fails. You can use this value only with **WDF_REQUEST_SEND_OPTION_IMPERSONATE_CLIENT**.

## Remarks

A driver that sets the WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET flag typically does not format the I/O request before it calls [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request to an I/O target. In fact, a driver that sets this flag must not call any of the **WdfIoTargetFormatRequestFor***Xxx* methods before it calls **WdfRequestSend**. The driver can use only the [WdfRequestFormatRequestUsingCurrentType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestformatrequestusingcurrenttype) or [WdfRequestWdmFormatUsingStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestwdmformatusingstacklocation) method to format the request.

Your driver *cannot* set the WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET flag in the following situations:

* The driver created the request object by calling [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate).
* The driver is sending the I/O request to a remote I/O target and the driver specified the [WdfIoTargetOpenByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_open_type) flag when it called [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen).
* The driver is sending the I/O request to a remote I/O target, and the driver specified both the [WdfIoTargetOpenUseExistingDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_open_type) flag and a [TargetFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) pointer when it called [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen).
* The request type is [WdfRequestTypeCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type) and the driver has not set the [WdfFileObjectNotRequired](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_fileobject_class) flag. (For more information about this situation, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).)

For the UMDF version of this enumeration, see [WDF_REQUEST_SEND_OPTIONS_FLAGS (UMDF)](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_send_options_flags).

## See also

[WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options)

[WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop)