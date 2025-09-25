# IRdcSimilarityGenerator::Results

## Description

Retrieves the similarity data that was generated for a file by the signature generator.

This method cannot be called until signature generation is completed. For more information, see the *endOfOutput* parameter of the [IRdcGenerator::Process](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcgenerator-process) method.

## Parameters

### `similarityData` [out]

A pointer to a [SimilarityData](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-similaritydata) structure that will receive the similarity data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRdcSimilarityGenerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcsimilaritygenerator)