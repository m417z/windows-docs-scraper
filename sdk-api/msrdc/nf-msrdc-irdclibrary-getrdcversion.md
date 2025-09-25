# IRdcLibrary::GetRDCVersion

## Description

The **GetRDCVersion** method retrieves
the version of the installed RDC runtime and the oldest version of the RDC interfaces supported by the installed
runtime.

## Parameters

### `currentVersion` [out]

Address of a **ULONG** that will receive the installed version of RDC. This
corresponds to the **MSRDC_VERSION** value.

### `minimumCompatibleAppVersion` [out]

Address of a **ULONG** that will receive the oldest version of RDC supported by
the installed version of RDC. This corresponds to the
**MSRDC_MINIMUM_COMPATIBLE_APP_VERSION** value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRdcGeneratorParameters::GetParametersVersion](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcgeneratorparameters-getparametersversion)

[IRdcLibrary](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdclibrary)