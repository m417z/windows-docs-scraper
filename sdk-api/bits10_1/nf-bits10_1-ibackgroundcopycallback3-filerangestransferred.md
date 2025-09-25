# IBackgroundCopyCallback3::FileRangesTransferred

## Description

BITS calls your implementation of the **FileRangesTransferred** method when one or more file ranges have been downloaded. File ranges are added to the job using the [IBackgroundCopyFile6::RequestFileRanges](https://learn.microsoft.com/windows/desktop/api/bits10_1/nf-bits10_1-ibackgroundcopyfile6-requestfileranges) method.

## Parameters

### `job`

An [IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) object that contains the methods for accessing property, progress, and state information of the job. Do not release *pJob*; BITS releases the interface when the method returns.

### `file`

An [IBackgroundCopyFile](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyfile) object that contains information about the file whose ranges have changed. Do not release *pFile*; BITS releases the interface when the method returns.

### `rangeCount`

The count of entries in the ranges array.

### `ranges`

An array of the files ranges that have transferred since the last call to **FileRangesTransferred** or the last call to the [IBackgroundCopyFile6::RequestFileRanges](https://learn.microsoft.com/windows/desktop/api/bits10_1/nf-bits10_1-ibackgroundcopyfile6-requestfileranges) method. Do not free *ranges*; BITS frees the ranges memory when the **FileRangesTransferred** method returns.

## Return value

This method returns **S_OK** on success; otherwise, returns an error code.

## Remarks

The ranges returned in this method may not match the ranges you requested. This is because BITS will not download the same byte range twice, and because BITS can report when part of a range is downloaded.

Your implementation may not receive all modification events under maximum resource load conditions.

BITS generates a high volume of events; consider creating a timer and polling for state and progress information or limiting your use of this callback. If you use this callback, keep your implementation short. You should set the **BITS_JOB_PROPERTY_MINIMUM_NOTIFICATION_INTERVAL** property to the highest value that still meets your needs; this will reduce the number of unneeded callbacks.

**Note** BITS supports up to four simultaneous notifications per user. If one or more applications block all four notifications for a user from returning, an application running as the same user will not receive notifications until one or more of the blocking notifications return.

#### Examples

For an example of how to use this function, see the example code for the [IBackgroundCopyCallback3](https://learn.microsoft.com/windows/desktop/api/bits10_1/nn-bits10_1-ibackgroundcopycallback3) interface.

## See also

[IBackgroundCopyCallback3](https://learn.microsoft.com/windows/desktop/api/bits10_1/nn-bits10_1-ibackgroundcopycallback3)