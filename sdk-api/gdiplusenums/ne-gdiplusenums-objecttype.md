# ObjectType enumeration

## Description

The **ObjectType** enumeration indicates the object type value of an EMF+ record.

## Constants

### `ObjectTypeInvalid`

Object type is invalid.

### `ObjectTypeBrush`

Object type is a brush.

### `ObjectTypePen`

Object type is a pen.

### `ObjectTypePath`

Object type is a path.

### `ObjectTypeRegion`

Object type is a region.

### `ObjectTypeImage`

### `ObjectTypeFont`

Object type is a font.

### `ObjectTypeStringFormat`

Object type is a string format.

### `ObjectTypeImageAttributes`

Object type is an image attribute.

### `ObjectTypeCustomLineCap`

Object type is a custom line cap.

### `ObjectTypeGraphics`

Object type is graphics.

### `ObjectTypeMax`

Maximum enumeration value. Currently, it is ObjectTypeGraphics.

### `ObjectTypeMin`

Minimum enumeration value. Currently, it is ObjectTypeBrush.

## Remarks

To determine whether the object type value of an EMF+ record is valid, call [ObjectTypeIsValid](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/nf-gdiplusenums-objecttypeisvalid).