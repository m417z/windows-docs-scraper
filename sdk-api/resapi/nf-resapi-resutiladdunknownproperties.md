# ResUtilAddUnknownProperties function

## Description

Retrieves a set of [unknown properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/unknown-properties) from the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) and appends them to the end of a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists).

## Parameters

### `hkeyClusterKey` [in]

Pointer to the cluster database key that identifies the location for the properties to read.

### `pPropertyTable` [in]

Pointer to a [property table](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-tables) describing the common and private properties of an object. Any properties found in the cluster database that are not in this property table are added to the property list.

### `pOutPropertyList` [in, out]

Pointer to a buffer in which to receive the returned properties. On input, the buffer can contain an existing property list, or it can be empty. On output, the retrieved properties will be appended to the end of the existing list, or, if the buffer is empty, will return as a new property list.

### `pcbOutPropertyListSize` [in]

Total byte size of the buffer pointed to by *pOutPropertyList*. The size of the buffer must be large enough to contain the existing property list and the property list to be returned.

### `pcbBytesReturned` [in, out]

On input, pointer to the byte size of the property list contained by the pOutPropertyList buffer. On output, pointer to the total number of bytes in the property list pointed to by *pOutPropertyList*.

### `pcbRequired` [in, out]

On output, points to the total number of bytes required to hold the returned property list. If the *pOutPropertyList* buffer was too small, it can be reallocated to the required size.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | There was an error allocating memory. |

## Remarks

The relationships between the input and output parameters of **ResUtilAddUnknownProperties** are illustrated in the following diagram:

:::image type="content" source="./images/resutil.png" border="false" alt-text="Diagram showing input and output parameters listed separately in two buffers. Two unknown properties have been added to the output parameter list.":::

The **ResUtilAddUnknownProperties** utility function enumerates the properties stored in the cluster database (under *hkeyClusterKey*) and looks for corresponding properties in the property table (*pPropertyTable*). Each property that is listed in the cluster database but not listed in the property table is added to the property list (*pOutPropertyList*).

## See also

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)

[ResUtilSetUnknownProperties](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetunknownproperties)