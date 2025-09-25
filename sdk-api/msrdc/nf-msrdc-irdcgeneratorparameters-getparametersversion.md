# IRdcGeneratorParameters::GetParametersVersion

## Description

The **GetParametersVersion**
method returns information about the version of RDC used to serialize the parameters.

## Parameters

### `currentVersion` [out]

Address of a **ULONG** that will receive the version of RDC used to serialize the
parameters for this object. This corresponds to the **MSRDC_VERSION** constant.

### `minimumCompatibleAppVersion` [out]

Address of a **ULONG** that will receive the version of RDC that is compatible
with the serialized parameters. This corresponds to the
**MSRDC_MINIMUM_COMPATIBLE_APP_VERSION** constant.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRdcGeneratorParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorparameters)

[IRdcLibrary::GetRDCVersion](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdclibrary-getrdcversion)