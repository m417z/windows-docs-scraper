# RtwqUnjoinWorkQueue function

## Description

Disassociates a work queue from an input/output (I/O) handle.

## Parameters

### `workQueueId` [in]

The ID of the work queue to disassociate.

### `hFile` [in]

The associated handle returned by the [RtwqJoinWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqjoinworkqueue) function.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.