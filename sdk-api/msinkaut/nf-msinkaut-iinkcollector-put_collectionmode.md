# IInkCollector::put_CollectionMode

## Description

Gets or sets the collection mode that determines whether ink, gesture, or both are recognized as the user writes.

This property is read/write.

## Parameters

## Remarks

For a list of the modes that you can use, see the [InkCollectionMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkcollectionmode) enumeration type. However, when using the **CollectionMode** property on a system that has the Microsoft Windows XP Tablet PC Edition Software Development Kit (SDK) installed but that doesn't have recognizer installed, the mode cannot be set to **GestureOnly** or **InkAndGesture**.

**Note** The [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) object, the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object, or the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control generates an error if you try to change the **CollectionMode** property while ink is being collected. To avoid this conflict, check the [CollectingInk](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_collectingink) property before changing the **CollectionMode** property.

The following behaviors occur for each of the **CollectionMode** values:

[InkOnly](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkcollectionmode) mode

* Only ink is collected; gestures are not.
* The [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event interest is set to **FALSE** (all other event interests remain as they were).

[GestureOnly](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkcollectionmode) mode

* Only gestures are collected; ink is not. The strokes are deleted after they are sent to the gesture recognizer.
* The [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event interest is set to **TRUE** (all other event interests remain as they were).
* The ink collector does not fire the following stroke and packet related events: the [CursorDown](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursordown), [Stroke](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-stroke), [NewPackets](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-newpackets), and [NewInAirPackets](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-newinairpackets) events.
* Cursor events fire.
* Ink is always deleted.

[InkAndGesture](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkcollectionmode) mode

* Both ink and gestures are collected.
* Only single-stroke gestures are recognized.
* The [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event interest is set to **TRUE** (all other event interests remain as they were).
* The [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event fires first, allowing you to accept or cancel the gesture. To cancel the gesture, set the *Cancel* parameter to **TRUE**. Canceling the gesture forces the ink collector to collect the ink.

Changing the collection mode does not alter the status of individual gestures.

Unwanted behavior might occur when **CollectionMode** is set to [InkAndGesture](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkcollectionmode) and an object's/control's interest in a known gesture is set (by calling the [SetGestureStatus](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setgesturestatus) method). If you draw ink that looks something like the known gesture and the known gesture is in the recognizer's list of alternates, the [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event fires and ink disappears, even if the gesture is not the top alternate. To prevent the ink from disappearing and cancel collection of the gesture, set the *Cancel* parameter to **TRUE** if the event is one that you have no interest in.

When **CollectionMode** is set to [GestureOnly](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkcollectionmode), the timeout between when a user adds a gesture and when the [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event occurs is a fixed value that cannot be altered programmatically. Gesture recognition is faster in **InkAndGesture** mode. To prevent the collection of ink while in **InkAndGesture** mode, you can:

1. Set the **CollectionMode** property to **InkAndGesture**.
2. In the [Stroke](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-stroke) event, delete the stroke.
3. In the [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event, process the gesture.
4. Set [DynamicRendering](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_dynamicrendering) to **FALSE** to prevent the flow of ink while gesturing.

## See also

[CollectingInk Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_collectingink)

[Enabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled)

[IInkCollector](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkcollector)

[InkCollectionMode Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkcollectionmode)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)