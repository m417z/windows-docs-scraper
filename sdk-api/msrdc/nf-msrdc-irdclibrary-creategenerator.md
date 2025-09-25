# IRdcLibrary::CreateGenerator

## Description

The **CreateGenerator** method
creates a signature generator that will generate the specified levels of signatures.

## Parameters

### `depth` [in]

The number of levels of signatures to generate. The valid range is from
**MSRDC_MINIMUM_DEPTH** to **MSRDC_MAXIMUM_DEPTH**.

### `iGeneratorParametersArray` [in]

Pointer to an array of initialized
[IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters) interface pointers. Each
**IRdcGeneratorParameters** interface pointer would
have been initialized by
[IRdcLibrary::CreateGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdclibrary-creategeneratorparameters) or
[IRdcGenerator::GetGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcgenerator-getgeneratorparameters).

### `iGenerator` [out]

Pointer to a location that will receive the returned
[IRdcGenerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgenerator) interface pointer. Callers must release the
interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CreateGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdclibrary-creategeneratorparameters)

[IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters)

[IRdcLibrary](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdclibrary)

[OpenGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdclibrary-opengeneratorparameters)