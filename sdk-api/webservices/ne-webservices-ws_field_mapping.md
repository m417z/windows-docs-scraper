## Description

Specifies how a field of a structure is represented in XML. This is used within a [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_field_description).

## Constants

### `WS_TYPE_ATTRIBUTE_FIELD_MAPPING:0`

The field corresponds to the XML type attribute (xsi:type). This can be used only with [WS_DESCRIPTION_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type).

```
struct Base
{
    WS_STRUCT_DESCRIPTION* type;

    // ... base fields ...
};

struct Derived : Base
{
    // ... derived fields ...
};

struct Struct
{
    Base* field;
};

Derived derived;
derived.type = &DerivedStructDescription;
Struct s;
s.field = &derived;

<Struct>
    <field xsi:type='Derived'>
        // ... base fields ...
        // ... derived fields ...
    </field>
</Struct>
```

This mapping does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value).

### `WS_ATTRIBUTE_FIELD_MAPPING:1`

The field corresponds to a single attribute.

The field's localName/ns are used as the XML attribute name and namespace.

Unless specified, the attribute must appear in the XML. If [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) is specified, then the attribute is not required to appear in the XML. If optional and not present, then the field is set to the [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value), or zero if the default value is not specified.

```
struct Struct
{
    int field;
};

Struct s;
s.field = 1;

<Struct field='1'/>
```

To discard the attribute, a [WS_VOID_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type) should be used. In this case, a field is not required in the structure. See **WS_VOID_TYPE** for more information.

### `WS_ELEMENT_FIELD_MAPPING:2`

The field corresponds to a single element.

The field's localName/ns are used as the XML element name and namespace.

Unless specified, the element must appear in the XML. If [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) is specified, then the element is not required to appear in the XML. If optional and not present, then the field is set to the [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value), or zero if the default value is not specified.

```
struct Struct
{
    int field;
};

Struct s;
s.field = 1;

<Struct>
    <field>1</field>
</Struct>
```

To discard the element, a [WS_VOID_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type) should be used. In this case, a field is not required in the structure. See **WS_VOID_TYPE** for more information.

### `WS_REPEATING_ELEMENT_FIELD_MAPPING:3`

The field corresponds to a repeating set of elements.

The field's localName/ns are used as the XML element name and namespace to use for the wrapper element (the element which is the parent of the repeating elements). If no wrapper element is desired, then both localName/ns should be **NULL**.

If a wrapper element has been specified, the wrapper element must appear in the XML if repeating element count is not 0. A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value) may not be specified for this field mapping.

The itemLocalName and itemNs are used as the XML element name and namespace for the repeating element.

```
struct Struct
{
    int* field;
    ULONG fieldCount;
};

int values[] = { 1, 2 };
Struct s;
s.field = values;
s.fieldCount = 2;

// with wrapper element specified
<Struct>
    <field>
        <item>1</item>
        <item>2</item>
    </field>
</Struct>

// with no wrapper element specified
<Struct>
    <item>1</item>
    <item>2</item>
</Struct>
```

The number of elements in the deserialized array can be constrained by specifying a non-**NULL**[WS_ITEM_RANGE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_item_range) structure that is part of the [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_field_description).

### `WS_TEXT_FIELD_MAPPING:4`

The field corresponds to the entire character content of the element. When this mapping is used, child elements are not allowed.

This mapping is commonly used in conjunction with [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_field_mapping) to define a structure which maps to an element containing some text and attributes (but no child elements).

```
struct Struct
{
    int field;
};

Struct s;
s.field = 1;

<Struct>1</Struct>
```

This mapping does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value).

### `WS_NO_FIELD_MAPPING:5`

The field is neither serialized nor deserialized.

The field is ignored when serializing, and is initialized to the default value when deserializing.

If the field maps to one of the existing types (for example [WS_INT32_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type)), then the type can be specified. If the type of the field is not one of the existing types, then **WS_VOID_TYPE** can be used to specify a field of an arbitrary type and size.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value) may be specified to provide the value to initialize the field to when deserializing the field. If a default value is not specified, then the field will be initialized to zero.

The field mapping can be used only with [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) value of 0.

```
struct Struct
{
    int field;
};

Struct s;
s.field = 1;

<Struct/>
```

### `WS_XML_ATTRIBUTE_FIELD_MAPPING:6`

The field corresponds to a reserved xml attribute (such as xml:lang).

The field's localName is used to identify the XML attribute name.

Unless [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) is specified, the attribute must appear in the XML. If **WS_FIELD_OPTIONAL** is specified, then the attribute is not required to appear in the XML. If optional and not present, then the field is set to the [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value), or zero if the default value is not specified.

```
struct Struct
{
    WS_STRING field;
};

Struct s;
s.field = ...; // 'us-en';

// Example of xml:lang
<Struct xml:lang='us-en'/>

s.field = ...; // 'true'

// Example of xml:space
<Struct xml:space='true'>
```

### `WS_ELEMENT_CHOICE_FIELD_MAPPING:7`

The field corresponds to a choice among a set of possible elements. Each element maps to one of the fields of a union. Each field of the union has a corresponding enum value, which is used to identify the current choice.

```
// Enumeration of choices of different values
enum Choice
{
    ChoiceA = 10,
    ChoiceB = 20,
    None = 0,
};

// Struct containing union of values, and enum 'selector'
struct Struct
{
    Choice choice;
    union
    {
        int a;          // valid when choice is ChoiceA
        WS_STRING b;    // valid when choice is ChoiceB
    } value;
};
```

This field mapping must be used with [WS_UNION_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type). The names and namespaces of the element choices are specified in the [WS_UNION_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_union_description). The field's localName and ns should be **NULL**.

Unless [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) is specified, one of the elements must appear in the XML. If **WS_FIELD_OPTIONAL** is specified, then none of the elements are required to appear in the XML. If optional and none of the elements are present, then the field's selector value is set to the none value of the enumeration (as specified in the noneEnumValue field of the [WS_UNION_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_union_description)). Due to the fact that the nonEnumValue is used as the default value, this mapping value does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value).

```
Struct s;
s.choice = ChoiceA;
s.value.a = 123;

<Struct>
    <choiceA>123</choiceA>
</Struct>

Struct S;
s.choice = ChoiceB;
s.value.b = ...; // 'hello'

<Struct>
    <choiceB>hello</choiceB>
</Struct>

Struct S;
s.choice = None;

<Struct>
</Struct>
```

The field corresponds to a choice among a set of possible elements. Each element maps to one of the fields of a union. Each field of the union has a corresponding enum value, which is used to identify the current choice.

```
// Enumeration of choices of different values
enum Choice
{
    ChoiceA = 10,
    ChoiceB = 20,
    None = 0,
};

// Struct containing union of values, and enum &quot;selector&quot;
struct Struct
{
    Choice choice;
    union
    {
        int a;          // valid when choice is ChoiceA
        WS_STRING b;    // valid when choice is ChoiceB
    } value;
};
```

This field mapping must be used with [WS_UNION_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type). The names and namespaces of the element choices are specified in the [WS_UNION_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_union_description). The field's localName and ns should be **NULL**.

Unless [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) is specified, one of the elements must appear in the XML. If **WS_FIELD_OPTIONAL** is specified, then none of the elements are required to appear in the XML. If optional and none of the elements are present, then the field's selector value is set to the none value of the enumeration (as specified in the noneEnumValue field of the [WS_UNION_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_union_description)). Due to the fact that the nonEnumValue is used as the default value, this mapping value does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value).

```
Struct s;
s.choice = ChoiceA;
s.value.a = 123;

<Struct>
    <choiceA>123</choiceA>
</Struct>

Struct S;
s.choice = ChoiceB;
s.value.b = ...; // &quot;hello&quot;

<Struct>
    <choiceB>hello</choiceB>
</Struct>

Struct S;
s.choice = None;

<Struct>
</Struct>
```

The selector value indicates which of the fields of the union are set. Other fields are left uninitialized when the value is deserialized. An application should always consult the selector value to verify that a field of the union is accessible.

### `WS_REPEATING_ELEMENT_CHOICE_FIELD_MAPPING:8`

The field corresponds to a repeating set of element choices.

Each item is represented by a union with selector value. This mapping must be used with [WS_UNION_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type).

The field's localName/ns are used as the XML element name and namespace to use for the wrapper element (the element which is the parent of the repeating elements). If no wrapper element is desired, then both localName/ns should be **NULL**.

If a wrapper element has been specified, the wrapper element must appear in the XML if repeating element count is not 0. A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value) may not be specified for this field mapping.

The itemLocalName and itemNs fields must be **NULL**. The XML element name and namespace are defined in the [WS_UNION_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_union_description).

```
struct Struct2
{
    Struct* field;      // see WS_UNION_DESCRIPTION for definition of Struct
    ULONG fieldCount;
};

StructType values[2];
values[0].choice = ChoiceA;
values[0].values.a = 123;
values[1].choice = ChoiceB;
values[1].values.b = ...; // hello

Struct2 s2;
s2.field = values;
s2.fieldCount = 2;

// with wrapper element specified
<Struct2>
    <field>
        <item>123</item>
        <item>hello</item>
    </field>
</Struct2>

// with no wrapper element specified
<Struct2>
    <item>123</item>
    <item>hello</item>
</Struct2>
```

