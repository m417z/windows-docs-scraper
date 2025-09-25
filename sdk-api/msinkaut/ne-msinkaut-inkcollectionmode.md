# InkCollectionMode enumeration

## Description

Defines values that determine whether ink, gestures, or ink and gestures are recognized as the user writes.

## Constants

### `ICM_InkOnly:0`

Collects only ink, creating a stroke.

The [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event interest is set to **FALSE**, meaning that gestures are not collected (all other event interests remain as they were).

### `ICM_GestureOnly`

Collects only gestures and does not create a stroke. Gestures can be either single or multi-stroke. Multi-stroke gestures are accepted if the strokes are made within the time set by the built-in timer of the recognizer.

All stroke-related and packet-related events do not fire from the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class). Cursor events do fire, and ink is always deleted.

The [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event interest is set to **TRUE**, meaning that gestures are collected (all other event interests remain as they were).

### `ICM_InkAndGesture`

Accepts only single-stroke gestures. The [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event fires first, giving the user the ability to say *Cancel* = **TRUE** or **FALSE**. The default is **TRUE**, except when [NoGesture](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture) is the primary gesture, *Cancel* defaults to **FALSE**. If **TRUE**, the ink is a gesture and is deleted. If **FALSE**, the gesture is ink and a [Stroke](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-stroke) event fires.

The [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event interest is set to **TRUE** (all other event interests are kept as they were).

## Remarks

If a user attempts a right-click and moves the pen when in InkOnly or InkAndGesture mode, ink flows from the pen tip. When handling the [Stroke](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-stroke) event, you should erase the ink that flowed as a result of the pen movement.

When the **InkCollectionMode** is set to GestureOnly (set through the [CollectionMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_collectionmode) property), the timeout between when a user adds a gesture and when the [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event occurs is a fixed value that cannot be altered programmatically. Gesture recognition is faster in InkAndGesture mode. To prevent the collection of ink while in InkAndGesture mode, you can:

* Set [CollectionMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_collectionmode) to InkAndGesture.
* In the [Stroke](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-stroke) event, delete the stroke.
* In the [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event, process the gesture.
* Set [DynamicRendering](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_dynamicrendering) to **FALSE**.

When using this enumeration with the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control (or the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) or [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) objects) on a system that has the Microsoft Windows XP Tablet PC Edition Software Development Kit (SDK) installed but that doesn't have recognizers, the mode cannot be set to GestureOnly or InkAndGesture.

The ink collector always creates either a stroke (InkOnly mode) or a gesture (GestureOnly mode) and sometimes created both (InkAndGesture mode).

Typical scenarios for each mode follow.

* InkOnly:
  1. [CursorInRange](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursorinrange) event fires.
  2. [NewInAirPackets](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-newinairpackets) event fires.
  3. [CursorDown](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursordown) event fires.
  4. [NewPackets](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-newpackets) event fires.
  5. [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object is created.
  6. [CursorOutOfRange](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursoroutofrange) event fires.

  **Note** You may not always want to fire the [CursorOutOfRange](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursoroutofrange) event. If you want to continue drawing ink, you may return to the [NewInAirPackets](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-newinairpackets) or [CursorDown](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursordown) events after a stroke is completed.
* GestureOnly:
  1. [CursorInRange](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursorinrange) event fires.
  2. [NewInAirPackets](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-newinairpackets) event fires.
  3. [CursorDown](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursordown) event fires.
  4. [NewPackets](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-newpackets) event fires.
  5. Either an [IInkGesture](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkgesture) object is created or, if the cursor movement does not represent a gesture, nothing happens.
  6. [CursorOutOfRange](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursoroutofrange) event fires.

  **Note** Either single or multi-stroke gestures are accepted in this mode.
* InkAndGesture:
  1. [CursorInRange](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursorinrange) event fires.
  2. [NewInAirPackets](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-newinairpackets) event fires.
  3. [CursorDown](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursordown) event fires.
  4. [NewPackets](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-newpackets) event fires.
  5. Either an [IInkGesture](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkgesture) object or an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object is created.
  6. [CursorOutOfRange](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursoroutofrange) event fires.

  **Note** Only single-stroke gestures are accepted in this mode.

Unwanted behavior might occur when the [CollectionMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_collectionmode) property is set to InkAndGesture and the interest of an object or control in a known gesture is set (by calling the [SetGestureStatus](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setgesturestatus) method). If a user draws ink that resembles a gesture that is in the recognizer's list of recognition alternates, the [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event fires and ink disappears, even if the gesture is not the top alternate. To prevent the ink from disappearing and cancel collection of the gesture, set *Cancel* to **TRUE** if the event is one to which you do not want the recognizer to respond.

## See also

[CollectionMode Property [InkCollector Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_collectionmode)

[Gesture Event](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[InkPicture Control Reference](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)

[Stroke Event](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-stroke)