# PosCxCleanPendingRequests function

## Description

PosCxCleanPendingRequests is called to cancel all pending requests for a given caller, identified by the open instance.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `callerFileObj` [in, optional]

A handle to a framework file object for which all pending requests should be cancelled, or NULL to cancel all pending requests.

### `completionStatus` [in]

An appropriate NTSTATUS error code that indicates success or failure.