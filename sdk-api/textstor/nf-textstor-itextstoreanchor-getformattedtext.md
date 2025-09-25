# ITextStoreAnchor::GetFormattedText

## Description

The **ITextStoreAnchor::GetFormattedText** method returns formatted text information from a text stream.

## Parameters

### `paStart` [in]

Anchor position at which to start retrieval of formatted text.

### `paEnd` [in]

Anchor position at which to end retrieval of formatted text.

### `ppDataObject` [out]

Pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object that contains the formatted text.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method was unable to obtain a valid interface pointer to the start and/or end anchors. |
| **E_NOTIMPL** | An application can return this value if the method is not implemented. |
| **TS_E_NOLOCK** | The caller does not have a read/write lock on the document. |

## Remarks

Text, embedded objects, and any formatting are wrapped into a single **IDataObject** object. In this way, private application-specific formatting associated with text can be preserved by a client.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)