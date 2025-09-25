# IDWriteTextAnalyzer1::GetBaseline

## Description

Retrieves the given baseline from the font.

## Parameters

### `fontFace`

Type: **[IDWriteFontFace](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritefontface1)***

The font face to read.

### `baseline`

Type: **[DWRITE_BASELINE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_baseline)**

A [DWRITE_BASELINE](https://learn.microsoft.com/windows/win32/api/dwrite_1/ne-dwrite_1-dwrite_baseline)-typed value that specifies the baseline of interest.

### `isVertical`

Type: **BOOL**

Whether the baseline is vertical or horizontal.

### `isSimulationAllowed`

Type: **BOOL**

Simulate the baseline if it is missing in the font.

### `scriptAnalysis`

Type: **[DWRITE_SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_script_analysis)**

Script analysis result from AnalyzeScript.

**Note** You can pass an empty script analysis structure, like this `DWRITE_SCRIPT_ANALYSIS scriptAnalysis = {};`, and this method will return the default baseline.

### `localeName` [in, optional]

Type: **const WCHAR***

The language of the run.

### `baselineCoordinate` [out]

Type: **INT32***

The baseline coordinate value in design units.

### `exists` [out]

Type: **BOOL***

Whether the returned baseline exists in the font.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the baseline does not exist in the font, it is not considered an
error, but the function will return exists = false. You may then use
heuristics to calculate the missing base, or, if the flag
simulationAllowed is true, the function will compute a reasonable
approximation for you.

## See also

[IDWriteTextAnalyzer1](https://learn.microsoft.com/windows/win32/api/dwrite_1/nn-dwrite_1-idwritetextanalyzer1)