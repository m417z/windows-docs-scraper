# CREDENTIAL_ATTRIBUTEA structure

## Description

The **CREDENTIAL_ATTRIBUTE** structure contains an application-defined attribute of the credential. An attribute is a keyword-value pair. It is up to the application to define the meaning of the attribute.

## Members

### `Keyword`

Name of the application-specific attribute. Names should be of the form \<CompanyName>_\<Name>.

This member cannot be longer than CRED_MAX_STRING_LENGTH (256) characters.

### `Flags`

Identifies characteristics of the credential attribute. This member is reserved and should be originally initialized as zero and not otherwise altered to permit future enhancement.

### `ValueSize`

Length of **Value** in bytes. This member cannot be larger than CRED_MAX_VALUE_SIZE (256).

### `Value`

Data associated with the attribute. By convention, if **Value** is a text string, then **Value** should not include the trailing zero character and should be in UNICODE.

Credentials are expected to be portable. The application should take care to ensure that the data in value is portable. It is the responsibility of the application to define the byte-endian and alignment of the data in **Value**.

## Remarks

> [!NOTE]
> The wincred.h header defines CREDENTIAL_ATTRIBUTE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).