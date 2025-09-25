# SDP_ELEMENT_DATA structure

## Description

The **SDP_ELEMENT_DATA** structure stores SDP element data.

## Members

### `type`

Enumeration of SDP element types. Generic element types have a
**specificType** value different from SDP_ST_NONE. The generic SDP element types are the following:

* SDP_TYPE_UINT
* SDP_TYPE_INT
* SDP_TYPE_UUID

The following element types do not have corresponding **specificType** values:

* SDP_TYPE_STRING
* SDP_TYPE_URL
* SDP_TYPE_SEQUENCE
* SDP_TYPE_ALTERNATIVE
* SDP_TYPE_BOOLEAN
* SDP_TYPE_NIL

There is no associated data value with the type SDP_TYPE_NIL.

### `specificType`

Specific type of SDP element, used to further specify generic element types.

### `data`

### `data.int128`

Value for type equals SDP_TYPE_INT, value for **specificType** equals SDP_ST_INT128.

### `data.int64`

Value for type equals SDP_TYPE_INT, value for **specificType** equals SDP_ST_INT64.

### `data.int32`

Value for type equals SDP_TYPE_INT, value for **specificType** equals SDP_ST_INT32.

### `data.int16`

Value for type equals SDP_TYPE_INT, value for **specificType** equals SDP_ST_INT16.

### `data.int8`

Value for type equals SDP_TYPE_INT, value for **specificType** equals SDP_ST_INT8.

### `data.uint128`

Value for type equals SDP_TYPE_UINT, value for **specificType** equals SDP_ST_UINT128.

### `data.uint64`

Value for type equals SDP_TYPE_UINT, value for **specificType** equals SDP_ST_UINT64.

### `data.uint32`

Value for type equals SDP_TYPE_UINT, value for **specificType** equals SDP_ST_UINT32.

### `data.uint16`

Value for type equals SDP_TYPE_UINT, value for **specificType** equals SDP_ST_UINT16.

### `data.uint8`

Value for type equals SDP_TYPE_UINT, value for **specificType** equals SDP_ST_UINT8.

### `data.booleanVal`

Value for type equals SDP_TYPE_BOOLEAN.

### `data.uuid128`

Value for type equals SDP_TYPE_UUID, value for **specificType** equals SDP_ST_UUID128.

### `data.uuid32`

Value for type equals SDP_TYPE_UUID, value for **specificType** equals SDP_ST_UUID32.

### `data.uuid16`

Value for type equals SDP_TYPE_UUID, value for **specificType** equals SDP_ST_UUID16.

### `data.string`

### `data.string.value`

Value for type equals SDP_TYPE_STRING, which is a raw string buffer. Cannot be encoded as ANSI. Use the [BluetoothSdpGetString](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetstring) function to convert the value if it is described by the base language attribute identifier list.

### `data.string.length`

Raw length of the string. Cannot be null terminated.

### `data.url`

### `data.url.value`

Value for type equals SDP_TYPE_URL.

### `data.url.length`

Length of the raw URL. Cannot be null terminated.

### `data.sequence`

### `data.sequence.value`

Raw sequence that begins at the sequence element header. Value for type equals SDP_TYPE_SEQUENCE.

### `data.sequence.length`

Length of the raw sequence. Cannot be null terminated.

### `data.alternative`

### `data.alternative.value`

Raw alternative that begins at the alternative element header. Value for type equals SDP_TYPE_ALTERNATIVE.

### `data.alternative.length`

Length of the raw alternative. Cannot be null terminated.

## See also

[BluetoothSdpEnumAttributes](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpenumattributes)

[BluetoothSdpGetAttributeValue](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetattributevalue)

[BluetoothSdpGetContainerElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetcontainerelementdata)

[BluetoothSdpGetElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetelementdata)

[BluetoothSdpGetString](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetstring)

[PFN_BLUETOOTH_ENUM_ATTRIBUTES_CALLBACK](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nc-bluetoothapis-pfn_bluetooth_enum_attributes_callback)