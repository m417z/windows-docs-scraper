# IInkRecognizer::get_PreferredPacketDescription

## Description

Gets an array of globally unique identifiers (GUIDs) that represents the preferred packet properties for the recognizer.

This property is read-only.

## Parameters

## Remarks

This property describes the contents of a packet and does not allow access to the data that the packet contains.

This property lists the packet properties that the recognizer uses to complete recognition. For all of the Microsoft recognizers, the **PreferredPacketDescription** property refers to the data describing (x, y) coordinates within an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object. This data is represented by the X and Y fields of the [packet property](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants) constants. A packet contains this point data as well as other data that is related to that stroke, such as the pressure of the pen that made the stroke, the angle of the pen, and so on. The Microsoft recognizers ignore pressure, tilt, and other packet properties.

## See also

[IInkRecognizer Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer)

[PacketPropertyGuids Constants](https://learn.microsoft.com/windows/desktop/tablet/packetpropertyguids-constants)