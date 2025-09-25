# RtwqGetWorkQueueMMCSSClass function

## Description

Retrieves the Multimedia Class Scheduler Service (MMCSS) class currently associated with this work queue.

## Parameters

### `workQueueId` [in]

Identifier for the work queue. The identifier is retrieved by the [RtwqAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqallocateworkqueue) function.

### `usageClass` [out]

Pointer to a buffer that receives the name of the MMCSS class. This parameter can be **NULL**.

### `usageClassLength` [in, out]

On input, specifies the size of the *usageClass* buffer, in characters. On output, receives the required size of the buffer, in characters. The size includes the terminating null character.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.