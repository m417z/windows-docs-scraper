# IRdcSimilarityGenerator::EnableSimilarity

## Description

Enables the signature generator to generate similarity data.

The **EnableSimilarity** method must be called before the [IRdcGenerator::Process](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcgenerator-process) method is called to begin generating signatures. Otherwise, this method will return an error.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRdcSimilarityGenerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcsimilaritygenerator)