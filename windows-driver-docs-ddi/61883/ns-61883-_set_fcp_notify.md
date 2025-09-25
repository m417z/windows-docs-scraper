# _SET_FCP_NOTIFY structure

## Description

This structure is used for FCP notification. The SetFcpNotify request registers a client driver notification of FCP requests or responses, or cancels a prior registration. A driver must register for FCP notifications in order to retrieve requests or responses. The driver is responsible for canceling registration by sending a SetFcpNotify request with DEREGISTER_FCP_NOTIFY set in **Flags** before the system unloads the driver.

## Members

### `Flags`

On input, specifies the notification requested by the driver. The driver can register by setting **Flags** with either or both of the following:

REGISTER_FCP_RESPONSE_NOTIFY

REGISTER_FCP_REQUEST_NOTIFY

The driver can cancel notification by setting **Flags** with DEREGISTER_FCP_NOTIFY, which clears REGISTER_FCP_RESPONSE_NOTIFY and REGISTER_FCP_REQUEST_NOTIFY.

### `NodeAddress`

Reserved for use by the operating system.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)