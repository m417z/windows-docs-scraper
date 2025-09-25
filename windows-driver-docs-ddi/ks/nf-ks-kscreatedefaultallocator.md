# KsCreateDefaultAllocator function

## Description

Given a validated IRP_MJ_CREATE request, the **KsCreateDefaultAllocator** function creates a default allocator that uses the specified memory pool and associates the IoGetCurrentIrpStackLocation(Irp)->FileObject with the allocator using an internal dispatch table (KSDISPATCH_TABLE).

## Parameters

### `Irp` [in]

Specifies the IRP with the IRP_MJ_CREATE request being handled.

## Return value

The **KsCreateDefaultAllocator** function returns STATUS_SUCCESS if successful, or it returns an error if unsuccessful.