# DDiscFormat2DataEvents::Update

## Description

Implement this method to receive progress notification of the current write operation.

## Parameters

### `object` [in]

The [IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data) interface that initiated the write operation.

This parameter is a **MsftDiscFormat2Data** object in script.

### `progress` [in]

An [IDiscFormat2DataEventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2dataeventargs) interface that you use to determine the progress of the write operation.

This parameter is a **MsftDiscFormat2Data** object in script.

## Return value

Return values are ignored.

## Remarks

Notifications are sent in response to calling the [IDiscFormat2Data::Write](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-write) method.

Notification is sent when the current action changes:

* Once when initializing the hardware
* Once when calibrating the power
* Once when formatting the media, if required by the media type
* Every 0.5 seconds during the write operation
* Once after the operation completes

To stop the write process, call the [IDiscFormat2Data::CancelWrite](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-cancelwrite) method.

## See also

[DDiscFormat2DataEvents](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscformat2dataevents)

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)