The number of elements in the deserialized array can be constrained by specifying a non-**NULL**[WS_ITEM_RANGE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_item_range) structure that is part of the [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_field_description).

### `WS_ANY_ELEMENT_FIELD_MAPPING:9`

TBD

### `WS_REPEATING_ANY_ELEMENT_FIELD_MAPPING:10`

The field is used to discard or store a sequence of elements with any name and namespace.

To store the elements, a [WS_XML_BUFFER_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type) should be used. This corresponds to an array of [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer)s, as follows:

```
struct Struct
{
    // ... known fields ...
    WS_XML_BUFFER** fields;
    ULONG fieldCount;
    // ... known fields ...
};

Struct s;
s.fields = ...; // { '<unknown1/>', '<unknown2/>'; }
s.fieldCount = 2;

<Struct>
    ... known fields ...
    <unknown1/>
    <unknown2/>
    ... known fields ...
</Struct>
```

To discard the elements, a [WS_VOID_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type) should be used. In this case, a field is not required in the structure. See **WS_VOID_TYPE** for more information.

The number of elements allowed during deserialization can be constrained by specifying a non-**NULL**[WS_ITEM_RANGE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_item_range) structure that is part of the [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_field_description).

This mapping doesn't support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value).

### `WS_ANY_CONTENT_FIELD_MAPPING:11`

The field is used to discard or store any remaining content (any mixture of text or elements) that occurs before the end of an element.

To store the elements, a [WS_XML_BUFFER_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type) should be used, as follows:

```
struct Struct
{
    // ... known fields ...
    WS_XML_BUFFER* field;
};

Struct s;
s.field = ...; // 'text1<unknown1/>text2<unknown2/>'

<Struct>
    ... known fields ...
    text1
    <unknown1/>
    text2
    <unknown2/>
</Struct>
```

To discard the elements, a [WS_VOID_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type) should be used. In this case, a field is not required in the structure. See **WS_VOID_TYPE** for more information.

This mapping does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value).

### `WS_ANY_ATTRIBUTES_FIELD_MAPPING:12`

The field is used to discard or store any attributes which were not mapped using other [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_field_mapping) values.

If this field mapping is not specified, then unmapped attributes will cause an error when deserializing.

The name field of the [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_field_description) must be **NULL**.

The ns field of the [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_field_description) restricts the namespace of the attributes allowed as follows:

* If the ns field is **NULL**, then there is no restriction. The
  [WS_FIELD_OTHER_NAMESPACE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) field option must be not set in this case.
* If the ns field is non-**NULL**, and the field option
  [WS_FIELD_OTHER_NAMESPACE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) is not set for the field, then
  the attribute must have the same namespace as was specified in the ns field.
* If the ns field is non-**NULL**, and the field option
  [WS_FIELD_OTHER_NAMESPACE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) is set for the field, then the
  attribute must have a different namespace than was specified
  in the ns field.

To store the attributes, [WS_ANY_ATTRIBUTES_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type) should be used. This correspond to [WS_ANY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_any_attributes) as follows:

```
struct Struct
{
    // ... known attributes ...
    WS_ANY_ATTRIBUTES field;
    // ... other content ...
};

Struct s;
s.field = ...; // 'unknown'/'http://example.com'/'value'

<Struct
    ... known attributes ...
    xmlns:a='http://example.com' a:unknown='value'>

    ... other content ...
</Struct>
```

To discard the unmapped attributes, a [WS_VOID_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_type) should be used. In this case, a field is not required in the structure. See **WS_VOID_TYPE** for more information.

This mapping does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_default_value).

## Remarks

The **WS_FIELD_MAPPING** indicates how different parts of the XML content maps to the fields of a structure. For example, **WS_ELEMENT_FIELD_MAPPING** can be used to map the value of a child element, and **WS_ATTRIBUTE_FIELD_MAPPING** can be used to map an attribute. Any XML content that is read that is not explicitly mapped will cause **WS_E_INVALID_FORMAT** to be returned when the XML is deserialized (see [Windows Web Services return values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

The order of the [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_field_description) within a [WS_STRUCT_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_struct_description) is determined by the **WS_FIELD_MAPPING** value of the **WS_FIELD_DESCRIPTION**. See **WS_STRUCT_DESCRIPTION** for more information on the ordering.