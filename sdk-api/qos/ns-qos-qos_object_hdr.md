# QOS_OBJECT_HDR structure

## Description

The QOS object
**QOS_OBJECT_HDR** is attached to each QOS object. It specifies the object type and its length.

## Members

### `ObjectType`

Specifies the type of object to which
**QOS_OBJECT_HDR** is attached. The following values are valid for
**QOS_OBJECT_HDR**:

#### QOS_OBJECT_DESTADDR

#### QOS_OBJECT_END_OF_LIST

#### QOS_OBJECT_SD_MODE

#### QOS_OBJECT_SHAPING_RATE

#### RSVP_OBJECT_ADSPEC

#### RSVP_OBJECT_FILTERSPEC_LIST

#### RSVP_OBJECT_POLICY_INFO

#### RSVP_OBJECT_RESERVE_INFO

### `ObjectLength`

Specifies the length of the attached object, inclusive of QOS_OBJECT_HDR.

## See also

[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos)