# IInkStrokeDisp::GetPacketValuesByProperty

## Description

Retrieves the data for a known packet property from one or more packets in the stroke.

## Parameters

### `PropertyName` [in]

The identifier from the [PacketProperty](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants) constants that was used to select which packet data is retrieved.

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `Index` [in, optional]

Optional. The starting point of the zero-based index to a packet within the stroke. The default value ISC_FirstElement, defined in the [InkSelectionConstants](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants) enumeration type, specifies the first packet.

### `Count` [in, optional]

Optional. The number of points that make up the stroke data. The default value ISC_AllElements, defined in the [InkSelectionConstants](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants) enumeration type, specifies all of the points that make up the stroke data.

### `PacketValues` [out, retval]

When this method returns, contains an array of signed 32-bit integers that specifies the value of the requested [PacketProperty](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants) for each point requested from the stroke.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **TPC_E_INVALID_STROKE** | The stroke is invalid. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_OUTOFMEMORY** | Cannot allocate packet data array. |
| **E_INVALIDARG** | Invalid index, count, or packet property. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **CO_E_CLASSSTRING** | Invalid GUID format. |

## Remarks

A specific packet property may not be available on a particular [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object. A Tablet PC may have more than one tablet for user input. The [InkTablets](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms704832(v=vs.85)) collection contains a list of all the tablets attached to the Tablet PC. Use the [IsPacketPropertySupported](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinktablet-ispacketpropertysupported) method to determine if a particular packet property is supported by a specific [IInkTablet](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object or by all the available tablets. Also, use the [DesiredPacketDescription](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_desiredpacketdescription) property of the **ink collector** to control which packet properties are collected on new strokes.

## See also

**DesiredPacketDescription Property**

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)

[InkTablets Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms704832(v=vs.85))

**IsPacketPropertySupported Method**

[ItemSelectionConstants Enumeration](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants)

[PacketPropertyGuids Constants](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants)