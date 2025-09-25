# IDestinationStreamFactory::GetDestinationStream

## Description

Gets an empty stream that receives the new version of the file being copied.

## Parameters

### `ppstm` [out]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)****

The address of a pointer to the new stream.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The property handler author calls **IDestinationStreamFactory::GetDestinationStream** to get a new empty stream that the new version of the file will write to. The handler builds the destination stream manually, copying from the source stream as necessary.