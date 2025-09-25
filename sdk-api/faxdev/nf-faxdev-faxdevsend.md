# FaxDevSend function

## Description

The fax service calls the **FaxDevSend** function to signal a fax service provider (FSP) that it must initiate an outgoing fax transmission. Each FSP must export the **FaxDevSend** function.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax handle returned by the [FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob) function.

### `FaxSend` [in]

Type: **PFAX_SEND**

Pointer to a [FAX_SEND](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_send) structure that contains the sending information. For more information, see the following Remarks section.

### `FaxSendCallback`

Type: **PFAX_SEND_CALLBACK**

Pointer to a callback function that notifies the fax service of the call handle that TAPI assigns. For more information, see the following Remarks section.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** For a successful send, FaxDevSend() should return **TRUE** and FaxDevReportStatus() should return FS_COMPLETED. For an unsuccessful send, FaxDevSend() should return **FALSE**, and FaxDevReportStatus() should return any of the following codes: FS_LINE_UNAVAILABLE, FS_NO_ANSWER, FS_NO_DIAL_TONE, FS_DISCONNECTED, FS_BUSY, FS_NOT_FAX_CALL, or FS_FATAL_ERROR. If after a failed fax the fax should not be re-sent, FaxDevReportStatus() should return any code other than those listed here.

## Remarks

The FSP must respond to the **FaxDevSend** function by making the call, sending the data, and terminating the call. The provider can call the [lineSetMediaMode](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediamode) function to correctly set the call's media mode. The fax service provider must dial the number specified by the **ReceiverNumber** member of the [FAX_SEND](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_send) structure.

The FSP has ownership of the line while in the context of the **FaxDevSend** function, and it must handle all protocol and error correction.

The data stream stored in the file specified by the **FileName** member of the [FAX_SEND](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_send) structure is a Tagged Image File Format Class F (TIFF Class F) file. For more information, see [Fax Image Format](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-image-format).

To notify the fax service that a call has been established, the FSP must call the [FaxSendCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nc-faxdev-pfax_send_callback) function pointed to by the *FaxSendCallback* parameter. The callback function also provides the fax service with the call handle that TAPI assigns. This handle is necessary for TAPI message routing. If the FSP does not call *FaxSendCallback*, it will miss all call-specific events for the send operation.

## See also

[FAX_SEND](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_send)

[Fax Service Provider Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-functions)

[FaxDevReceive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevreceive)

[FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob)

[FaxSendCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nc-faxdev-pfax_send_callback)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)