# IInkStrokeDisp::GetPacketData

## Description

Retrieves the packet data for a range of packets within the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object.

## Parameters

### `Index` [in, optional]

Optional. The starting point of the zero-based index to a packet within the stroke. The default value ISC_FirstElement, defined in the [InkSelectionConstants](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants) enumeration type, specifies the first packet.

### `Count` [in, optional]

Optional. The number of point packet data sets that should be returned, starting with the packet specified in the *startingIndex* parameter. The default value ISC_AllElements, defined in the [InkSelectionConstants](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants) enumeration type, specifies all of the points that make up the stroke data.

### `PacketData` [out, retval]

When this method returns, contains a signed 32-bit integer array containing the packet data for the requested points in the stroke. The array contains the data for the first point, then the data for the second point, and so on.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_OUTOFMEMORY** | Cannot allocate Stroke handler helper object. |
| **E_INVALIDARG** | The stroke is invalid. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

If the number of packets in the stroke is less than the sum of the *startingIndex* and *pointCount* parameters, then the returned array of data contains packet information for fewer points than the count requested.

To retrieve the description of the packet data, use the stroke's [PacketDescription](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_packetdescription) property. This property returns an array of globally unique identifier (GUID) that indicates which property values are returned by the **GetPacketData** method for each point. The [PacketProperty](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants) constants contain the available packet property GUIDs.

## See also

[GetPacketDescriptionPropertyMetrics Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getpacketdescriptionpropertymetrics)

[GetPacketValuesByProperty Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getpacketvaluesbyproperty)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[ItemSelectionConstants Enumeration](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants)

[PacketCount Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_packetcount)

[PacketDescription Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_packetdescription)

[PacketSize Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_packetsize)

[SetPacketValuesByProperty Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-setpacketvaluesbyproperty)