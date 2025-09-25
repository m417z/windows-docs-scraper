# BluetoothSdpGetString function

## Description

The **BluetoothSdpGetString** function converts a raw string embedded in the SDP record into a Unicode string.

## Parameters

### `pRecordStream` [in]

A pointer to a valid record stream formatted as a single SDP record.

### `cbRecordLength` [in]

The length, in bytes, of *pRecordStream*.

### `pStringData` [in]

When set to **NULL**, the calling thread locale is used to search for a matching string in the SDP record. If not **NULL**, the **mibeNum** and **attributeId** members of the
[SDP_STRING_TYPE_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_string_type_data) structure are used to find the string to convert.

### `usStringOffset` [in]

SDP string type offset to convert. The *usStringOffset* is added to the base attribute identifier of the string. SDP specification-defined offsets are: STRING_NAME_OFFSET, STRING_DESCRIPTION_OFFSET, and STRING_PROVIDER_NAME_OFFSET. These offsets can be found in the bthdef.h header file.

### `pszString` [out]

If not **NULL**, contains the converted string on output. When set to **NULL**, the *pcchStringLength* parameter is filled with the required number of characters, not bytes, to retrieve the converted string.

### `pcchStringLength` [in, out]

On input, contains the length of
*pszString* if *pszString* is not **NULL**, in characters.

Upon output, contains the
number of required characters including **NULL** if an error is returned,
or the number of characters written to *pszString*, including **NULL**.

## Return value

Returns ERROR_SUCCESS upon successful completion; the *pszString* parameter contains the converted string. Returns error codes upon failure. Common errors are listed in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | The *pszString* parameter was **NULL** or too small to contain the converted string; the *pcchStringLength* parameter contains, in characters, the required length. |
| **ERROR_INVALID_DATA** | The conversion cannot be performed. |
| **ERROR_NO_SYSTEM_RESOURCES** | The system cannot allocate memory internally to perform the conversion. |
| **ERROR_INVALID_PARAMETER** | One of the required pointers was **NULL**, the *pRecordStream* parameter was not a valid SDP stream, the *pRecordStream* was not a properly formatted record, or the requested attribute plus offset was not a string. |

## See also

[BluetoothSdpEnumAttributes](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpenumattributes)

[BluetoothSdpGetAttributeValue](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetattributevalue)

[BluetoothSdpGetContainerElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetcontainerelementdata)

[BluetoothSdpGetElementData](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothsdpgetelementdata)

[SDP_ELEMENT_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_element_data)

[SDP_STRING_TYPE_DATA](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/ns-bluetoothapis-sdp_string_type_data)