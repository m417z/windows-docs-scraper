# PFN_BLUETOOTH_ENUM_ATTRIBUTES_CALLBACK callback function

## Description

The *PFN_BLUETOOTH_ENUM_ATTRIBUTES_CALLBACK* is a callback function prototype that is called once for each attribute found in the **pSDPStream** parameter passed to the [BluetoothSdpEnumAttributes](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpenumattributes) function call.

## Parameters

### `uAttribId`

The current attribute identifier in the SDP stream.

### `pValueStream`

The raw SDP stream for the attribute value associated with **uAttribId**. Use the [BluetoothSdpGetElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetelementdata) function to parse the raw results into computer-readable data.

### `cbStreamSize`

The size, in bytes, of **pValueStream**.

### `pvParam`

The context passed in from a previous call to the [BluetoothSdpEnumAttributes](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpenumattributes) function.

## Return value

Should return **TRUE** when the enumeration continues to the next attribute identifier found in the stream. Should return **FALSE** when enumeration of the record attribute identifiers should immediately stop.

## See also

[BluetoothSdpGetElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetelementdata)