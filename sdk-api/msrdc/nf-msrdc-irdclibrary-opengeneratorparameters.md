# IRdcLibrary::OpenGeneratorParameters

## Description

The **OpenGeneratorParameters** method
opens an existing serialized parameter block and returns an
[IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters) interface pointer initialized
with the data.

## Parameters

### `size` [in]

The size, in bytes, of the serialized parameter block.

### `parametersBlob` [in]

Pointer to a serialized parameter block.

### `iGeneratorParameters` [out]

Pointer to a location that will receive the returned
[IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters) interface pointer. Callers
must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To create a serialized parameter block, use the [IRdcGeneratorParameters::Serialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcgeneratorparameters-serialize) method.

## See also

[IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters)

[IRdcGeneratorParameters::Serialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcgeneratorparameters-serialize)

[IRdcLibrary](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdclibrary)