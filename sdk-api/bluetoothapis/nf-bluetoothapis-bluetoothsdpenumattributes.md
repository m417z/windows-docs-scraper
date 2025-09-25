# BluetoothSdpEnumAttributes function

## Description

The **BluetoothSdpEnumAttributes** function enumerates through the SDP record stream, and calls the callback function
for each attribute in the record.

## Parameters

### `pSDPStream`

Pointer to a valid record stream that is formatted as a single SDP record.

### `cbStreamSize`

Size of the stream pointed to by *pSDPStream*, in bytes.

### `pfnCallback`

Pointer to the callback routine. See [PFN_BLUETOOTH_ENUM_ATTRIBUTES_CALLBACK](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nc-bluetoothapis-pfn_bluetooth_enum_attributes_callback) for more information about the callback.

### `pvParam`

Optional parameter to be passed to the callback routine.

## Return value

Returns **TRUE** if an enumeration occurred. Returns **FALSE** upon failure. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function for more information. The following table describes common error codes associated with the **BluetoothSdpEnumAttributes** function:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *pSDPStream* or *pfnCallback* parameter is **NULL**. |
| **ERROR_INVALID_DATA** | The SDP stream is corrupt. |

## Remarks

If the callback function returns
**FALSE**, the enumeration initiated by the **BluetoothSdpEnumAttributes** function is stopped.

The record stream in *pSDPStream* must be an SDP stream formatted as an SDP record, a SEQUENCE
containing attribute ID (UINT16) plus attribute value (any SDP element type) pairs.

## See also

[BluetoothSdpGetContainerElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetcontainerelementdata)

[BluetoothSdpGetElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetelementdata)

[BluetoothSdpGetString](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetstring)

[PFN_BLUETOOTH_ENUM_ATTRIBUTES_CALLBACK](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nc-bluetoothapis-pfn_bluetooth_enum_attributes_callback)

[SDP_ELEMENT_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_element_data)

[SDP_STRING_TYPE_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_string_type_data)