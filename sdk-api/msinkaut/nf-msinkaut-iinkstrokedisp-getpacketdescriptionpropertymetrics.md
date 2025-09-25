# IInkStrokeDisp::GetPacketDescriptionPropertyMetrics

## Description

Retrieves the metrics for a given packet description type.

## Parameters

### `PropertyName` [in]

The globally unique identifier (GUID) from the [PacketProperty](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants) constants that identifies the property for which to obtain metrics.

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `Minimum` [out]

The minimum value, in logical units, that the tablet reports for this property. For example, a tablet reporting x-values from 0 to 9000 would have a logical minimum of 0.

### `Maximum` [out]

The maximum value, in logical units, that the tablet reports for this property. For example, a tablet reporting x-values from 0 to 9000 would have a logical maximum of 9000.

### `Units` [out]

The physical units of the property, such as inches or degrees. For a list of property units, see the [TabletPropertyMetricUnit](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-tabletpropertymetricunit) enumeration type.

### `Resolution` [out]

The resolution or increment value for the *units* member. For example, a tablet that reports 400 dots per inch (dpi) would have a *resolution* value of 400.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate memory necessary to complete this request. |
| **CO_E_CLASSSTRING** | Invalid GUID format. |
| **E_INVALIDARG** | The property does not exist in the collection. |
| **E_INK_EXCEPTION** | An exception occurred while processing. |

## See also

[GetPacketValuesByProperty Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getpacketvaluesbyproperty)

[GetPropertyMetrics Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinktablet-getpropertymetrics)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[SetPacketValuesByProperty Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-setpacketvaluesbyproperty)

[TabletPropertyMetricUnit Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-tabletpropertymetricunit)