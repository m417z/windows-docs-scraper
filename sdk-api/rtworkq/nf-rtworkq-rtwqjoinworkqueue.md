# RtwqJoinWorkQueue function

## Description

Associates a work queue with an input/output (I/O) handle.

## Parameters

### `workQueueId` [in]

The ID of the work queue to redirect the I/O handle into.

### `hFile` [in]

The network I/O handle.

### `out` [out]

A cookie that represents the association between the network and I/O handles.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.