# WS_ENUM_DESCRIPTION structure

## Description

A type description that is used with [WS_ENUM_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) and is required.
It provides information used in serializing and deserializing
values of an enumeration.

## Members

### `values`

Points to an array of enumeration values and their
corresponding names.

There must not be duplicate values or names in
the array.

### `valueCount`

The number of items in the values array.

### `maxByteCount`

The length, in UTF8 bytes, of the longest name
in the values array.

### `nameIndices`

An optional array that provides information which can improve
the performance of mapping enumeration values to names and back.
This array may **NULL**, in which case an O(n) lookup is used,
which may be sufficient for small numbers of enumerated values.

If non-**NULL**, the following must be true:

* The values array is required to be sorted by value, in ascending order.
* The nameIndices array points to an array that has valueCount items.
* The nameIndices array provides the indices of the items in
  the values array as if they were sorted by name in ascending order.
  The names should by sorted by performing a byte-wise comparison of the utf-8 string.

## Remarks

The following examples illustrates initializing an enum description. This
example illustrates the use of the nameIndices field, but this field could
be **NULL** instead.

``` syntax
enum
{
    Red = 10,
    Green = 20,
    Blue = 30,
};

WS_XML_STRING redString = WS_XML_STRING_VALUE("red");
WS_XML_STRING greenString = WS_XML_STRING_VALUE("green");
WS_XML_STRING blueString = WS_XML_STRING_VALUE("blue");

// sorted by ascending numeric value
WS_ENUM_VALUE valueArray[3] =
{
    { Red, &redString },
    { Green, &greenString },
    { Blue, &blueString },
};

// sorted by ascending name
ULONG nameIndices[3] =
{
    2, // "blue"
    1, // "green"
    0, // "red"
};

WS_ENUM_DESCRIPTION enumDescription;
enumDescription.maxByteCount = 5; // "green"
enumDescription.values = valueArray;
enumDescription.valueCount = 3;
enumDescription.nameIndices = nameIndices;

```