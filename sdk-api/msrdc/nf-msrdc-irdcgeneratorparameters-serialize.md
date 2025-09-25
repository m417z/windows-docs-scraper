# IRdcGeneratorParameters::Serialize

## Description

The
**Serialize** method serializes the
parameter data into a block of memory. This allows the parameters to be stored or transmitted.

## Parameters

### `size` [in]

The size of the buffer pointed to by the *parametersBlob* parameter.

### `parametersBlob` [out]

The address of a buffer to receive the serialized parameter data.

### `bytesWritten` [out]

Address of a **ULONG** that on successful completion is filled with the size, in
bytes, of the serialized parameter data written to the buffer pointed to by the
*parametersBlob* parameter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GetSerializeSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcgeneratorparameters-getserializesize)

[IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters)