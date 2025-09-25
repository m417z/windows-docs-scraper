# DsUnquoteRdnValueA function

## Description

The **DsUnquoteRdnValue** function is a client call that converts a quoted RDN value back to an unquoted RDN value. Because the RDN was originally put into quotes because it contained characters that could be misinterpreted when it was embedded within a distinguished name (DN), the unquoted RDN value should not be submitted as part of a DN to the directory service using various APIs such as LDAP.

## Parameters

### `cQuotedRdnValueLength` [in]

The number of characters in the *psQuotedRdnValue* string.

### `psQuotedRdnValue` [in]

The RDN value that may be quoted and escaped.

### `pcUnquotedRdnValueLength` [in, out]

The input value for this argument is the maximum length, in characters, of *psQuotedRdnValue*.

The output value for this argument includes the following flags.

#### ERROR_SUCCESS

This is returned if the number of characters match the string used in *psQuotedRdnValue*.

#### ERROR_BUFFER_OVERFLOW

This is returned if the number of characters do not match the string used in *psQuotedRdnValue*.

### `psUnquotedRdnValue` [out]

The converted, unquoted RDN value.

## Return value

The following list contains the possible values that are returned for the **DsUnquoteRdnValue** function.

## Remarks

When *psQuotedRdnValue* is quoted:

* The leading and trailing quotes are removed.
* White space before the first quote is discarded.
* White space trailing the last quote is discarded.
* Escapes are removed and the character following the escape is kept.

The following actions are taken when *psQuotedRdnValue* is unquoted:

* The leading white space is discarded.
* The trailing white space is kept.
* Escaped non-special characters return an error.
* Unescaped special characters return an error.
* RDN values beginning with # (ignoring leading white space) are handled as a BER value that has previously been converted to a string, and converted accordingly.
* Escaped hex digits (\89) are converted into a binary byte (0x89).
* Escapes are removed from escaped special characters.

The following actions are always taken:

* Escaped special characters are unescaped.
* The input and output RDN values are not null-terminated values.

> [!NOTE]
> The dsparse.h header defines DsUnquoteRdnValue as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsQuoteRdnValue](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsquoterdnvaluea)