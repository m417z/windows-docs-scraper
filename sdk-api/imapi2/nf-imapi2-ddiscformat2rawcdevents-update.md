# DDiscFormat2RawCDEvents::Update

## Description

Implement this method to receive progress notification of the current raw-image write operation.

## Parameters

### `object` [in]

The [IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd) interface that initiated the write operation.

This parameter is a **MsftDiscFormat2RawCD** object in script.

### `progress` [in]

An [IDiscFormat2RawCDEventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcdeventargs) interface that you use to determine the progress of the write operation.

This parameter is a **MsftDiscFormat2RawCD** object in script.

## Return value

Return values are ignored.

## Remarks

Notifications are sent in response to calling the [IDiscFormat2RawCD::WriteMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-writemedia) or [IDiscFormat2RawCD::WriteMedia2](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-writemedia2) method.

To stop the write process, call the [IDiscFormat2RawCD::CancelWrite](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-cancelwrite) method.

## See also

[DDiscFormat2RawCDEvents](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscformat2rawcdevents)

[IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd)

[IDiscFormat2RawCD::CancelWrite](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-cancelwrite)