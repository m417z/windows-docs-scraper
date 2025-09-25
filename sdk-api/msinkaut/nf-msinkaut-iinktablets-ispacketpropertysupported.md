# IInkTablets::IsPacketPropertySupported

## Description

Determines whether a property of a tablet device or a collection of tablet devices, identified with a globally unique identifier (GUID), is supported. For example, use this method to determine if all of the tablets in a collection support tangential pressure from a pen.

## Parameters

### `packetPropertyName` [in]

The GUID for the [PacketProperty GUIDs](https://learn.microsoft.com/windows/desktop/tablet/packetproperty-guids) of the tablet or tablets that is requested. Use a defined BSTR constant from the [PacketProperty](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants) constants.

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `Supported` [out, retval]

When this method returns, contains **VARIANT_TRUE** if a known property is supported by the tablet or tablets; otherwise, **VARIANT_FALSE**.

**Note** This method can be re-entered when called within certain message handlers, causing unexpected results. Take care to avoid a reentrant call when handling any of the following messages: WM_ACTIVATE, WM_ACTIVATEAPP, WM_NCACTIVATE, WM_PAINT; WM_SYSCOMMAND if *wParam* is set to SC_HOTKEY or SC_TASKLIST; and WM_SYSKEYDOWN (when processing Alt-Tab or Alt-Esc key combinations). This is an issue with single-threaded apartment model applications.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **CO_E_CLASSSTRING** | Invalid GUID format. |
| **E_INK_EXCEPTION** | An exception occurred while processing. |
| **E_INVALIDARG** | The flag is invalid. |

## Remarks

**Note** When this method is called on the [InkTablets](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms704832(v=vs.85)) collection, it queries all of the tablets on the system. If any of them does not support the property, it returns **VARIANT_FALSE**. Call [IsPacketPropertySupported](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinktablet-ispacketpropertysupported) on an individual [IInkTablet](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object to determine whether the device supports a known property.

## See also

[GetPacketData Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getpacketdata)

[IInkTablet Class](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)

[IInkTablets](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinktablets)

[InkTablets Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms704832(v=vs.85))

[SetPacketValuesByProperty Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-setpacketvaluesbyproperty)