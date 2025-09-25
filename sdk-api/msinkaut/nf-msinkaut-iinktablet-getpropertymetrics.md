# IInkTablet::GetPropertyMetrics

## Description

Retrieves the metrics data for a specified property.

## Parameters

### `propertyName` [in]

The property for which you want to determine metrics.

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `Minimum` [out]

The minimum value, in logical units, that the tablet reports for this property. For example, a tablet reporting x-values from 0 to 9000 has a logical minimum of 0.

### `Maximum` [out]

The maximum value, in logical units, that the tablet reports for this property. For example, a tablet reporting x-values from 0 to 9000 would have a logical maximum of 9000.

### `Units` [out]

The physical units of the property, such as inches or degrees. For a list of property units, see the [TabletPropertyMetricUnit](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-tabletpropertymetricunit) enumeration type.

### `Resolution` [out]

Specifies the resolution or increment value for the **units** member. For example, a tablet that reports 400 dots per inch (dpi) has a resolution value of 400.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **TPC_E_UNKNOWN_PROPERTY** | The tablet does not support the specified property. |
| **E_FAIL** | An unspecified error occurred. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **CO_E_CLASSSTRING** | Invalid GUID format. |
| **E_INVALIDARG** | Unknown property string. |
| **E_INK_EXCEPTION** | An exception occurred while processing. |

## Remarks

The properties for which you retrieve metrics may include the time that a packet was generated or the downward pressure of the pen tip on the tablet surface.

For a complete list of properties for which you can retrieve metrics, see the [PacketProperty](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants) constants.

**Note** Accessing this property within certain message handlers can result in the underlying function being re-entered, causing unexpected results. Take care to avoid a reentrant call when handling any of the following messages: WM_ACTIVATE, WM_ACTIVATEAPP, WMNCACTIVATE, WM_PAINT; WM_SYSCOMMAND if **wParam** is set to SC_HOTKEY or SC_TASKLIST; and WM_SYSKEYDOWN (when processing Alt-Tab or Alt-Esc key combinations). This is an issue with single-threaded apartment model applications.

## See also

[GetPacketDescriptionPropertyMetrics Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getpacketdescriptionpropertymetrics)

[GetPacketValuesByProperty Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getpacketvaluesbyproperty)

[IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)

[SetPacketValuesByProperty Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-setpacketvaluesbyproperty)

[TabletPropertyMetricUnit Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-tabletpropertymetricunit)