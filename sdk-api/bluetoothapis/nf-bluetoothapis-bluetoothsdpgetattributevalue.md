# BluetoothSdpGetAttributeValue function

## Description

The **BluetoothSdpGetAttributeValue** function retrieves the attribute value for an attribute identifier.

## Parameters

### `pRecordStream` [in]

Pointer to a valid record stream that is formatted as a single SDP record.

### `cbRecordLength` [in]

Length of *pRecordStream*, in bytes.

### `usAttributeId` [in]

Attribute identifier to search for. See Remarks.

### `pAttributeData` [out]

Pointer to an [SDP_ELEMENT_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_element_data) structure into which the attribute's identifier value is placed.

## Return value

Returns ERROR_SUCCESS upon successful completion; the *pAddributeData* parameter contains the attribute value. Any other return value indicates error. The following table describes common error codes associated with the **BluetoothSdpGetAttributeValue** function:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Either one of the required pointers was **NULL**, the *pRecordStream* parameter was not a valid SDP stream, or the *pRecordStream* parameter was not a properly formatted SDP record. |
| **ERROR_FILE_NOT_FOUND** | The identifier provided in *usAttributeId* was not found in the record. |

## Remarks

The record stream in *pRecordStream* must be an SDP stream formatted as an SDP record, a SEQUENCE
containing attribute ID (UINT16) plus attribute value (any SDP element type) pairs.

The attribute identifier provided in the *usAttributeId* parameter can be one of the many SDP_ATTRIB_Xxx universal attribute identifiers provided in the bthdef.h file, or a custom attribute value defined by a Bluetooth profile. All values greater than or equal to 0x200 are profile-specific attribute identifiers, and are specific to the profile. See the bthdef.h header file for a list of universal SDP attribute identifiers.

## See also

[BluetoothSdpEnumAttributes](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpenumattributes)

[BluetoothSdpGetContainerElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetcontainerelementdata)

[BluetoothSdpGetElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetelementdata)

[BluetoothSdpGetString](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetstring)

[SDP_ELEMENT_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_element_data)

[SDP_STRING_TYPE_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_string_type_data)