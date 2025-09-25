# DsQuoteRdnValueW function

## Description

The **DsQuoteRdnValue** function converts an RDN into a quoted RDN value, if the RDN value contains characters that require quotes. The quoted RDN can then be submitted as part of a distinguished name (DN) to the directory service using various APIs such as LDAP. An example of an RDN that would require quotes would be one that has a comma-separated value, such as an RDN for a name that uses the format "last,first".

## Parameters

### `cUnquotedRdnValueLength` [in]

The number of characters in the *psUnquotedRdnValue* string.

### `psUnquotedRdnValue` [in]

The string that specifies the unquoted RDN value.

### `pcQuotedRdnValueLength` [in, out]

The maximum number of characters in the *psQuotedRdnValue* string.

The following flags are the output for this parameter.

#### ERROR_SUCCESS

Indicates that the correct number of characters were found in *psQuotedRdnValue*.

#### ERROR_BUFFER_OVERFLOW

Indicates that the number of characters in the string do not match *psQuotedRdnValue*.

### `psQuotedRdnValue` [out]

The string that receives the converted, and perhaps quoted, RDN value.

##### - pcQuotedRdnValueLength.ERROR_BUFFER_OVERFLOW

Indicates that the number of characters in the string do not match *psQuotedRdnValue*.

##### - pcQuotedRdnValueLength.ERROR_SUCCESS

Indicates that the correct number of characters were found in *psQuotedRdnValue*.

## Return value

The following list contains the possible values returned for the **DsQuoteRdnValue** function.

## Remarks

Quotes are not added to the RDN if none are required. In this case, the output RDN value is the same as the input RDN value.

When quoting is required, the RDN is quoted in accordance with the specification "Lightweight Directory Access Protocol (v3): UTF-8 String Representation of Distinguished Names," RFC 2253.

The input and output RDN values are not **NULL**-terminated strings.

To revert changes made by this call, call the [DsUnquoteRdnValue](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsunquoterdnvaluea) function.

> [!NOTE]
> The dsparse.h header defines DsQuoteRdnValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsUnquoteRdnValue](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsunquoterdnvaluea)