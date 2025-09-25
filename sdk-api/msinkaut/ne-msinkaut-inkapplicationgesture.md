# InkApplicationGesture enumeration

## Description

Defines values that set the interest in a set of application-specific gesture.

Application gestures are gestures that you can choose to have your application support. Applications that are specifically designed to work with a pen are more likely to use these gestures than applications designed for mouse and keyboard.

The **Tap** and **DoubleTap** gestures are supported as application gestures and system gestures (system gestures are defined in the [InkSystemGesture](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inksystemgesture) enumeration type). This means you can incorporate an application gesture that has a component that may be construed as a **Tap** or **DoubleTap** (such as the **Exclamation** gesture). In this case, enable the **Tap** application gesture and disable the **Tap** system gesture in your application. When a user taps, the application gesture is recognized. This allows your application to listen for a single component that can both identify and distinguish a system gesture **Tap** from a **Tap** within the application gesture.

In addition to the following list of gestures, Microsoft intends to support many gesture glyphs as part of the Microsoft gesture recognizer. For more information about these unimplemented gesture glyphs, see [Unimplemented Glyphs](https://learn.microsoft.com/windows/desktop/tablet/unimplemented-glyphs).

For more information about application gestures and system gestures, see [Using Gestures](https://learn.microsoft.com/windows/desktop/tablet/using-gestures) and [Pen Input, Ink, and Recognition](https://learn.microsoft.com/windows/desktop/tablet/pen-input--ink--and-recognition).

## Constants

### `IAG_AllGestures:0`

 All application-specific gestures.

### `IAG_NoGesture:0xf000`

 No application-specific gestures. See the following "Remarks" section for more details on this member.

This is the default value.

### `IAG_Scratchout:0xf001`

This gesture must be drawn as a single stroke that has at least three back-and-forth motions.

### `IAG_Triangle:0xf002`

The triangle must be drawn in a single stroke, without lifting the pen.

### `IAG_Square:0xf003`

The square can be drawn in one or two strokes. In one stroke, draw the entire square without lifting the pen. In two strokes, draw three sides of the square and use another stroke to draw the remaining side. Do not use more than two strokes to draw the square.

### `IAG_Star:0xf004`

The star must have exactly five points and be drawn in a single stroke without lifting the pen.

### `IAG_Check:0xf005`

The upward stroke must be twice as long as the smaller downward stroke.

### `IAG_Curlicue:0xf010`

Start the curlicue on the ink on which you intend to take action.

### `IAG_DoubleCurlicue:0xf011`

Start the double-curlicue on the ink on which you intend to take action.

### `IAG_Circle:0xf020`

The circle must be drawn in a single stroke without lifting the pen.

### `IAG_DoubleCircle:0xf021`

The two circles must overlap each other and be drawn in a single stroke without lifting the pen.

### `IAG_SemiCircleLeft:0xf028`

The semicircle must be drawn from left to right. Horizontally, the two ends of the semicircle should be as even as possible.

### `IAG_SemiCircleRight:0xf029`

The semicircle must be drawn from right to left. Horizontally, the two ends of the semicircle should be as even as possible.

### `IAG_ChevronUp:0xf030`

Both sides of the chevron must be drawn as equal as possible. The angle must be sharp and end in a point.

### `IAG_ChevronDown:0xf031`

Both sides of the chevron must be drawn as equal as possible. The angle must be sharp and end in a point.

### `IAG_ChevronLeft:0xf032`

Both sides of the chevron must be drawn as equal as possible. The angle must be sharp and end in a point.

### `IAG_ChevronRight:0xf033`

Both sides of the chevron must be drawn as equal as possible. The angle must be sharp and end in a point.

### `IAG_ArrowUp:0xf038`

The arrow can be drawn in single stroke or in two strokes in which one stroke is the line and the other is the arrow head. Do not use more than two strokes to draw the arrow.

### `IAG_ArrowDown:0xf039`

The arrow can be drawn in a single stroke or in two strokes in which one stroke is the line and the other is the arrow head. Do not use more than two strokes to draw the arrow.

### `IAG_ArrowLeft:0xf03a`

The arrow can be drawn in a single stroke or in two strokes in which one stroke is the line and the other is the arrow head. Do not use more than two strokes to draw the arrow.

### `IAG_ArrowRight:0xf03b`

The arrow can be drawn in a single stroke or in two strokes in which one stroke is the line and the other is the arrow head. Do not use more than two strokes to draw the arrow.

### `IAG_Up:0xf058`

This gesture must be drawn as a single fast flick in the upward direction.

This gesture is used by [Flicks Gestures](https://learn.microsoft.com/windows/desktop/tablet/flicks-gestures).

### `IAG_Down:0xf059`

This gesture must be drawn as a single fast flick in the downward direction.

This gesture is used by [Flicks Gestures](https://learn.microsoft.com/windows/desktop/tablet/flicks-gestures).

### `IAG_Left:0xf05a`

This gesture must be drawn as a single fast flick to the left.

This gesture is used by [Flicks Gestures](https://learn.microsoft.com/windows/desktop/tablet/flicks-gestures).

### `IAG_Right:0xf05b`

This gesture must be drawn as a single fast flick to the right.

This gesture is used by [Flicks Gestures](https://learn.microsoft.com/windows/desktop/tablet/flicks-gestures).

### `IAG_UpDown:0xf060`

This gesture must be drawn in a single stroke starting with the up stroke. The two strokes must be as close to each other as possible.

### `IAG_DownUp:0xf061`

This gesture must be drawn in a single stroke starting with the down stroke. The two strokes must be as close to each other as possible.

### `IAG_LeftRight:0xf062`

This gesture must be drawn in a single stroke starting with the left stroke. The two strokes must be as close to each other as possible.

### `IAG_RightLeft:0xf063`

This gesture must be drawn in a single stroke starting with the right stroke. The two strokes must be as close to each other as possible.

### `IAG_UpLeftLong:0xf064`

This gesture must be drawn in a single stroke starting with the up stroke. The left stroke must be about twice as long as the up stroke, and the two strokes must be at a right angle.

### `IAG_UpRightLong:0xf065`

This gesture must be drawn in a single stroke starting with the up stroke. The right stroke must be about twice as long as the up stroke, and the two strokes must be at a right angle.

### `IAG_DownLeftLong:0xf066`

This gesture must be drawn in a single stroke starting with the down stroke. The left stroke is about twice as long as the up stroke, and the two strokes must be at a right angle.

### `IAG_DownRightLong:0xf067`

This gesture must be drawn in a single stroke starting with the down stroke. The right stroke must be about twice as long as the up stroke, and the two strokes must be at a right angle.

### `IAG_UpLeft:0xf068`

This gesture must be drawn in a single stroke starting with the up stroke. The two sides must be as equal in length as possible and at a right angle.

### `IAG_UpRight:0xf069`

This gesture must be drawn in a single stroke starting with the up stroke. The two sides must be as equal in length as possible and at a right angle.

### `IAG_DownLeft:0xf06a`

This gesture must be drawn in a single stroke starting with the down stroke. The two sides must be as equal in length as possible and at a right angle.

### `IAG_DownRight:0xf06b`

This gesture must be drawn in a single stroke starting with the down stroke. The two sides must be as equal in length as possible and at a right angle.

### `IAG_LeftUp:0xf06c`

This gesture must be drawn in a single stroke starting with the left stroke. The two sides must be as equal in length as possible and at a right angle.

### `IAG_LeftDown:0xf06d`

This gesture must be drawn in a single stroke starting with the left stroke. The two sides are as equal in length as possible and at a right angle.

### `IAG_RightUp:0xf06e`

This gesture must be drawn in a single stroke starting with the right stroke. The two sides must be as equal in length as possible and at a right angle.

### `IAG_RightDown:0xf06f`

This gesture must be drawn in a single stroke starting with the right stroke. The two sides must be as equal in length as possible and at a right angle.

### `IAG_Exclamation:0xf0a4`

The line must be drawn first and then the dot drawn quickly and as close to the line as possible.

### `IAG_Tap:0xf0f0`

 A mouse click.

For the least amount of slipping across the digitizer surface, tap quickly.

### `IAG_DoubleTap:0xf0f1`

A mouse double-click.

Tap quickly and in as close to the same place for best results.

## Remarks

The default value is **NoGesture**, which is actually a cutoff line that represents the Microsoft gesture recognizer minimum suggested confidence. It does not actually represent a gesture or lack of gesture, just the point at which the gesture recognizer lacks enough confidence in the result accuracy to recommend anything following that point.

For example, assume that a gesture array consists of the following values: **Circle**, **LeftRight**, **NoGesture**, **RightLeft**, and **Triangle**. In this case, the gesture recognizer has a great degree of confidence in **Circle** and less confidence in **LeftRight**. The recognizer has very low confidence in **RightLeft** and **Triangle** because they come after **NoGesture** in the array order.

The confidence level at which the gesture recognizer returns **NoGesture** cannot be changed.

If **NoGesture** is the first element in the array (which means that every recognized gesture is below the suggested confidence threshold), then the platform alters the default value of the *Cancel* parameter in the [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture) event handler from **FALSE** to **TRUE**. This causes the ink to be considered a stroke and not be deleted from the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object by default.

## See also

[CollectionMode Property [InkPicture Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_collectionmode)

[Gesture Event [InkPicture Control]](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-gesture)

[GetGestureStatus Method [InkPicture Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-getgesturestatus)

[GetHotPoint Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkgesture-gethotpoint)

[InkSystemGesture Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inksystemgesture)

[Integrating Application Gestures](https://learn.microsoft.com/previous-versions/windows/desktop/ms704819(v=vs.85))

[SetGestureStatus Method [InkPicture Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setgesturestatus)

[SystemGesture Event [InkPicture Class]](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-systemgesture)

[Using Gestures](https://learn.microsoft.com/windows/desktop/tablet/using-gestures)