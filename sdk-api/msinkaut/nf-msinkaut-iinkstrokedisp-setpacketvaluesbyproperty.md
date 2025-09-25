# IInkStrokeDisp::SetPacketValuesByProperty

## Description

Modifies the packet values for a particular property.

## Parameters

### `bstrPropertyName` [in]

The globally unique identifier (GUID) identifier from the [PacketProperty](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants) constants that is used to select which packet data is set. Use [PacketDescription](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_packetdescription) to determine the defined properties for this stroke.

### `PacketValues` [in]

The array of packet data values. The method fails if any of the values in the array are outside the minimum or maximum value of the property. To determine the range of values in the property, call the [GetPacketDescriptionPropertyMetrics](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getpacketdescriptionpropertymetrics) method.

### `Index` [in, optional]

Optional. The starting index of the packet to be modified. The default value [ISC_FirstElement](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants), defined in the **ItemSelectionConstants** enumeration type, specifies the first packet.

### `Count` [in, optional]

Optional. Specifies the number of packets in the stroke to modify and the number of values in *PacketValues*. The default value [ISC_AllElements](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants), defined in the **ItemSelectionConstants** enumeration type, specifies that all packets are modified.

### `NumberOfPacketsSet` [out, retval]

When this method returns, contains the actual number of packets set.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **CO_E_CLASSSTRING** | Invalid GUID format. |
| **E_INVALIDARG** | Invalid variant, index (out of range), or property GUID. |
| **E_INK_EXCEPTION** | An exception occurred inside method. |

## See also

[GetPacketDescriptionPropertyMetrics Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getpacketdescriptionpropertymetrics)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[ItemSelectionConstants Enumeration](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants)

[PacketPropertyGuids Constants](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants)