# DDiscFormat2EraseEvents::Update

## Description

Implement this method to receive progress notification of the current erase operation.

## Parameters

### `object` [in]

The [IDiscFormat2Erase](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2erase) interface that initiated the erase operation.

This parameter is a **MsftDiscFormat2Erase** object in script.

### `elapsedSeconds` [in]

Elapsed time, in seconds, of the erase operation.

### `estimatedTotalSeconds` [in]

Estimated time, in seconds, to complete the erase operation.

## Return value

Return values are ignored.

## Remarks

Notifications are sent in response to calling the [IDiscFormat2Erase::EraseMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-erasemedia) method.

Notification is sent every 0.5 or 1.0 seconds depending on the method required to blank the media.

Total time estimates for a single erasure can vary as the operation progresses. The drive provides updated information that can affect the projected duration of the erasure.

## See also

[DDiscFormat2EraseEvents](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscformat2eraseevents)