# IPortClsEtwHelper::MiniportWriteEtwEvent

## Description

The `MiniportWriteEtwEvent` method is used by an audio miniport driver for providing the information about an Event Tracing for Windows (ETW) event.

## Parameters

### `miniportEventType` [in]

An [EPcMiniportEngineEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-epcminiportengineevent) enumerated value that provides additional error information for reporting glitching errors.

### `pvData1` [in]

Data parameter.

### `pvData2` [in]

Data parameter.

### `ulData3` [in]

Data parameter.

### `ulData4` [in]

Data parameter.

## Return value

**MiniportWriteEtwEvent** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error code.

## See also

[EPcMiniportEngineEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ne-portcls-epcminiportengineevent)

[IPortClsEtwHelper](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclsetwhelper)