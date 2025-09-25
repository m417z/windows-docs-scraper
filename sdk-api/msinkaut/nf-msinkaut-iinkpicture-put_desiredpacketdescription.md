# IInkPicture::put_DesiredPacketDescription

## Description

Gets or sets the desired packet description of the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class).

This property is read/write.

## Parameters

## Remarks

The description is an array of globally unique identifiers (GUIDs) from the [PacketProperty](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants) object.

In multitablet mode, this is the packet description for all of the tablet devices. If any of the devices don't support a known packet description property, the property data is not returned.

By default, **DesiredPacketDescription** contains [STR_GUID_X](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants), STR_GUID_Y, and STR_GUID_NORMALPRESSURE from the PacketProperty object. If you set **DesiredPacketDescription** to anything else, STR_GUID_BUTTONPRESSURE only for example, STR_GUID_X and STR_GUID_Y is also added. A get of **DesiredPacketDescription** returns {X,Y,ButtonPressure} and not {ButtonPressure}.

When **DesiredPacketDescription** is set to something that includes [STR_GUID_PAKETSTATUS](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants), the packet status is added in the third position. For example, if you set **DesiredPacketDescription** to (a, b, c, d, PacketStatus, e, f), when you get **DesiredPacketDescription** the result is (X, Y, PacketStatus, a, b, c, d, e, f).

Changes to this property do not affect incoming packet data until the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_enabled) property changes from **FALSE** to **TRUE**.

## See also

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)

[InkPicture Control](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control)

[PacketPropertyGuids Constants](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants)