# WMIQ_ANALYSIS_TYPE enumeration

## Description

Contains constants used to specify the type of analysis to perform by using the [GetAnalysis](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbemquery-getanalysis) method.

## Constants

### `WMIQ_ANALYSIS_RPN_SEQUENCE:0x1`

Used if the query has a SELECT clause. When this type of analysis is used, *pAnalysis* points to an [SWbemRpnEncodedQuery](https://learn.microsoft.com/windows/win32/api/wmiutils/ns-wmiutils-swbemrpnencodedquery) structure.

### `WMIQ_ANALYSIS_ASSOC_QUERY:0x2`

Used to return information about association type queries. When this type of analysis is used, *pAnalysis* points to an [SWbemAssocQueryInf](https://learn.microsoft.com/windows/win32/api/wmiutils/ns-wmiutils-swbemassocqueryinf) structure.

### `WMIQ_ANALYSIS_PROP_ANALYSIS_MATRIX:0x3`

Unused. Reserved for future use.

### `WMIQ_ANALYSIS_QUERY_TEXT:0x4`

Used to return a text string that has the original query text. If this type of analysis is used, *pAnalysis* points to a text string that contains the original query text.

You can use this parameter if a parser object is passed to another method.

### `WMIQ_ANALYSIS_RESERVED:0x8000000`

Unused. Reserved for future use.