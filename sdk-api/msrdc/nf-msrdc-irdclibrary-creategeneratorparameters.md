# IRdcLibrary::CreateGeneratorParameters

## Description

The
**CreateGeneratorParameters** method
returns an [IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters)
interface pointer initialized with the parameters necessary for a signature generator.

## Parameters

### `parametersType` [in]

Specifies the type of signature generator for the created parameters, enumerated by the
[GeneratorParametersType](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-generatorparameterstype) enumeration. The initial
release of RDC only supports one type, **RDCGENTYPE_FilterMax**.

### `level` [in]

The recursion level for this parameter block. A parameter block is needed for each level of generated
signatures. The valid range is from **MSRDC_MINIMUM_DEPTH** to
**MSRDC_MAXIMUM_DEPTH**.

### `iGeneratorParameters` [out]

Pointer to a location that will receive an
[IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters) interface pointer. On a
successful return the interface will be initialized on return. Callers must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GeneratorParametersType](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-generatorparameterstype)

[IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters)

[IRdcLibrary](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdclibrary)