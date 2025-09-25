# IRdcGenerator::GetGeneratorParameters

## Description

The **GetGeneratorParameters** method
returns a copy of the parameters used to create the generator. The generator parameters are
fixed when the generator is created.

## Parameters

### `level` [in]

The generator level for the parameters to be returned. The range is
**MSRDC_MINIMUM_DEPTH** to **MSRDC_MAXIMUM_DEPTH**.

### `iGeneratorParameters` [out]

Address of a pointer that on successful return will contain the
[IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters) interface pointer for the
parameters for the generator level specified in the *level* parameter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRdcGenerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgenerator)

[IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters)