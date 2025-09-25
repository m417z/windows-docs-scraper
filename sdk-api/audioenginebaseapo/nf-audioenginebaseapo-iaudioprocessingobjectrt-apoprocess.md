# IAudioProcessingObjectRT::APOProcess

## Description

The APOProcess method causes the APO to make a processing pass.

## Parameters

### `u32NumInputConnections` [in]

The number of input connections that are attached to this APO.

### `ppInputConnections` [in]

An array of input connection property structures. There is one structure per input connection.

### `u32NumOutputConnections` [in]

The number of output connections that are attached to this APO.

### `ppOutputConnections` [in, out]

An array of output connection property structures. There is one structure per output connection.

## Return value

None

| Return code | Description |
| --- | --- |

## Remarks

The `APOProcess` method must not change the data in the ppOutputConnections array. But it must set the properties of the output connections after processing.

The `APOProcess` method is called from a real-time processing thread. The implementation of this method must not touch paged memory and it should not call any system blocking routines.

For a detailed look at an implementation of this method, see the [Swap sample code](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-vista-sapo-feature-reference) and refer to the Swapapolfx.cpp file.

## See also

[Swap sample code](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-vista-sapo-feature-reference)