# WS_XML_DICTIONARY structure

## Description

Represents a set of unique strings. This information is used by the binary
encoding to write a more compact xml document.

## Members

### `guid`

A guid that uniquely identifies the set of strings represented by the dictionary.
The guid is never transmitted or persisted, and needs to only be unique for the lifetime of the process.

### `strings`

The set of unique strings that comprise the dictionary.

### `stringCount`

Specifies the number of strings in the dictionary.

### `isConst`

Indicates if the dictionary and its contents are declared const and that they will be kept valid for the
entire lifetime of any object with which strings in the dictionary are used.

If this is **TRUE**, then the strings can be manipulated more efficiently.

## Remarks

All strings and values within a dictionary must be unique. Dictionaries are
always assumed to be well-formed, so it is up to the creator of the dictionary
to ensure that this is the case.

A dictionary might be declared as:

``` syntax
struct PurchaseOrderDictionary
{
    WS_XML_DICTIONARY dictionary;
    WS_XML_STRING quantity;
    WS_XML_STRING productName;
    WS_XML_STRING purchaseOrder;
    WS_XML_STRING purchaseOrderNamespace;
};

static PurchaseOrderDictionary purchaseOrderDictionary =
{
    {
        { /* A unique GUID generated from uuidgen */ },
        &purchaseOrderDictionary.quantity,
        4,
        TRUE
    },
    WS_XML_STRING_DICTIONARY_VALUE("Quantity",           &purchaseOrderDictionary.dictionary, 0),
    WS_XML_STRING_DICTIONARY_VALUE("ProductName",        &purchaseOrderDictionary.dictionary, 1),
    WS_XML_STRING_DICTIONARY_VALUE("PurchaseOrder",      &purchaseOrderDictionary.dictionary, 2),
    WS_XML_STRING_DICTIONARY_VALUE("http://example.com", &purchaseOrderDictionary.dictionary, 3),
};

```

Strings from the dictionary might be used as:

``` syntax
WsWriteStartElement(xmlWriter, NULL, &purchaseOrderDictionary.purchaseOrder, &purchaseOrderDictionary.purchaseOrderNamespace, error);
```