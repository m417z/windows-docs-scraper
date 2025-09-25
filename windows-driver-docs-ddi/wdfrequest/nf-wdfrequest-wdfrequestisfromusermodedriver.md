# WdfRequestIsFromUserModeDriver function

## Description

[Applies to UMDF only]

The **WdfRequestIsFromUserModeDriver** method indicates whether an I/O request came from a user-mode driver or an application.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestIsFromUserModeDriver** returns **TRUE** if the specified I/O request is from a user-mode driver. The method returns **FALSE** if the current I/O request came from an application.

## Remarks

If your driver supports [kernel-mode clients](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-kernel-mode-clients-in-umdf-drivers), it should call **WdfRequestIsFromUserModeDriver** only if [WdfRequestGetRequestorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetrequestormode) returns **WdfUserMode**.

## See also

[WdfRequestGetRequestorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetrequestormode)