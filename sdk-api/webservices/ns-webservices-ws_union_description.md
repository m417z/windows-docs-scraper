# WS_UNION_DESCRIPTION structure

## Description

Information about the choices within a union type.
This is used with [WS_UNION_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type).

## Members

### `size`

The size in bytes of the structure.

### `alignment`

The alignment requirement of the structure. This must be a power
of two between 1 and 8.

### `fields`

An array of pointers to the descriptions of the fields of the union.

See the Remarks section for information about ordering of the fields
in this array.

### `fieldCount`

The number of fields in the fields array. Any part of the structure
that is not represented by a field will be left uninitialized.
Fields descriptions may reference the same offset of the structure
(for example if they are all part of a single union).

### `enumOffset`

The offset of the enumeration field which controls which choice is
selected within the union. The size of the field is assumed to be
the size of an enumeration (32-bit signed integer).

### `noneEnumValue`

This value corresponds to the enum value used when none of the
choices are currently set. This field is only used when the
field is optional ([WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) was specified).

### `valueIndices`

This optional array provides information which can improve
the performance of looking up fields of the union either by
element or by enum value. This array may **NULL**, in which case
an O(n) lookup is used, which may be sufficient for small
numbers of fields.

If non-**NULL**, the following must be true:

* The fields array is required to be sorted by element, in ascending order.
  When comparing an element the namespace should be compared first, then the local name.
  Each of the names should be compared by performing a byte-wide comparison of the utf-8 string.
  The field that uses [WS_ANY_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping), if present, should always
  be last in the fields array.
* The valueIndices array points to an array that has fieldCount items. The valueIndices
  array provides the indices of the items in the fields array as if they were sorted by
  value in ascending order.

## Remarks

This description assumes a structure which contains both the
selector value (an integer enumerated value) and a union which
contains a field which corresponds to each of the possible
choices, for example:

``` syntax
// Enumeration of choices of different values
enum Choice
{
    ChoiceA = 20,
    ChoiceB = 10,
    None = 0,
};

// Struct containing union of values, and enum "selector"
struct StructType
{
    Choice choice;
    union
    {
        int a;
        WS_STRING b;
    } value;
};
```

The following examples illustrates initializing a union description
for the previous example. This example fills out the nameIndices
field, but this field could be **NULL** instead.

``` syntax
WS_XML_STRING choiceAString = WS_XML_STRING_VALUE("choiceA");
WS_XML_STRING choiceANs = WS_XML_STRING_VALUE("http://examples.org/a");

WS_UNION_FIELD_DESCRIPTION fieldA = { };
fieldA.value = ChoiceA;
fieldA.field.localName = &choiceAString;
fieldA.field.ns = &choiceANs;
fieldA.field.type = WS_INT32_TYPE;
fieldA.field.offset = WsOffsetOf(StructType, value.a);

WS_XML_STRING choiceBString = WS_XML_STRING_VALUE("choiceB");
WS_XML_STRING choiceBNs = WS_XML_STRING_VALUE("http://examples.org/b");

WS_UNION_FIELD_DESCRIPTION fieldB = { };
fieldB.value = ChoiceB;
fieldB.field.localName = &choiceBString;
fieldB.field.ns = &choiceBNs;
fieldB.field.type = WS_STRING_TYPE;
fieldB.field.offset = WsOffsetOf(StructType, value.b);

// Sorted by ascending element name (first ns, then localName)
WS_UNION_FIELD_DESCRIPTION* fieldsArray[] =
{
    &fieldA, // "http://example.com/a", "choiceA"
    &fieldB, // "http://example.com/b", "choiceB"
};

// Sorted by ascending enum value
ULONG valueIndices[] =
{
    1, // ChoiceB (10)
    0, // ChoiceA (20)
};

WS_UNION_DESCRIPTION unionDescription;
unionDescription.size = sizeof(StructType);
unionDescription.alignment = __alignof(StructType);
unionDescription.fields = fieldsArray;
unionDescription.fieldCount = WsCountOf(fieldsArray);
unionDescription.enumOffset = WsOffsetOf(StructType, choice);
unionDescription.noneEnumValue = None;
unionDescription.valueIndices = valueIndices;

```

The above would allow either of the following elements to appear:

``` syntax
<choiceA xmlns="http://example.com/a">123</choiceA>
<choiceB xmlns="http://example.com/b">hello</choiceB>

```

The following is an example of setting values:

``` syntax
StructType structType;

// Set ChoiceA
structType.choice = ChoiceA;
structType.value.a = 123;

// Set ChoiceB
static const WS_STRING = WS_STRING_VALUE(L"hello");
structType.choice = ChoiceB;
structType.value.b = helloString;

// Set "none" choice
structType.choice = None;

```

The following is the grammar describing the order of the [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description) that make up a **WS_UNION_DESCRIPTION**. The order is defined based on the
mapping field of the **WS_FIELD_DESCRIPTION**.

``` syntax

Fields := ElementContentFields AnyElementField?
ElementContentFields := (ElementField | RepeatingElementField)*
ElementField := WS_ELEMENT_FIELD_MAPPING
RepeatingElementField := WS_REPEATING_ELEMENT_FIELD_MAPPING
AnyElementField := WS_ANY_ELEMENT_FIELD_MAPPING
```

The [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) and **WS_REPEATING_ELEMENT_FIELD_MAPPING** represent the element choices and their corresponding fields in the union.

The [WS_ANY_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) is the field used when none of the
other elements matched.

The following restrictions apply to the field descriptions:

* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) may only be used when
  a wrapper element name and namespace has been specified.
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) may not be used.