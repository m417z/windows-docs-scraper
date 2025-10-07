# WPD\_VIDEO\_SCAN\_TYPES enumeration

The **WPD\_VIDEO\_SCAN\_TYPES** enumeration type describes how the fields in a video file are encoded.

## Constants

**WPD\_VIDEO\_SCAN\_TYPE\_UNUSED**

The scan type has not been defined for this video file, or is not applicable.

**WPD\_VIDEO\_SCAN\_TYPE\_PROGRESSIVE**

A progressive scan video file.

**WPD\_VIDEO\_SCAN\_TYPE\_FIELD\_INTERLEAVED\_UPPER\_FIRST**

An interleaved video file where the fields alternate and the upper field (with line 1) is drawn first. For more information, see the Remarks section.

**WPD\_VIDEO\_SCAN\_TYPE\_FIELD\_INTERLEAVED\_LOWER\_FIRST**

An interleaved video file where the fields alternate and the lower field (with line 2) is drawn first. For more information, see Remarks, following this section.

**WPD\_VIDEO\_SCAN\_TYPE\_FIELD\_SINGLE\_UPPER\_FIRST**

An interleaved video file where the fields are sent as contiguous samples and the upper field (with line 1) is drawn first. For more information, see Remarks, following this section.

**WPD\_VIDEO\_SCAN\_TYPE\_FIELD\_SINGLE\_LOWER\_FIRST**

An interleaved video file where the fields are sent as contiguous samples and the lower field (with line 2) is sent first.

**WPD\_VIDEO\_SCAN\_TYPE\_MIXED\_INTERLACE**

A video file with a mix of interlacing modes.

**WPD\_VIDEO\_SCAN\_TYPE\_MIXED\_INTERLACE\_AND\_PROGRESSIVE**

A video file with a mix of interlaced and progressive modes.

## Remarks

This enumeration is used by the [WPD\_VIDEO\_SCAN\_TYPE](https://learn.microsoft.com/windows/win32/wpd_sdk/properties-and-attributes) property.

There are two types of interleaved file formats that are specified by this enumeration. **WPD\_VIDEO\_SCAN\_TYPE\_FIELD\_INTERLEAVED** refers to a file format where frames are delivered as they were scanned fields alternate and data goes line by line, as shown here:

**Frame 1**

Field 1: Line 1

Field 2: Line 1

Field 1: Line 2

Field 2: Line 2

Field 1: Line 3

Field 2: Line 3

...

**WPD\_VIDEO\_SCAN\_TYPE\_FIELD\_SINGLE** refers to a file format where each field is stored in a single block of scan lines, and fields are stored sequentially, as shown here:

**Frame 1**

Field 1: Line 1

Field 1: Line 2

Field 1: Line 3

...

Followed by

Field 2: Line 1

Field 2: Line 2

Field 2: Line 3

...

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------------|
| Header<br> | PortableDevice.h |

## See also

[**Structures and Enumeration Types**](https://learn.microsoft.com/windows/win32/wpd_sdk/structures-and-enumeration-types)

