# IDWriteTextAnalyzer1::GetScriptProperties

## Description

Retrieves the properties for a given script.

## Parameters

### `scriptAnalysis`

Type: **[DWRITE_SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_script_analysis)**

The script for a run of text returned
from [IDWriteTextAnalyzer::AnalyzeScript](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextanalyzer-analyzescript).

### `scriptProperties` [out]

Type: **[DWRITE_SCRIPT_PROPERTIES](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_script_properties)***

A pointer to a [DWRITE_SCRIPT_PROPERTIES](https://learn.microsoft.com/windows/win32/api/dwrite_1/ns-dwrite_1-dwrite_script_properties) structure that describes info for the script.

## Return value

Type: **HRESULT**

Returns properties for the given script. If the script is invalid,
it returns generic properties for the unknown script and E_INVALIDARG.

## See also

[IDWriteTextAnalyzer1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalyzer1)