# KsValidateAllocatorCreateRequest function

## Description

The **KsValidateAllocatorCreateRequest** function validates an IRP_MJ_CREATE request as an allocator request and returns the create structure associated with the request on success.

## Parameters

### `Irp` [in]

Specifies the IRP with the IRP_MJ_CREATE request being validated.

### `AllocatorFraming` [out]

Caller-defined pointer that on successful completion contains an address to the framing structure supplied with the request.

## Return value

The **KsValidateAllocatorCreateRequest** function returns STATUS_SUCCESS if successful, or an error if the allocator request is not valid.