# ITextStoreACP::GetFormattedText

## Description

The **ITextStoreACP::GetFormattedText** method returns formatted text data about a specified text string. The caller must have a read/write lock on the document before calling this method.

## Parameters

### `acpStart` [in]

Specifies the starting character position of the text to get in the document.

### `acpEnd` [in]

Specifies the ending character position of the text to get in the document. This parameter is ignored if the value is 1.

### `ppDataObject` [out]

Receives the pointer to the **IDataObject** object that contains the formatted text.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_NOLOCK** | The caller does not have a read/write lock on the document. |