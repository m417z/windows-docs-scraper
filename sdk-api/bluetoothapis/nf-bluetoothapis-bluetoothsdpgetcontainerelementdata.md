# BluetoothSdpGetContainerElementData function

## Description

The **BluetoothSdpGetContainerElementData** function iterates a container stream and returns each element contained within the container element.

## Parameters

### `pContainerStream` [in]

A pointer to valid SDP stream. The first element in the stream must be a sequence
or an alternative.

### `cbContainerLength` [in]

The size, in bytes, of the *pContainerStream* parameter.

### `pElement` [in, out]

A value used to track the location in the stream. The first
time the **BluetoothSdpGetContainerElementData** function is called for a container, **pElement* should be **NULL**. For subsequent calls, the value should be
unmodified.

### `pData` [out]

A pointer to a buffer filled with data from the
current SDP element of *pContainerStream*.

## Return value

Returns **ERROR_SUCCESS** upon success, indicating that the *pData* parameter contains the data. Returns error codes upon failure. The following table describes common error codes associated with the **BluetoothSdpGetContainerElementData** function:

| Return code | Description |
| --- | --- |
| **ERROR_NO_MORE_ITEMS** | There are no more items in the list. The caller should stop calling the [BluetoothSdpGetContainerElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetcontainerelementdata) function for this container. |
| **ERROR_INVALID_PARAMETER** | A required pointer is **NULL**, or the container is not a valid SDP stream. |

## See also

[BluetoothSdpEnumAttributes](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpenumattributes)

[BluetoothSdpGetElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetelementdata)

[BluetoothSdpGetString](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetstring)

[SDP_ELEMENT_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_element_data)

[SDP_STRING_TYPE_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_string_type_data)