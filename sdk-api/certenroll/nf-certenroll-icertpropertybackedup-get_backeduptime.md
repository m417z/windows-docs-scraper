# ICertPropertyBackedUp::get_BackedUpTime

## Description

The **BackedUpTime** property retrieves the date and time at which the certificate was backed up.

This property is read-only.

## Parameters

## Remarks

Call the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertybackedup-initialize) method or the [InitializeFromCurrentTime](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertybackedup-initializefromcurrenttime) method to set the **BackedUpTime** value.

The date is stored as an 8-byte real value, representing a date between January 1, 1900 and December 31, 9999, inclusive. The value 2.0 represents January 1, 1900; 3.0 represents January 2, 1900. Adding 1 to the value increments the date by a day. The fractional part of the value represents the time of day. Therefore, 2.5 represents 12:00 on January 1, 1900; 3.25 represents 06:00 on January 2, 1900.

For dates between 1950 and 2049 inclusive, the date and time is encoded UTC-time in the form YYMMDDHHMMSS. For dates before 1950 or after 2049, encoded generalized time is used. Encoded generalized time is in the form YYYYMMDDHHMMSSMMM, using a four digit year, and is precise to milliseconds.

## See also

[ICertProperty](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertproperty)

[ICertPropertyBackedUp](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertybackedup)