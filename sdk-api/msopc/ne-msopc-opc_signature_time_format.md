# OPC_SIGNATURE_TIME_FORMAT enumeration

## Description

Describes how to interpret the *signingTime* parameter, which is a record of when a signature was created, of the [IOpcDigitalSignature::GetSigningTime](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignature-getsigningtime) method.

## Constants

### `OPC_SIGNATURE_TIME_FORMAT_MILLISECONDS:0`

The format is the complete date with hours, minutes, and seconds expressed as a decimal fraction.

Syntax: *YYYY*-*MM*-*DD*T*hh*:*mm*:*ss*.*s**TZD*

A value of "2010-03-09T18:45:32.3-08:00" would represent 6:45:32.3 P.M. on March 9, 2010 Pacific Time.

### `OPC_SIGNATURE_TIME_FORMAT_SECONDS:1`

The format is the complete date with hours, minutes, and seconds.

Syntax: *YYYY*-*MM*-*DD*T*hh*:*mm*:*ss**TZD*

A value of "2010-03-09T18:45:32-08:00" would represent 6:45:32 P.M. on March 9, 2010 Pacific Time.

### `OPC_SIGNATURE_TIME_FORMAT_MINUTES:2`

The format is the complete date with hours and minutes.

Syntax: *YYYY*-*MM*-*DD*T*hh*:*mm**TZD*

A value of "2010-03-09T18:45-08:00" would represent 6:45 P.M. on March 9, 2010 Pacific Time.

### `OPC_SIGNATURE_TIME_FORMAT_DAYS:3`

The format is the complete date.

Syntax: *YYYY*-*MM*-*DD*

A value of "2010-03-09" would represent March 9, 2010.

### `OPC_SIGNATURE_TIME_FORMAT_MONTHS:4`

The format is the year and month.

Syntax: *YYYY*-*MM*

A value of "2010-03" would represent March, 2010.

### `OPC_SIGNATURE_TIME_FORMAT_YEARS:5`

The format is the year.

Syntax: *YYYY*

A value of "2010" would represent 2010.

## Remarks

The following table provides descriptions of placeholder values.

| Placeholder | Description | Example |
| --- | --- | --- |
| *YYYY* | Four-digit year. | 2010 |
| *MM* | Two-digit month with a leading zero. Possible values: 01–12. | 03 |
| *DD* | Two-digit day of month with a leading zero. Possible values: 01–31. | 09 |
| *hh* | Two-digit hour, 24-hour time with a leading zero. Possible values: 00–23. | 18 |
| *mm* | Two-digit minute with a leading zero. Possible values: 00–59. | 45 |
| *ss* | Two-digit second with a leading zero. Possible values: 00–59. | 32 |
| *s* | One digit representing the decimal fraction of a second. | 3 |
| *TZD* | Time zone designator with a leading zero. Possible values: Z, +*hh*:*mm*, -*hh*:*mm*. | -08:00 |

## See also

[ECMA-376 OpenXML standard](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcDigitalSignature::GetTimeFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcdigitalsignature-gettimeformat)

[IOpcSigningOptions::GetTimeFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-gettimeformat)

[IOpcSigningOptions::SetTimeFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcsigningoptions-settimeformat)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-enumerations)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**

[W3C Recommendation, XML Signature and Syntax Processing](https://www.w3.org/TR/xmldsig-core/)