# BluetoothSdpGetElementData function

## Description

The **BluetoothSdpGetElementData** function retrieves and parses a single element from an SDP stream.

## Parameters

### `pSdpStream` [in]

A pointer to a valid SDP stream.

### `cbSdpStreamLength` [in]

The length, in bytes, of *pSdpStream*.

### `pData` [out]

A pointer to a buffer to be filled with the data of the SDP element found at the beginning of the *pSdpStream* SDP stream.

## Return value

Returns **ERROR_SUCCESS** when the SDP element is parsed correctly. Returns **ERROR_INVALID_PARAMETER** if one of the required parameters is **NULL**, or if the SDP stream pointed to by *pSdpStream* is not valid.

## See also

[BluetoothSdpEnumAttributes](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpenumattributes)

[BluetoothSdpGetContainerElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetcontainerelementdata)

[BluetoothSdpGetString](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetstring)

[SDP_ELEMENT_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_element_data)

[SDP_STRING_TYPE_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_string_type_data)