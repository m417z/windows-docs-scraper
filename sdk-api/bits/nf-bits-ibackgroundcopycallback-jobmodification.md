# IBackgroundCopyCallback::JobModification

## Description

BITS calls your implementation of the
**JobModification** method when the job has been modified. The service generates this event when bytes are transferred, files have been added to the job, properties have been modified, or the state of the job has changed.

## Parameters

### `pJob` [in]

Contains the methods for accessing property, progress, and state information of the job. Do not release *pJob*; BITS releases the interface when the **JobModification** method returns.

### `dwReserved` [in]

Reserved for future use.

## Return value

This method should return **S_OK**.

## Remarks

Your implementation may not receive all modification events under maximum resource load conditions.

BITS generates a high volume of modification events; consider creating a timer and polling for state and progress information or limiting your use of this callback. If you use this callback, keep your implementation short.

BITS does not generate a modify event when the state of the job changes to BG_JOB_STATE_ERROR or BG_JOB_STATE_TRANSFERRED.

**Note** BITS supports up to four simultaneous notifications per user. If one or more applications block all four notifications for a user from returning, an application running as the same user will not receive notifications until one or more of the blocking notifications return.

#### Examples

See the example code for the
[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface.

## See also

[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback)

[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob)